cmake_minimum_required(VERSION 3.27)
project(semestralka C)

set(CMAKE_C_STANDARD 11)

add_executable(semestralka main.c hrac.c moderator.c
        moderator.h
        hrac.h
        kviz.h)
