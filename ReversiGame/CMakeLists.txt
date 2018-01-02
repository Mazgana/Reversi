cmake_minimum_required(VERSION 3.8)
project(ReversiGame)

set(CMAKE_CXX_STANDARD 98)

include_directories(ReversiGame)
include_directories(ReversiGame/src)
include_directories(ReversiGame/include)

set(SOURCE_FILES
        include/AI.h
        include/AiGame.h
        include/Board.h
        include/Cell.h
        include/Client.h
        include/ClientPlayer.h
        include/ConsoleDisplay.h
        include/Display.h
        include/GameFlow.h
        include/GameLogic.h
        include/HumanPlayer.h
        include/OpponentClientPlayer.h
        include/Player.h
        include/RemoteGame.h
        include/TwoHumansGame.h
        src/AI.cpp
        src/AiGame.cpp
        src/Board.cpp
        src/Cell.cpp
        src/Client.cpp
        src/ClientPlayer.cpp
        src/ConsoleDisplay.cpp
        src/GameFlow.cpp
        src/HumanPlayer.cpp
        src/Main.cpp
        src/OpponentClientPlayer.cpp
        src/RemoteGame.cpp
        src/TwoHumansGame.cpp)

add_executable(Reversi_main ${SOURCE_FILES} src/Main.cpp src/Client.cpp include/Client.h src/ClientPlayer.cpp src/OpponentClientPlayer.cpp)
