cmake_minimum_required(VERSION 3.10)

project(algorithm_study)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-Wall -Werror -std=c++20)

find_package(yaml-cpp REQUIRED)
find_package(fmt REQUIRED)
find_package(GTest REQUIRED)

set(SRC
  src/problem1.cpp
  src/problem2.cpp
  src/problem3.cpp
  src/problem4.cpp
)

set(TESTS
  test1.cpp
  test2.cpp
  test3.cpp
  test4.cpp
)

foreach(test ${TESTS})
  string(REPLACE ".cpp" "" test_name ${test})
  add_executable(${test_name} ${test} ${SRC})
  target_link_directories(${test_name} PRIVATE include)
  target_link_libraries(${test_name} yaml-cpp fmt::fmt GTest::GTest GTest::Main)
endforeach(test)

  
