cmake_minimum_required(VERSION 3.10)
project(Oodle)

set(CMAKE_CXX_STANDARD 14)

add_executable(Oodle src/sources/Main.cpp src/sources/FileInfo.cpp src/headers/FileInfo.h src/sources/DirInfo.cpp src/headers/DirInfo.h src/sources/Pickler.cpp src/headers/Pickler.h src/sources/PicklerMode.cpp src/headers/PicklerMode.h src/sources/SortStrategy.cpp src/headers/SortStrategy.h src/sources/SortFactory.cpp src/headers/SortFactory.h src/headers/DirComponent.h src/sources/Filter.cpp src/headers/Filter.h)