cmake_minimum_required(VERSION 3.29)
project(cpp_lang_demo)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(src/educative)
include_directories(src/educative/learn-cpp-complete-course)

add_executable(cpp_lang_demo
    src/educative/learn-cpp-complete-course/section-1/main.cpp
    src/educative/learn-cpp-complete-course/section-3/main.cpp
    src/educative/learn-cpp-complete-course/section-4/main.cpp
        src/educative/learn-cpp-complete-course/section-5-operators/main.cpp
        src/educative/learn-cpp-complete-course/section-6-conditional-statements/main.cpp
        src/educative/learn-cpp-complete-course/section-7-loops/main.cpp
        src/educative/learn-cpp-complete-course/section-8-functions/main.cpp
        src/educative/learn-cpp-complete-course/section-9-recursive/main.cpp
        src/educative/learn-cpp-complete-course/section-10-arrays/main.cpp
        src/educative/learn-cpp-complete-course/section-11-computer-memory/main.cpp
        src/educative/learn-cpp-complete-course/section-12-dynamic-memory-allocation/main.cpp
        src/educative/learn-cpp-complete-course/section-13-structures/main.cpp
        src/educative/learn-cpp-complete-course/mini-project-1/main.cpp
        src/educative/learn-cpp-complete-course/mini-project-2/main.cpp)
