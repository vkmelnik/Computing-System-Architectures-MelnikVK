cmake_minimum_required(VERSION 3.20)
project(Task5_Code)

set(CMAKE_CXX_STANDARD 20)

add_executable(gallery_simulator main.cpp main.cpp Gallery.cpp Gallery.h Picture.cpp Picture.h)
