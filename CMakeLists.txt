cmake_minimum_required(VERSION 3.8)
project(Reversi)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(ReversiGame/googletest-release-1.8.0)

include_directories(ReversiGame/googletest-release-1.8.0/googletest/include)
include_directories(ReversiGame/googletest-release-1.8.0/googlemock/include)
#include_directories(ReversiGame/gtest_src/gtest)
#include_directories(ReversiGame/gtest_src)

include_directories(ReversiGame)
include_directories(ReversiGame/test)
include_directories(ReversiGame/src)
include_directories(ReversiGame/include)

set(TEST_FILES ReversiGame/test/BoardTest.cpp ReversiGame/test/CellTest.cpp ReversiGame/test/PlayerTest.cpp ReversiGame/include/ClientPlayer.h ReversiGame/include/OpponentClientPlayer.h)
set(SOURCE_FILES
        ReversiGame/src/OpponentClientPlayer.cpp
        ReversiGame/src/Client.cpp
        ReversiGame/src/ClientPlayer.cpp
        ReversiGame/src/Main.cpp
        ReversiGame/src/AI.cpp
        ReversiGame/src/AiGame.cpp
        ReversiGame/src/Board.cpp
        ReversiGame/src/Cell.cpp
        ReversiGame/src/ConsoleDisplay.cpp
        ReversiGame/src/HumanPlayer.cpp
        ReversiGame/src/RemoteGame.cpp
        ReversiGame/src/TwoHumansGame.cpp
        ReversiGame/src/GameFlow
        ReversiGame/include/Client.h
        ReversiGame/include/AI.h
        ReversiGame/include/AiGame.h
        ReversiGame/include/Client.h
        ReversiGame/include/Board.h
        ReversiGame/include/ClientPlayer.h
        ReversiGame/include/OpponentClientPlayer.h
        ReversiGame/include/Cell.h
        ReversiGame/include/ConsoleDisplay.h
        ReversiGame/include/Display.h
        ReversiGame/include/GameLogic.h
        ReversiGame/include/HumanPlayer.h
        ReversiGame/include/Player.h
        ReversiGame/include/RemoteGame.h
        ReversiGame/include/TwoHumansGame.h
        ReversiGame/include/GameFlow)

add_executable(Reversi_main ${SOURCE_FILES} ReversiGame/src/Main.cpp ReversiGame/src/Client.cpp ReversiGame/include/Client.h ReversiGame/src/ClientPlayer.cpp ReversiGame/src/OpponentClientPlayer.cpp)
add_executable(test_main ${TEST_FILES} ${SOURCE_FILES} ReversiGame/test/gtest_main.cpp)

target_link_libraries(Reversi_main gtest gtest_main)
target_link_libraries(test_main gtest gtest_main)