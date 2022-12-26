cmake_minimum_required(VERSION 3.15)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "-O2 -g -fsanitize=address")
set(CMAKE_CXX_FLAGS "-O2 -g ")
include_directories(include /usr/local/include/)
project(a.out LANGUAGES CXX)
add_executable(a.out main.cpp)

