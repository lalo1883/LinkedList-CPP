cmake_minimum_required(VERSION 3.28)
project(ArrayC)

set(CMAKE_CXX_STANDARD 17)

add_executable(ArrayC main.cpp
        LinkedList.cpp
        LinkedList.h)
