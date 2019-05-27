cmake_minimum_required(VERSION 3.13)
project(Tree_moskanova)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS -export)

include_directories(BEFORE src)
include_directories(BEFORE tests)

add_library(Tree       MODULE src/Tree.h         src/Tree.cpp)
add_library(BinaryTree STATIC src/BinaryTree.cpp src/BinaryTree.h)
add_library(PrefixTree STATIC src/PrefixTree.cpp src/PrefixTree.h)

add_executable(test_tree tests/test_tree.cpp)

#find_package(Tree COMPONENTS REQUIRED src/Tree.h src/Tree.cpp)
#target_include_directories(test_tree PUBLIC src)

#target_link_libraries(test_tree Tree)