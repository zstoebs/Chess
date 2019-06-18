//chessdriver.cpp
//Description: Executes chess game
//Author: Zach Stoebner
//Created date: 6-12-19
//Copyright © 2019

#include <iostream>
#include "Board.h"
#include "King.h"
#include "ChessData.h"


int main() {

    King king(BLACK,1,1);

    std::cout << king.getPieceType() << std::endl;

    return 0;
}