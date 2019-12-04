cmake_minimum_required(VERSION 3.13)
project(DataTime_Pankova)

set(CMAKE_CXX_STANDARD 98)

add_executable(DataTime_Pankova src/Date.cpp headers/Date.h src/Time.cpp headers/Time.h headers/common.h src/DateTimeExceptions.cpp src/DualStream.cpp tests/DateTime_test.cpp)