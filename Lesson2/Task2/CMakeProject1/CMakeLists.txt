cmake_minimum_required(VERSION 3.27)
project(Lab_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(CMakeProject1
        Gauss.h
        CMakeProject1.cpp
        "QR decomposition.h"
        matrix_operations.h)
