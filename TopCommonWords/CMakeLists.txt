cmake_minimum_required(VERSION 3.15.3)
project(TopCommonWords)

set(CMAKE_CXX_STANDARD 11)

add_executable(TopCommonWords main.cpp map.cpp validation.cpp map.h validation.h)
