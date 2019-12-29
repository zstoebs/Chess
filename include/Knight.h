//Knight.h
//Description: Extends Piece to Knight subclass
//Author: Zach Stoebner
//Created date: 6-12-19
// Created by Zachary Stoebner on 2019-06-12.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H

#include "Piece.h"

class Knight : public Piece {

public:

    /*
     * default constructor
     * post: Knight is initialized
     */
    Knight(PieceColor pieceColor, u_int32_t row, u_int32_t col);

};


#endif //CHESS_KNIGHT_H
