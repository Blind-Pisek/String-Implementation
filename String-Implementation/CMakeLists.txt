cmake_minimum_required(VERSION 3.0.0)
project(STL-STR-IMPLEMENTATION-LIB VERSION 0.1.0)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
    PRIVATE
    string.cpp
)