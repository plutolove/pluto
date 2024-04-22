add_rules("mode.debug") 

set_languages("c++20")
set_optimize("fastest")

add_rules("plugin.compile_commands.autoupdate", { outputdir = "build" })

add_repositories("local-repo https://github.com/plutolove/xmake-repo.git")

add_requires("libllvm 15.x", { configs = { shared = true } })

add_requires("fmt 10.0.0")
add_requires("abseil 20220623.0")
add_requires("spdlog v1.11.0")
add_requires("antlr4 v4.12.0")
add_requires("boost 1.84.0")

rule("dep_gen")
  before_build(function(target)
	  os.vrun(
		  "java -jar ./tools/antlr-4.12.0-complete.jar -visitor -no-listener -Dlanguage=Cpp -package pluto ./src/parser/Pluto.g4 -o ./"
	  )
  os.vrun("mlir-tblgen  --gen-dialect-decls ./src/ir/Op.td -o ./src/ir/Dialect.h.inc -I"..os.getenv("LLVM_ROOT").."/include/")
	os.vrun("mlir-tblgen  --gen-dialect-defs ./src/ir/Op.td -o ./src/ir/Dialect.cpp.inc -I"..os.getenv("LLVM_ROOT").."/include/")

	os.vrun("mlir-tblgen  --gen-op-decls ./src/ir/Op.td -o ./src/ir/Op.h.inc -I"..os.getenv("LLVM_ROOT").."/include/")
	os.vrun("mlir-tblgen  --gen-op-defs ./src/ir/Op.td -o ./src/ir/Op.cpp.inc -I"..os.getenv("LLVM_ROOT").."/include/")
end)

target("compiler")
  set_kind("static")
  add_rules("dep_gen")
  add_includedirs("./src")
  add_files("src/*/*/*.cpp")
  add_files("src/*/*.cpp")
  add_files("src/*/*.cpp")
  add_packages("antlr4", "libllvm", "fmt", "abseil", "spdlog", "boost")

target("main")
  set_kind("binary")
  add_includedirs("./src")
  add_files("src/main.cpp")
  add_packages("antlr4", "libllvm", "fmt", "abseil", "spdlog", "boost")
