cmake_minimum_required(VERSION 2.8)

## Use the variable PROJECT_NAME for changing the target name
set( PROJECT_NAME "HelloWorld" )

## Set our project name
project(${PROJECT_NAME})

include_directories ("Headers")

## Use all the *.cpp files we found under this folder for the project
FILE(GLOB SRCS "*.cpp" "source/*.c")

## Use all the *.h files we found under this folder for the project
FILE(GLOB HDRS "*.h" "*.hpp")

## Define the executable
add_executable(${PROJECT_NAME} ${HDRS} ${SRCS})
