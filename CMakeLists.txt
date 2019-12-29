cmake_minimum_required(VERSION 3.15)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(src)

set(SOURCE_FILES
        include/Bishop.h
        include/King.h
        include/Knight.h
        include/Pawn.h
        include/Piece.h
        include/Queen.h
        include/Rook.h
        src/Bishop.cpp
        src/King.cpp
        src/Knight.cpp
        src/Pawn.cpp
        src/Queen.cpp
        src/Rook.cpp)

add_executable(Chess ${SOURCE_FILES})

