cmake_minimum_required(VERSION 3.17)
project(ClassesandSingleton)

set(CMAKE_CXX_STANDARD 14)

add_executable(ClassesandSingleton main.cpp Student.cpp Grade.cpp Logger.cpp Logger.h Student.h Grade.h main.h)