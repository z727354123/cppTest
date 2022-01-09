cmake_minimum_required(VERSION 3.21)
project(testOne)

set(CMAKE_CXX_STANDARD 14)

add_executable(testOne base/01_基本操作/01_函数重载/main.cpp)

project(02_extern)
file(GLOB 02_extern_SRC
        base/01_基本操作/02_extern/*.cpp
        base/01_基本操作/02_extern/*.c
        base/01_基本操作/02_extern/*.h)
add_executable(02_extern ${02_extern_SRC})


#project(03_extern)
#add_executable(03_extern base/01_基本操作/02_extern/main.cpp)
