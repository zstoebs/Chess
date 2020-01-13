// Bishop.cpp
// Description: Extends Piece to Bishop subclass
// Author: Zach Stoebner
// Created date: 6-12-19
// Created by Zachary Stoebner on 2019-06-12.
//

#include "Bishop.h"

/*
 * default constructor
 * post: Queen is initialized
 */
Bishop::Bishop(PieceColor pieceColor, u_int32_t row, u_int32_t col)
    : Piece(pieceColor, row, col) {}

std::set<Location> Bishop::updateValidMoves(const Board *board) {
    std::set<Location> schema;

    PcPtr ptr;
    size_t i; //row index
    size_t j; //column index
    size_t pieceCount; //one piece can be in sight in any given direction,
    // but after that she's blind (helper function will return one

    //adding all down-left diagonal tiles
    for (i = location.row+1, j = location.column-1, pieceCount = 0;
         i < ROWS && j >= 0 && pieceCount == 0; ++i, --j) {

        ptr = getPiece(i, j);

        if (!ptr || ptr->getColor() != color) {

            addLocation(schema,pieceCount,i,j);

        }

    }


    //adding all down-right diagonal tiles
    for (i = location.row+1, j = location.column+1, pieceCount = 0;
         i < ROWS && j < COLUMNS && pieceCount == 0; ++i, ++j) {

        ptr = getPiece(i, j);

        if (!ptr || ptr->getColor() != color) {

            addLocation(schema,pieceCount,i,j);

        }

    }

    //adding all up-left diagonal tiles
    for (i = location.row-1, j = location.column-1, pieceCount = 0;
         i >= 0 && j >= 0 && pieceCount == 0; --i, --j) {

        ptr = getPiece(i, j);

        if (!ptr || ptr->getColor() != color) {

            addLocation(schema,pieceCount,i,j);

        }

    }


    //adding all up-right diagonal tiles
    for (i = location.row-1, j = location.column+1, pieceCount = 0;
         i >= 0 && j < COLUMNS && pieceCount == 0; --i, ++j) {

        ptr = getPiece(i, j);

        if (!ptr || ptr->getColor() != color) {

            addLocation(schema,pieceCount,i,j);

        }

    }

    return schema;
}