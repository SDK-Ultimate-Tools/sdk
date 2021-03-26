cmake_minimum_required(VERSION 3.19)
project(sdk)

set(CMAKE_CXX_STANDARD 17)

add_executable(sdk
        mem/setMem.cpp)

add_executable(sdkmemset mem/custom-array.cpp)