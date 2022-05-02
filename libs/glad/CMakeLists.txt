cmake_minimum_required(VERSION 3.21)
project(glad)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_library(glad SHARED src/gl.c include/glad/gl.h include/KHR/khrplatform.h)
