cmake_minimum_required(VERSION 3.9)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 11)

add_executable(GameOfLife main.cpp Grid.h Grid.cpp Multithreads.h Multithreads.cpp)