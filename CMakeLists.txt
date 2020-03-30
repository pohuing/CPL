cmake_minimum_required(VERSION 3.15)
project(CPL C)

set(CMAKE_C_STANDARD 11)

include_directories(src/lib)
add_definitions(-DCOLLECT_STATS)
add_executable(CPL
        src/lib/data.c
        src/lib/data.h
        src/lib/file.c
        src/lib/file.h
        src/lib/sort.c
        src/lib/sort.h
        src/lib/ui.c
        src/lib/ui.h
        src/main.c)
