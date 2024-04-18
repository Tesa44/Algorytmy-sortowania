cmake_minimum_required(VERSION 3.27)
project(SortingApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(SortingApp main.cpp
        Menu.cpp
        Menu.h
        App.h
        Sort/InsertionSort.h
        Sort/HeapSort.h
        Sort/QuickSort.h
        Sort/ShellSort.h
        Model.h
)
