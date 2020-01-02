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
    Bishop(PieceColor pieceColor, u_int32_t row, u_int32_t col);

protected:

    /*
 * Updates valid move set
 */
    virtual std::set<Location> updateValidMoves(const Board* board);

};


#endif //CHESS_BISHOP_H
