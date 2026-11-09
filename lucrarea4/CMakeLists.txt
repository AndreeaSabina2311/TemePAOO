cmake_minimum_required(VERSION 3.10)

project(MiniCalculator)

include_directories(inc)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(MiniCalculator main.cpp)