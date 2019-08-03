cmake_minimum_required(VERSION 3.14)
project(Demo C CXX)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp)
add_executable(2ndPoint 二级指针函数输出.c
      )
add_executable(dynamicalloc   动态内存分配.c)
add_executable(leakmem leak/leakmem.h leak/leakmem.c leak/leakmem_test.c)
add_executable(encry encryption/encrypt.c)
