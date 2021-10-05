cmake_minimum_required(VERSION 3.16)
project(APUE C)

set(CMAKE_C_STANDARD 99)

add_executable(APUE main.c fileIO.c fileIO.h err_log.c err_log.h)