//chessdriver.cpp
//Description: Executes chess game
//Author: Zach Stoebner
//Created date: 6-12-19
//Copyright © 2019

#include <iostream>
#include "Board.h"
#include "ChessData.h"


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