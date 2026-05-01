cmake_minimum_required(VERSION 3.20)

project(ALVINAGORTA_ANGEL_PC2 LANGUAGES CXX)
include(CTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(pc2_core src/LRUCache.cpp)
target_include_directories(pc2_core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_compile_features(pc2_core PUBLIC cxx_std_17)

function(add_pc2_target target_name source_file)
  add_executable(${target_name} "${source_file}")
  target_link_libraries(${target_name} PRIVATE pc2_core)
endfunction()

add_pc2_target(pc2_demo_lru "demos/demo_lru.cpp")
add_pc2_target(pc2_demo_lru2 "demos/demo_lru2.cpp")
add_pc2_target(pc2_demo_lru3 "demos/demo_lru3.cpp")
add_pc2_target(pc2_demo_lru4 "demos/demo_lru4.cpp")
add_pc2_target(pc2_benchmark "benchmark/benchmark.cpp")
add_pc2_target(pc2_test "tests/test_lru.cpp")

add_test(NAME pc2_test COMMAND pc2_test)