cmake_minimum_required(VERSION 3.8)
project(Reversi)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(ReversiGame/lib/googletest-release-1.8.0)

include_directories(ReversiGame/lib/googletest-release-1.8.0/googletest/include)
include_directories(ReversiGame/lib/googletest-release-1.8.0/googlemock/include)

include_directories(ReversiGame)
include_directories(ReversiGame/Tests)
include_directories(ReversiGame/src)

set(TEST_FILES ReversiGame/Tests/BoardTest.cpp ReversiGame/Tests/CellTest.cpp ReversiGame/Tests/PlayerTest.cpp)
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
add_executable(test_main ${TEST_FILES} ${SOURCE_FILES} ReversiGame/Tests/gtest_main.cpp)

target_link_libraries(Reversi_main gtest gtest_main)
target_link_libraries(test_main gtest gtest_main)