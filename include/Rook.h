//Rook.h
//Description: Extends Piece to Rook subclass
//Author: Zach Stoebner
//Created date: 6-12-19
// Created by Zachary Stoebner on 2019-06-12.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include "Piece.h"

class Rook : public Piece {

public:

    /*
     * default constructor
     * post: Rook is initialized
     */
    Rook(PieceColor pieceColor, u_int32_t row, u_int32_t col);


};


#endif //CHESS_ROOK_H
