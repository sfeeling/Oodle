cmake_minimum_required(VERSION 3.10)
project(Oodle)

set(CMAKE_CXX_STANDARD 14)

add_executable(Oodle src/Main.cpp src/FileInfo.cpp src/FileInfo.h src/DirInfo.cpp src/DirInfo.h src/Pickler.cpp src/Pickler.h src/PicklerMode.cpp src/PicklerMode.h src/SortStrategy.cpp src/SortStrategy.h src/SortFactory.cpp src/SortFactory.h src/DirComponent.cpp src/DirComponent.h src/Filter.cpp src/Filter.h)