cmake_minimum_required(VERSION 3.5)

project(timedate LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(timedate structs.h timedate.cpp timedate.h main.cpp)
