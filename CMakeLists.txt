cmake_minimum_required(VERSION 3.24)
project(Modeling)

set(CMAKE_CXX_STANDARD 14)

include_directories(lab_1)

add_executable(Modeling
        lab_1/first_lab.cpp
        lab_1/first_lab.h
        main.cpp)
