//Pawn.h
//Description: Extends Piece to Pawn subclass
//Author: Zach Stoebner
//Created date: 6-12-19
// Created by Zachary Stoebner on 2019-06-12.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include "Piece.h"

class Pawn : public Piece {

public:

    /*
    * default constructor
    * post: Pawn is initialized
    */
    Pawn(PieceColor pieceColor, size_t row, size_t col);

};


#endif //CHESS_PAWN_H
