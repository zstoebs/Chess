//Pawn.h
//Description: Extends Piece to Pawn subclass
//Author: Zach Stoebner
//Created date: 6-12-19
// Created by Zachary Stoebner on 2019-06-12.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include "Piece.h"
#include "Board.h"

class Pawn : public Piece {

    bool justMoved2 = false;

public:

    /*
    * default constructor
    * post: Pawn is initialized
    */
    Pawn(PieceColor pieceColor, size_t row, size_t col);

    /*
     * creates movement schema for Piece
     */
    std::set<Location> sight(const Board& board) const;

    /*
     * checks if possible en passant
     */
    bool enPassant(const Board& board) const;

    /*
     * changes field for a pawn that has just moved 2 tiles from start
     */
    void setJustMoved2(bool state);

    /*
     * returns Boolean if pawn just moved 2 tiles from start
     */
    bool hasJustMoved2() const;

};


#endif //CHESS_PAWN_H
