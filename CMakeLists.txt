cmake_minimum_required(VERSION 3.15)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(src)

set(SOURCE_FILES
        src/Bishop.cpp
        src/King.cpp
        src/Knight.cpp
        src/Pawn.cpp
        src/Queen.cpp
        src/Rook.cpp
        src/Reactor.cpp
        src/Location.cpp
        src/main.cpp
        src/Board.cpp)

add_executable(Chess ${SOURCE_FILES})

