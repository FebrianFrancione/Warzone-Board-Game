cmake_minimum_required(VERSION 3.17)
project(COMP_345_Warzone)

set(CMAKE_CXX_STANDARD 14)

include_directories(Part2)

add_executable(COMP_345_Warzone
        Part2/Cards.cpp
        Part2/Cards.h
        Part2/CardsDriver.cpp
        Part2/startupPhase.cpp
        Part2/startupPhase.h
        Map.cpp
        Map.h
        MapDriver.cpp
        Orders.h
        Orders.cpp
        OrdersDriver.cpp
        Part2/Player.cpp
        Part2/Player.h)