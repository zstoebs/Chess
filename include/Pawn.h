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
    Pawn(PieceColor pieceColor, u_int32_t row, u_int32_t col);


protected:

    /*
 * Updates valid move set
 */
    virtual std::set<Location> updateValidMoves(const Board* board);

};


#endif //CHESS_PAWN_H
