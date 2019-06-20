//Pawn.cpp
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
std::set<Location> Pawn::sight(const Board& board) const {

    std::set<Location> schema;
    PcPtr ptr; //to check for piece color at diagonals

    ///ADD EN PASSANT MOVES

    if (color == WHITE && location.row < ROWS-1) {

        //getting forward tile
        if (!board.hasPiece(location.row+1,location.column)) {

                schema.insert(schema.begin(),Location(location.row+1,location.column));

        }

        //adding diagonal locations if there is a piece to take
        if (location.column > 0) {

            ptr = board.getPiece(location.row+1,location.column-1);

            if (ptr && ptr->getColor() != this->color) {

                schema.insert(schema.begin(),Location(location.row+1,location.column-1));

            }

        }

        if (location.column < COLUMNS-1) {

            ptr = board.getPiece(location.row+1,location.column+1);

            if (ptr && ptr->getColor() != this->color) {

                schema.insert(schema.begin(),Location(location.row+1,location.column+1));

            }

        }

    }


    if (color == BLACK && location.row > 0) {

        //adding forward tile
        if (!board.hasPiece(location.row-1,location.column)) {

            schema.insert(schema.begin(),Location(location.row-1,location.column));

        }

        //adding diagonal tiles if there is a piece to take
        if (location.column > 0) {

            ptr = board.getPiece(location.row-1,location.column-1);

            if (ptr && ptr->getColor() != this->color) {

                schema.insert(schema.begin(),Location(location.row-1,location.column-1));

            }

        }

        if (location.column < COLUMNS-1) {

            ptr = board.getPiece(location.row-1,location.column+1);

            if (ptr && ptr->getColor() != this->color) {

                schema.insert(schema.begin(),Location(location.row-1,location.column+1));

            }

        }

    }

    return schema;

}
