// Pawn.cpp
// Description: Extends Piece to Pawn subclass
// Author: Zach Stoebner
// Created date: 6-12-19
// Created by Zachary Stoebner on 2019-06-12.
//

#include "Pawn.h"

/*
 * default constructor
 * post: Queen is initialized
 */
Pawn::Pawn(PieceColor pieceColor, u_int32_t row, u_int32_t col)
    : Piece(pieceColor, row, col) {}

std::set<Location> Pawn::updateValidMoves(const Board *board) {
  std::set<Location> moves;
  return moves;
}
