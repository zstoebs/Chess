//Bishop.h
//Description: Extends Piece to Bishop subclass
//Author: Zach Stoebner
//Created date: 6-12-19
// Created by Zachary Stoebner on 2019-06-12.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H

#include "Piece.h"


class Bishop : public Piece {

public:

    /*
     * default constructor
     * post: Bishop is initialized
     */
    Bishop(PieceColor pieceColor, size_t row, size_t col);

    /*
     * creates movement schema for Piece
     */
    std::set<Location> sight() const override;

};


#endif //CHESS_BISHOP_H
