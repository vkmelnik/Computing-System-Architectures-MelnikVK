cmake_minimum_required(VERSION 3.20)
project(Task2_Code)

set(CMAKE_CXX_STANDARD 14)

add_executable(Task2 main.cpp Shape.cpp Shape.h Sphere.cpp Sphere.h Parallelepiped.cpp Parallelepiped.h Tetrahedron.cpp Tetrahedron.h Container.cpp Container.h)
