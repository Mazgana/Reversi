cmake_minimum_required(VERSION 3.8)
project(Reversi)

set(CMAKE_CXX_STANDARD 11)

include_directories(ReversiGame)

set(SOURCE_FILES
        ReversiGame/src/Board.cpp
        ReversiGame/src/Board.h
        ReversiGame/src/Cell.cpp
        ReversiGame/src/Cell.h
        ReversiGame/src/Game.cpp
        ReversiGame/src/Game.h
        ReversiGame/src/AI.cpp
        ReversiGame/src/AI.h
        ReversiGame/src/HumanPlayer.cpp
        ReversiGame/src/HumanPlayer.h
        ReversiGame/src/Player.h)

add_executable(Reversi_main ${SOURCE_FILES} ReversiGame/src/Main.cpp)
#add_executable(Reversi ${SOURCE_FILES})

#add_subdirectory(lib/googletest-release-1.8.0)

#include_directories(lib/googletest-release-1.8.0/googletest/include)
#include_directories(lib/googletest-release-1.8.0/googlemock/include)

#include_directories(src)

#set(TEST_FILES tests/PlayerTest.cpp tests/CellTest.cpp tests/BoardTest.cpp)
#set(SOURCE_FILES src/Board.cpp src/Board.h src/Cell.cpp src/Cell.h src/Player.cpp src/Player.h src/ReversiGame.cpp src/ReversiGame.h)

#add_executable(ex2_main ${SOURCE_FILES} src/main.cpp)
#add_executable(test_main ${TEST_FILES} ${SOURCE_FILES} tests/gtest_main.cpp)

#target_link_libraries(ex2_main gtest gtest_main)
#target_link_libraries(test_main gtest gtest_main)