cmake_minimum_required(VERSION 3.9)
project(UnitTest)

set(CMAKE_CXX_STANDARD 11)

add_executable(UnitTest main.cpp File.cpp File.h Test.h Test.cpp)