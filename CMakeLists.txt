cmake_minimum_required(VERSION 3.17)
project(comp1601_finals)

set(CMAKE_CXX_STANDARD 14)

add_executable(comp1601_finals main.cpp util.cpp util.h menu.cpp menu.h)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/inf.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/outf.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})