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
Queen::Queen(PieceColor pieceColor, size_t row, size_t col) : Piece(pieceColor,QUEEN,row,col) {}

/*
 * creates movement schema for Piece
 */
std::set<Location> Queen::sight(const Board& board) const {

    std::set<Location> schema;

    PcPtr ptr;
    size_t i; //row index
    size_t j; //column index
    size_t pieceCount; //one piece can be in sight in any given direction,
                        // but after that she's blind (helper function will return one
    //adding all downward tiles
    ///THINKING OF WAYS TO IMPLEMENT MOVEMENT WITH RECURSION
    for (i = location.row+1, pieceCount = 0; i < ROWS && pieceCount == 0; ++i) {

        ptr = board.getPiece(i, location.column);

        if (!ptr || ptr->getColor() != this->color) {

            addLocation(board,schema,pieceCount,i,location.column);

        }


    }

    //adding all upward tiles
    for (i = location.row-1, pieceCount = 0; i >= 0 && pieceCount == 0; ++i) {

        ptr = board.getPiece(i, location.column);

        if (!ptr || ptr->getColor() != this->color) {

            addLocation(board,schema,pieceCount,i,location.column);

        }

    }

    //adding all leftward tiles
    for (j = location.column-1, pieceCount = 0; j >= 0 && pieceCount == 0; ++j) {

        ptr = board.getPiece(location.row, j);

        if (!ptr || ptr->getColor() != this->color) {

            addLocation(board,schema,pieceCount,location.row,j);

        }

    }

    //adding all rightward tiles
    for (j = location.column+1, pieceCount = 0; j >= 0 && pieceCount == 0; ++j) {

        ptr = board.getPiece(location.row, j);

        if (!ptr || ptr->getColor() != this->color) {

            addLocation(board,schema,pieceCount,location.row,j);

        }

    }


    //adding all down-left diagonal tiles
    for (i = location.row+1, j = location.column-1, pieceCount = 0;
    i < ROWS && j >= 0 && pieceCount == 0; ++i, --j) {

        ptr = board.getPiece(i, j);

        if (!ptr || ptr->getColor() != this->color) {

            addLocation(board,schema,pieceCount,i,j);

        }

    }


    //adding all down-right diagonal tiles
    for (i = location.row+1, j = location.column+1, pieceCount = 0;
    i < ROWS && j < COLUMNS && pieceCount == 0; ++i, ++j) {

        ptr = board.getPiece(i, j);

        if (!ptr || ptr->getColor() != this->color) {

            addLocation(board,schema,pieceCount,i,j);

        }

    }

    //adding all up-left diagonal tiles
    for (i = location.row-1, j = location.column-1, pieceCount = 0;
         i >= 0 && j >= 0 && pieceCount == 0; --i, --j) {

        ptr = board.getPiece(i, j);

        if (!ptr || ptr->getColor() != this->color) {

            addLocation(board,schema,pieceCount,i,j);

        }

    }


    //adding all up-right diagonal tiles
    for (i = location.row-1, j = location.column+1, pieceCount = 0;
         i >= 0 && j < COLUMNS && pieceCount == 0; --i, ++j) {

        ptr = board.getPiece(i, j);

        if (!ptr || ptr->getColor() != this->color) {

            addLocation(board,schema,pieceCount,i,j);

        }

    }

    return schema;

}

/*
     * addLocation
     * adds location to set, wrapped in for loop in sight method
     * pre: sight() is called
     * post: location added and current Piece count in given direction returned
     */
void Queen::addLocation(const Board& b, std::set<Location>& curSet,
                            size_t& curPcCount, size_t row, size_t col) const {

    if (b.hasPiece(row,col)) {

        ++curPcCount;

    }

    if (curPcCount < 2) {

        curSet.insert(curSet.begin(),Location(row,col));

    }

}