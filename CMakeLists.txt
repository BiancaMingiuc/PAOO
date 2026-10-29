cmake_minimum_required(VERSION 3.16)

project(StudentMemoryManagement
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(student_demo
    src/main.cpp
    src/Student.cpp
)

target_include_directories(student_demo PRIVATE include)

if (MSVC)
    target_compile_options(student_demo PRIVATE /W4 /permissive-)
else()
    target_compile_options(student_demo PRIVATE -Wall -Wextra -Wpedantic)
endif()