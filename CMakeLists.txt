cmake_minimum_required(VERSION 3.7)
project(calc)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES
        main.c
        calc.c calc.h
        math/add.c math/add.h
        math/mult.h math/mult.c
        math/sub.h
        utils/parse.c utils/parse.h
        utils/reverse.h utils/reverse.c
        utils/alloc.h utils/alloc.c
        )
add_executable(calc ${SOURCE_FILES})