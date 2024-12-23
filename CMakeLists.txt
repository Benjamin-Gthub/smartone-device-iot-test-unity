cmake_minimum_required(VERSION 3.30)
project(c_test C)

set(CMAKE_C_STANDARD 11)

add_executable(c_test main.c
        src/operations.h
        src/operations.c
        tests/unity.c
        tests/unity.h
        tests/test_operations.c
        shared/search_next_schedule.c
        tests/test_search_next_schedule.c
        shared/search_next_schedule.h)
