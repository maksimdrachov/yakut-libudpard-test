cmake_minimum_required(VERSION 3.12)
project(yakut_libudpard_test C CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCES
        src/main.cpp
        src/udpard.c)

add_executable(MyExecutable ${SOURCES})
