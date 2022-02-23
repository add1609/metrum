cmake_minimum_required(VERSION 3.21)
project(metrum)

set(CMAKE_CXX_STANDARD 20)

add_executable(metrum main.cpp Tokenizer.cpp Tokenizer.hpp)
