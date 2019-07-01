//King.h
//Description: Extends Piece to King subclass
//Author: Zach Stoebner
//Created date: 6-12-19
// Created by Zachary Stoebner on 2019-06-12.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H

#include "Piece.h"
#include "Board.h"

class King : public Piece {

public:

    /*
    * default constructor
    * post: King is initialized
    */
    King(PieceColor pieceColor, size_t row, size_t col);

    /*
     * creates movement schema for Piece
     */
    std::set<Location> sight(const Board& board) const;

    /*
     * creates a movement schema for Piece
     * pre: Piece is King
     * post: set of possible movement Locations returned
     */
    std::set<Location> availableMoves(const Board& board, const std::set<Location>& checks);

    /*
     * castle
     * checks if possible castle for King
     * pre: Board is set
     * post: return bool if King and Rook haven't moved and no impeding pieces and no checks
     */
    bool castle (const Board& board) const;


};


#endif //CHESS_KING_H
