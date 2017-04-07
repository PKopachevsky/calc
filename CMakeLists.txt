cmake_minimum_required(VERSION 3.7)
project(calc)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c calc.c calc.h parse.c parse.h)
add_executable(calc ${SOURCE_FILES})