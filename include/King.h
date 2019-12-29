//King.h
//Description: Extends Piece to King subclass
//Author: Zach Stoebner
//Created date: 6-12-19
// Created by Zachary Stoebner on 2019-06-12.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H

#include "Piece.h"

class King : public Piece {

public:

    /*
    * default constructor
    * post: King is initialized
    */
    King(PieceColor pieceColor, u_int32_t row, u_int32_t col);


};


#endif //CHESS_KING_H
