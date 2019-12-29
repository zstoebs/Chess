//Queen.h
//Description: Extends Piece to Queen subclass
//Author: Zach Stoebner
//Created date: 6-12-19
// Created by Zachary Stoebner on 2019-06-12.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H

#include "Piece.h"

class Queen : public Piece {

public:

    /*
     * default constructor
     * post: Queen is initialized
     */
    Queen(PieceColor pieceColor, size_t row, size_t col);

};


#endif //CHESS_QUEEN_H
