cmake_minimum_required(VERSION 3.21)
project(Toreador)

set(CMAKE_CXX_STANDARD 17)
add_compile_definitions(BUILD_SHARED_LIBS)

add_subdirectory(libs/glfw)
add_subdirectory(libs/glad)

include_directories(include)
include_directories(libs/glfw/include)
include_directories(libs/glad/include)

add_library(Toreador SHARED src/Toreador/Core/Application/Application.cpp include/Toreador/Core/Application/EntryPoint.hpp) #CPP files only
target_include_directories(Toreador PUBLIC include)
target_link_libraries(Toreador glfw)
target_link_libraries(Toreador glad)

add_subdirectory(test)