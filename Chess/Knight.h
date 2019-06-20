//Knight.h
//Description: Extends Piece to Knight subclass
//Author: Zach Stoebner
//Created date: 6-12-19
// Created by Zachary Stoebner on 2019-06-12.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H

#include "Piece.h"
#include "Board.h"

class Knight : public Piece {

public:

    /*
     * default constructor
     * post: Knight is initialized
     */
    Knight(PieceColor pieceColor, size_t row, size_t col);

    /*
     * creates movement schema for Piece
     */
    std::set<Location> sight(const Board& board) const;

};


#endif //CHESS_KNIGHT_H
