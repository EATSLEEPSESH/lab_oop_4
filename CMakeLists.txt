cmake_minimum_required(VERSION 3.27)
project(lab_OOP_4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(lab_OOP_4 main.cpp)
add_subdirectory(Google_Tests)
target_include_directories(lab_OOP_4 PRIVATE include)

enable_testing()