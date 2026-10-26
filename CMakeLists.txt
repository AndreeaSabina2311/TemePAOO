cmake_minimum_required(VERSION 3.10)

project(hello)

include_directories(inc)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME}
    inc/hello/hello_config.hpp
    inc/hello/hello.hpp
    src/main.cpp
    src/hello.cpp
)