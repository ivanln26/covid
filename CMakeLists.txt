cmake_minimum_required(VERSION 3.13)
project(CMake_covid)

set(CMAKE_CXX_STANDARD 14)

add_executable(CMake_covid main.cpp CSVReader.cpp Estadistica.cpp Contador.cpp Caso.cpp Fecha.cpp)