cmake_minimum_required(VERSION 3.12)
project(example)

find_package(pybind11 REQUIRED)

pybind11_add_module(ml_lib main_pybind.cpp)

# You can set additional flags here if needed
# target_compile_options(example PRIVATE ...)

# Specify additional include directories if needed
# target_include_directories(example PRIVATE ...)

# Link against Python's libraries
# target_link_libraries(example PRIVATE Python3::Python)
