cmake_minimum_required(VERSION 3.14)
project(Chess)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        chessdriver.cpp
        Piece.h
        Board.cpp Board.h
        BoardNode.cpp BoardNode.h
        King.cpp King.h
        Queen.cpp Queen.h
        Bishop.cpp Bishop.h
        Knight.cpp Knight.h
        Rook.cpp Rook.h
        Pawn.cpp Pawn.h ChessData.h)


add_executable(Chess ${SOURCES})