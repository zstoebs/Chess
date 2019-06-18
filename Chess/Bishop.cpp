//Bishop.h
//Description: Extends Piece to Bishop subclass
//Author: Zach Stoebner
//Created date: 6-12-19
// Created by Zachary Stoebner on 2019-06-12.
//

#include "Bishop.h"

/*
* default constructor
* post: Queen is initialized
*/
Bishop::Bishop(PieceColor pieceColor, size_t row, size_t col) : Piece(pieceColor,BISHOP,row,col) {}

/*
 * creates movement schema for Piece
 */
std::set<Location> Bishop::sight() const {

    std::set<Location> schema;



    return schema;

}