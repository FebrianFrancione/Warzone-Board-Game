cmake_minimum_required(VERSION 3.17)
project(COMP_345_Warzone)

set(CMAKE_CXX_STANDARD 14)

#[[include_directories(WarZone/Part2)]]
INCLUDE_DIRECTORIES(WarZone)

add_executable(COMP_345_Warzone
        WarZone/Cards.cpp
        WarZone/Cards.h
        WarZone/CardsDriver.cpp
        WarZone/startupPhase.cpp
        WarZone/startupPhase.h
        WarZone/Map.cpp
        WarZone/Map.h
        WarZone/MapDriver.cpp
        WarZone/MapLoader.cpp
        WarZone/MapLoader.h
        WarZone/Orders.h
        WarZone/Orders.cpp
        WarZone/OrdersDriver.cpp
        WarZone/Player.cpp
        WarZone/Player.h
        WarZone/GameEngine.h
        WarZone/GameEngine.cpp
        WarZone/GameDriver.cpp
        WarZone/PlayerStrategies.cpp
        WarZone/PlayerStrategies.h)