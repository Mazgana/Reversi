cmake_minimum_required(VERSION 3.8)
project(Reversi)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        AI.cpp
        AI.h
        Board.cpp
        Board.h
        Cell.cpp
        Cell.h
        Game.cpp
        Game.h
        HumanPlayer.cpp
        HumanPlayer.h
        Main.cpp
        Player.h)

add_executable(Reversi ${SOURCE_FILES})