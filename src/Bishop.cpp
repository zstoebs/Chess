//Bishop.cpp
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
Bishop::Bishop(PieceColor pieceColor, u_int32_t row, u_int32_t col) : Piece(pieceColor,row,col) {}