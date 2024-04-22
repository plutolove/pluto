#pragma once
#include <type_traits>

#include "boost/type_index.hpp"
#include "common/log.h"

namespace pluto {

template <typename... Ts>
struct TypeList {
  using type = TypeList<Ts...>;
  static constexpr auto size = sizeof...(Ts);

  template <typename... Args>
  using append = TypeList<Ts..., Args...>;

  template <template <typename...> class To>
  using exportTo = To<Ts...>;
};

template <typename... Ts>
void print(TypeList<Ts...>) {
  (INFO("{}", boost::typeindex::type_id<Ts>().pretty_name()), ...);
  INFO("----------------------------------");
}

template <typename T, template <typename> class OP>
struct Map;

template <typename T, template <typename> class OP>
using Map_t = Map<T, OP>::type;

template <typename... Ts, template <typename> class OP>
struct Map<TypeList<Ts...>, OP> {
  using type = TypeList<typename OP<Ts>::type...>;
};

template <typename T, template <typename> class P, typename Out = TypeList<>>
struct Filter {
  using type = Out;
};

template <typename T, template <typename> class P>
using Filter_t = Filter<T, P>::type;

template <typename T, typename... Ts, template <typename> class P, typename Out>
struct Filter<TypeList<T, Ts...>, P, Out>
    : std::conditional_t<
          P<T>::value,
          Filter<TypeList<Ts...>, P, typename Out::template append<T>>,
          Filter<TypeList<Ts...>, P, Out>> {};

template <typename T, typename Acc, template <typename, typename> class OP>
struct Fold {
  using type = Acc;
};

template <typename T, typename Acc, template <typename, typename> class OP>
using Fold_t = Fold<T, Acc, OP>::type;

template <typename T, typename... Ts, typename Acc,
          template <typename, typename> class OP>
struct Fold<TypeList<T, Ts...>, Acc, OP>
    : Fold<TypeList<Ts...>, typename OP<Acc, T>::type, OP> {};

template <typename Ts, typename E>
struct TypeIn {
  template <typename Acc, typename T>
  struct In : std::conditional_t<Acc::value, Acc, std::is_same<E, T>> {};

  using type = Fold_t<Ts, std::false_type, In>;
  static constexpr auto value = type::value;
};

template <typename Ts, typename E>
constexpr auto TypeIn_v = TypeIn<Ts, E>::value;

template <typename L, typename R>
struct Concat {
  template <typename Acc, typename E>
  struct Append : Acc::template append<E> {};

  using type = Fold_t<R, L, Append>;
};

template <typename L, typename R>
using Concat_t = Concat<L, R>::type;

template <typename T>
struct Unique {
  template <typename Acc, typename E>
  struct Append : std::conditional_t<TypeIn_v<Acc, E>, Acc,
                                     typename Acc::template append<E>> {};
  using type = Fold_t<T, TypeList<>, Append>;
};

template <typename T>
using Unique_t = Unique<T>::type;

template <typename T, template <typename, typename> class Cmp>
struct Sort {
  using type = TypeList<>;
};

template <typename T, template <typename, typename> class Cmp>
using Sort_t = Sort<T, Cmp>::type;

template <typename T, typename... Ts, template <typename, typename> class Cmp>
struct Sort<TypeList<T, Ts...>, Cmp> {
  template <typename E>
  struct lcmp {
    static constexpr auto value = Cmp<E, T>::value;
  };

  template <typename E>
  struct rcmp {
    static constexpr auto value = !Cmp<E, T>::value;
  };

  using Left = Sort<Filter_t<TypeList<Ts...>, lcmp>, Cmp>::type;
  using Right = Sort<Filter_t<TypeList<Ts...>, rcmp>, Cmp>::type;

  using type = Concat_t<typename Left::template append<T>, Right>;
};

}  // namespace pluto