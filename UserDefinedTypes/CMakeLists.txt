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
        include/class_hierarchies/shape.h
        include/class_hierarchies/shape.cpp)

target_include_directories(UserDefinedTypes PRIVATE ${CMAKE_SOURCE_DIR}/include)

