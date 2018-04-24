cmake_minimum_required(VERSION 3.10)
project(Oodle)

set(CMAKE_CXX_STANDARD 11)

add_executable(Oodle src/Main.cpp src/FileInfo.cpp src/FileInfo.h src/DirInfo.cpp src/DirInfo.h src/Pickler.cpp src/Pickler.h src/PicklerMode.cpp src/PicklerMode.h src/SortStrategy.cpp src/SortStrategy.h)