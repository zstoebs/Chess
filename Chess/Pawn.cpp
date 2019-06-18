//Pawn.h
//Description: Extends Piece to Pawn subclass
//Author: Zach Stoebner
//Created date: 6-12-19
// Created by Zachary Stoebner on 2019-06-12.
//

#include "Pawn.h"

/*
* default constructor
* post: Queen is initialized
*/
Pawn::Pawn(PieceColor pieceColor, size_t row, size_t col) : Piece(pieceColor,PAWN,row,col) {}

/*
 * creates movement schema for Piece
 */
std::set<Location> Pawn::sight() const {

    std::set<Location> schema;



    return schema;

}
