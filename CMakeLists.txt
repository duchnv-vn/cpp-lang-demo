cmake_minimum_required(VERSION 3.29)
project(cpp_lang_demo)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        src/educative/object-oriented-programming/3-inheritance/Vehicle.cpp
        src/educative/object-oriented-programming/3-inheritance/Vehicle.h
        src/educative/object-oriented-programming/3-inheritance/main.cpp
        src/educative/object-oriented-programming/3-inheritance/Car.cpp
        src/educative/object-oriented-programming/3-inheritance/Car.h
        src/educative/object-oriented-programming/3-inheritance/License.cpp
        src/educative/object-oriented-programming/3-inheritance/License.h
        src/educative/object-oriented-programming/3-inheritance/Honda.cpp
        src/educative/object-oriented-programming/3-inheritance/Honda.h
)

include_directories(src)

add_executable(cpp_lang_demo ${SOURCE_FILES})
