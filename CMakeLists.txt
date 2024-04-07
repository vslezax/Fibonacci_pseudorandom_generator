cmake_minimum_required(VERSION 3.27)
project(Fibonacci)

set(CMAKE_CXX_STANDARD 23)

add_executable(Fibonacci main.cpp FibonacciGenerator.cpp FibonacciGenerator.h)
