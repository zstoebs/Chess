//Knight.cpp
//Description: Extends Piece to Knight subclass
//Author: Zach Stoebner
//Created date: 6-12-19
// Created by Zachary Stoebner on 2019-06-12.
//

#include "Knight.h"

/*
* default constructor
* post: Knight is initialized
*/
Knight::Knight(PieceColor pieceColor, size_t row, size_t col) : Piece(pieceColor,KNIGHT,row,col) {}

/*
 * creates movement schema for Piece
 */
std::set<Location> Knight::sight(const Board& board) const {

    std::set<Location> schema;
    PcPtr ptr; //to check piece color at a candidate location

    //adding downward pair
    if (location.row+2 < ROWS) {

        if (location.column-1 >=0) {

            ptr = board.getPiece(location.row+2,location.column-1);

            if ( ptr->getColor() != this->color)
                schema.insert(schema.begin(),Location(location.row+2,location.column-1));

        }

        if (location.column+1 < COLUMNS){

            ptr = board.getPiece(location.row+2,location.column+1);

            if (ptr->getColor() != this->color)
                schema.insert(schema.begin(),Location(location.row+2,location.column+1));

        }

    }

    //adding upward pair
    if (location.row-2 >=0) {

        if (location.column-1 >=0) {

            ptr = board.getPiece(location.row-2,location.column-1);

            if ( ptr->getColor() != this->color)
                schema.insert(schema.begin(),Location(location.row-2,location.column-1));

        }

        if (location.column+1 < COLUMNS){

            ptr = board.getPiece(location.row-2,location.column+1);

            if (ptr->getColor() != this->color)
                schema.insert(schema.begin(),Location(location.row-2,location.column+1));

        }

    }

    //adding leftward pair
    if (location.column-2 >=0) {

        if (location.row-1 >=0) {

            ptr = board.getPiece(location.row-1,location.column-2);

            if ( ptr->getColor() != this->color)
                schema.insert(schema.begin(),Location(location.row-1,location.column-2));

        }

        if (location.row+1 < ROWS){

            ptr = board.getPiece(location.row+1,location.column-2);

            if (ptr->getColor() != this->color)
                schema.insert(schema.begin(),Location(location.row+1,location.column-2));

        }

    }

    //adding rightward pair
    if (location.column+2 < COLUMNS) {

        if (location.row-1 >=0) {

            ptr = board.getPiece(location.row-1,location.column+2);

            if ( ptr->getColor() != this->color)
                schema.insert(schema.begin(),Location(location.row-1,location.column+2));

        }

        if (location.row+1 < ROWS){

            ptr = board.getPiece(location.row+1,location.column+2);

            if (ptr->getColor() != this->color)
                schema.insert(schema.begin(),Location(location.row+1,location.column+2));

        }

    }

    return schema;

}
