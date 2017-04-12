cmake_minimum_required(VERSION 3.7)
project(calc)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c add.c add.h parse.c parse.h calc.c calc.h reverse.h reverse.c)
add_executable(calc ${SOURCE_FILES})