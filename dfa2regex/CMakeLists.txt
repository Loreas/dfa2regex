cmake_minimum_required(VERSION 3.6)
project(dfa2regex)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Dfa.h Dfa.cpp)
add_executable(dfa2regex ${SOURCE_FILES})