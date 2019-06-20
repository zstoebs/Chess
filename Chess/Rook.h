//Rook.h
//Description: Extends Piece to Rook subclass
//Author: Zach Stoebner
//Created date: 6-12-19
// Created by Zachary Stoebner on 2019-06-12.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include "Piece.h"
#include "Board.h"

class Rook : public Piece {

public:

    /*
     * default constructor
     * post: Rook is initialized
     */
    Rook(PieceColor pieceColor, size_t row, size_t col);

    /*
     * creates movement schema for Piece
     */
    std::set<Location> sight(const Board& board) const;

private:

    /*
     * addLocation
     * adds location to set, wrapped in for loop in sight method
     * pre: sight() is called
     * post: location added and current Piece count in given direction returned
     */
    void addLocation(const Board& b, std::set<Location>& curSet,size_t& curPcCount,
                     size_t row, size_t col) const;


};


#endif //CHESS_ROOK_H
