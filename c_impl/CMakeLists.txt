cmake_minimum_required(VERSION 3.9)
project(AronsonsSequencePractice)

set(ASP_SOURCES
    src/main.c)

set(CMAKE_C_FLAGS "-Wall -Wextra -Wpedantic")
set(CMAKE_C_FLAGS_DEBUG "-g -O0")
set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG")

if(NOT CMAKE_BUILD_TYPE OR "${CMAKE_BUILD_TYPE}" MATCHES ^$)
    set(CMAKE_BUILD_TYPE "Debug")
    message("Set defualt build type to Debug")
endif()

add_executable(aronsonsSequence ${ASP_SOURCES})
