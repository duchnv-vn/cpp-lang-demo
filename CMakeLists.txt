cmake_minimum_required(VERSION 3.29)
project(cpp_lang_demo)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        src/ptit/trr/final/question12.cpp
)

include_directories(src)

add_executable(cpp_lang_demo ${SOURCE_FILES})
