#pragma once
#include "common/typelist.h"

namespace pluto {

template <typename F, typename T>
struct Edge {
  using From = F;
  using To = T;
};

template <typename T, typename Out = TypeList<>>
struct Chain {
  using type = Out;
};

template <typename F, typename Out>
struct Chain<auto (*)(F)->void, Out> {
  using From = F;
  using type = Out;
};

template <typename F, typename T, typename Out>
struct Chain<auto (*)(F)->T, Out> {
  using From = F;
  using To = Chain<T>::From;

  using type = Chain<T, typename Out::template append<Edge<From, To>>>::type;
};

template <typename... Ts>
struct Graph {
  using type =
      Fold_t<TypeList<typename Chain<Ts>::type...>, TypeList<>, Concat>;
};

template <typename Node = void>
struct EdgeTrait {
  template <typename Edge>
  struct IsFrom {
    static constexpr auto value = std::is_same_v<Node, typename Edge::From>;
  };

  template <typename Edge>
  struct IsTo {
    static constexpr auto value = std::is_same_v<Node, typename Edge::To>;
  };

  template <typename Edge>
  struct GetFrom {
    using type = typename Edge::From;
  };

  template <typename Edge>
  struct GetTo {
    using type = typename Edge::To;
  };
};

template <typename Edges, typename From, typename Target,
          typename Path = TypeList<>, typename = void>
struct FindShortestPath;

// template <typename Edges, typename From, typename Target>
// using FindShortestPath_t = FindShortestPath<Edges, From, Target>::type;

template <typename Edges, typename Target, typename Path>
struct FindShortestPath<Edges, Target, Target, Path>
    : Path::template append<Target> {};

template <typename Edges, typename From, typename Target, typename Path>
struct FindShortestPath<Edges, From, Target, Path,
                        std::enable_if_t<TypeIn_v<Path, From>>> : TypeList<> {};

template <typename Edges, typename From, typename Target, typename Path>
struct FindShortestPath<
    Edges, From, Target, Path,
    std::enable_if_t<!TypeIn_v<Path, From> && !std::is_same_v<From, Target>>> {
  using CEdges =
      Filter_t<Edges, EdgeTrait<From>::template IsFrom>;  // 以from为起点的边

  using CNodes = Map_t<CEdges, EdgeTrait<>::GetTo>;  // 获取所有to节点

  template <typename NEXT_NODE>
  struct FPath : FindShortestPath<Edges, NEXT_NODE, Target,
                                  typename Path::template append<From>> {};

  using AllPath = Map_t<CNodes, FPath>;

  template <typename ACC, typename CP>
  struct MiniPath
      : std::conditional_t<(ACC::size == 0 ||
                            ((ACC::size > CP::size) && CP::size > 0)),
                           CP, ACC> {};
  using type = Fold_t<AllPath, TypeList<>, MiniPath>;
};

}  // namespace pluto