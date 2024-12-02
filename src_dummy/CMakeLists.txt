# Basic CMakeLists.txt taken from documentation https://pybind11.readthedocs.io/en/stable/compiling.html#cmake

cmake_minimum_required(VERSION 3.15...3.30)
project(ada_dummy LANGUAGES CXX)


set(PYBIND11_FINDPYTHON ON)
find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(ada_dummy pywrap.cpp)
install(TARGETS ada_dummy DESTINATION .)
