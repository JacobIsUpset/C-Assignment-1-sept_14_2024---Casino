cmake_minimum_required(VERSION 3.29)
project(Casino_Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(Casino_Project
        casino.cpp
        Includes/persistence.cpp
        Includes/gameController.cpp
        Includes/games.cpp
)

