cmake_minimum_required(VERSION 3.8)
project(Server)

set(CMAKE_CXX_STANDARD 98)

set(CMAKE_CXX_FLAGS -pthread)

set(SOURCE_FILES
        Command.h
        CommandManager.cpp
        CommandManager.h
        Main.cpp
        Server.cpp
        Server.h
        serverConfiguration.txt ClientHandler.cpp ClientHandler.h StartCommand.cpp StartCommand.h ListGamesCommand.cpp ListGamesCommand.h JoinCommand.cpp JoinCommand.h GameManager.cpp GameManager.h ThreadPool.cpp ThreadPool.h Task.h)

add_executable(Server ${SOURCE_FILES})