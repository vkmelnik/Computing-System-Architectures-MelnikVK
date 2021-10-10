cmake_minimum_required(VERSION 3.20)
project(Task1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Task1 main.cpp shape.h sphere.h parallelepiped.h tetrahedron.h shape.cpp sphere.cpp parallelepiped.cpp tetrahedron.cpp container.h container.cpp)
