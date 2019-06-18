//Queen.h
//Description: Extends Piece to Queen subclass
//Author: Zach Stoebner
//Created date: 6-12-19
// Created by Zachary Stoebner on 2019-06-12.
//

#include "Queen.h"

/*
* default constructor
* post: Queen is initialized
*/
Queen::Queen(PieceColor pieceColor, size_t row, size_t col) : Piece(pieceColor,QUEEN,row,col) {}

/*
 * creates movement schema for Piece
 */
std::set<Location> Queen::sight() const {

    std::set<Location> schema;



    return schema;

}