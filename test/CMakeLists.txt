cmake_minimum_required(VERSION 3.21)
project(ToreadorTest)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include_directories(../include)

add_executable(ToreadorTest src/main.cpp)
target_link_libraries(ToreadorTest Toreador)