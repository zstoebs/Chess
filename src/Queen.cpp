//Queen.cpp
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
Queen::Queen(PieceColor pieceColor, u_int32_t row, u_int32_t col) : Piece(pieceColor,row,col) {}