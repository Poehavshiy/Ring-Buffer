cmake_minimum_required(VERSION 2.8)
project(Cycle_Buffer)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c Ring_Buffer.h Ring_Buffer.c)
add_executable(Cycle_Buffer ${SOURCE_FILES})