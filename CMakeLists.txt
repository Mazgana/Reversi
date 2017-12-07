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

set(TEST_FILES ReversiGame/test/BoardTest.cpp ReversiGame/test/CellTest.cpp ReversiGame/test/PlayerTest.cpp ReversiGame/include/ClientPlayer.h ReversiGame/include/componentClientPlayer.h)
set(SOURCE_FILES
        ReversiGame/src/Board.cpp
        ReversiGame/include/Board.h
        ReversiGame/src/Cell.cpp
        ReversiGame/include/Cell.h
        ReversiGame/src/Game.cpp
        ReversiGame/include/Game.h
        ReversiGame/src/AI.cpp
        ReversiGame/include/AI.h
        ReversiGame/src/HumanPlayer.cpp
        ReversiGame/include/HumanPlayer.h
        ReversiGame/include/Player.h)

add_executable(Reversi_main ${SOURCE_FILES} ReversiGame/src/Main.cpp ReversiGame/src/Client.cpp ReversiGame/include/Client.h ReversiGame/src/ClientPlayer.cpp ReversiGame/src/componentClientPlayer.cpp)
add_executable(test_main ${TEST_FILES} ${SOURCE_FILES} ReversiGame/test/gtest_main.cpp)

target_link_libraries(Reversi_main gtest gtest_main)
target_link_libraries(test_main gtest gtest_main)