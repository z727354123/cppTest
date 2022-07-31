cmake_minimum_required(VERSION 3.21)
project(testOne)
set(CMAKE_CXX_STANDARD 14)
add_executable(testOne base/01_基本操作/01_函数重载/main.cpp)

#第2个项目
set(myPath 02_extern)
set(myProName 02_Pro)
project(${myProName})
file(GLOB ${myProName}
        base/01_基本操作/${myPath}/*.cpp
        base/01_基本操作/${myPath}/*.c
        base/01_基本操作/${myPath}/*.h)
add_executable(${myProName} ${${myProName}})

#第3个项目
set(myPath 03_默认参数)
set(myProName 03_Proj)
project(${myProName})
file(GLOB ${myProName}
        base/01_基本操作/${myPath}/*.cpp
        base/01_基本操作/${myPath}/*.c
        base/01_基本操作/${myPath}/*.h)
add_executable(${myProName} ${${myProName}})

#第4个项目
set(myPath 04_内联函数)
set(myProName 04_Proj)
project(${myProName})
file(GLOB ${myProName}
        base/01_基本操作/${myPath}/*.cpp
        base/01_基本操作/${myPath}/*.c
        base/01_基本操作/${myPath}/*.h)
add_executable(${myProName} ${${myProName}})

#第5个项目
set(myPath 05_引用本质)
set(myProName 05_Proj)
project(${myProName})
file(GLOB ${myProName}
        base/01_基本操作/${myPath}/*.cpp
        base/01_基本操作/${myPath}/*.c
        base/01_基本操作/${myPath}/*.h)
add_executable(${myProName} ${${myProName}})
