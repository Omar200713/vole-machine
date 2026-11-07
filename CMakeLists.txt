cmake_minimum_required(VERSION 4.0)
project(vole_machine)

set(CMAKE_CXX_STANDARD 20)

add_executable( vole_machine main.cpp
        DisplayManager.h
        SimulatorController.h
        Menu.h
        Menu.cpp
        SimulatorController.cpp
        DisplayManager.cpp
        Memory.cpp
        Memory.h
        Machine.h)



