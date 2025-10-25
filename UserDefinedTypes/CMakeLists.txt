cmake_minimum_required(VERSION 4.0)
project(UserDefinedTypes)

set(CMAKE_CXX_STANDARD 20)

add_executable(UserDefinedTypes main.cpp
        vector.h
        vector.cpp
        complex.h
        complex.cpp
        container.h
        vector_container.h
        list_container.h
        list_container.cpp
        class_hierarchies/shape.h
        class_hierarchies/shape.cpp)
