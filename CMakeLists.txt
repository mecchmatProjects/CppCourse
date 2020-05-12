cmake_minimum_required(VERSION 3.13)
project(DateTime)

set(CMAKE_CXX_STANDARD 98)

add_executable(DateTime tests/DateTime_test.cpp src/Date.cpp headers/Date.h
        src/Time.cpp headers/Time.h src/DateTimeExceptions.cpp src/DualStream.cpp)