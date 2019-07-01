//chessdriver.cpp
//Description: Executes ChessGame
//Author: Zach Stoebner
//Created date: 6-12-19
//Copyright © 2019

#include <iostream>
#include "Board.h"
#include "ChessData.h"
#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"


int main() {

    Board b;
    b.resetBoard();

    if (b.hasPiece(1,1)) {

        std::cout << "True" << std::endl;
    } else {

        std::cout << "False" << std::endl;

    }

    return 0;
}