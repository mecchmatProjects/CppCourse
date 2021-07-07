cmake_minimum_required(VERSION 3.13)
project(Tree_moskanova)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS -export)

include_directories(BEFORE src)
include_directories(BEFORE tests)

add_library(TreeError  MODULE src/TreeError.h src/TreeError.cpp)

add_library(Tree       MODULE src/TreeError.h src/TreeError.cpp src/Tree.h         src/Tree.cpp     src/TreeError.h src/TreeError.cpp)
add_library(BinaryTree MODULE src/BinaryTree.h src/BinaryTree.cpp )
add_library(PrefixTree MODULE src/PrefixTree.cpp src/PrefixTree.h)

#add_dependencies(Tree TreeError)
#target_link_libraries(Tree PUBLIC TreeError)

add_executable(test_tree tests/test_tree.cpp)
add_executable(test_binary_tree tests/test_binary_tree.cpp)
add_executable(test_prefix_tree tests/test_prefix_tree.cpp)

#find_package(Tree COMPONENTS REQUIRED src/Tree.h src/Tree.cpp)
#target_include_directories(test_tree PUBLIC src)

#target_link_libraries(test_tree Tree)