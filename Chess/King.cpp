//King.cpp
//Description: Extends Piece to King subclass
//Author: Zach Stoebner
//Created date: 6-12-19
// Created by Zachary Stoebner on 2019-06-12.
//

#include "King.h"

///PUBLIC FUNCTIONS
/*
* default constructor
* post: King is initialized
*/
King::King(PieceColor pieceColor, size_t row, size_t col) : Piece(pieceColor,KING,row,col) {}

/*
 * gets sight schema for Piece
 */
std::set<Location> King::sight(const Board& board) const {

    std::set<Location> schema;
    PcPtr ptr; //holds pointer for ensuring that candidate tile has no piece or opposing piece

    //down movement
    if (location.row < ROWS-1) {

        ptr = board.getPiece(location.row+1, location.column);

        if (!ptr || ptr->getColor() != this->color) {

            schema.insert(schema.begin(),Location(location.row+1,location.column));

        }

        //down-left
        if (location.column > 0) {

            ptr = board.getPiece(location.row+1, location.column-1);

            if (!ptr || ptr->getColor() != this->color) {

                schema.insert(schema.begin(),Location(location.row+1,location.column-1));

            }

        }

        //down-right
        if (location.column < COLUMNS-1) {

            ptr = board.getPiece(location.row+1, location.column+1);

            if (!ptr || ptr->getColor() != this->color) {

                schema.insert(schema.begin(),Location(location.row+1,location.column+1));

            }

        }

    }

    //up movement
    if (location.row > 0) {

        ptr = board.getPiece(location.row-1, location.column);

        if (!ptr || ptr->getColor() != this->color) {

            schema.insert(schema.begin(),Location(location.row-1,location.column));

        }

        //up-left
        if (location.column > 0) {

            ptr = board.getPiece(location.row-1, location.column-1);

            if (!ptr || ptr->getColor() != this->color) {

                schema.insert(schema.begin(),Location(location.row-1,location.column-1));

            }

        }

        //up-right
        if (location.column < COLUMNS-1) {

            ptr = board.getPiece(location.row-1, location.column+1);

            if (!ptr || ptr->getColor() != this->color) {

                schema.insert(schema.begin(),Location(location.row-1,location.column+1));

            }

        }

    }

    //right movement
    if (location.column < COLUMNS-1) {

        ptr = board.getPiece(location.row, location.column+1);

        if (!ptr || ptr->getColor() != this->color) {

            schema.insert(schema.begin(),Location(location.row,location.column+1));

        }

    }

    //left movement
    if (location.column > 0) {

        ptr = board.getPiece(location.row, location.column-1);

        if (!ptr || ptr->getColor() != this->color) {

            schema.insert(schema.begin(),Location(location.row,location.column-1));

        }

    }

    return schema;

}

/*
* creates a movement schema for Piece
* pre: Piece is King
* post: set of possible movement Locations returned
*/
std::set<Location> King::availableMoves(const Board& board, const std::set<Location>& checks) {


    std::set<Location> inSight = sight(board);

    //getting the intersection of the two sets
    std::set<Location> shared;
    std::set_intersection(inSight.begin(),inSight.end(),checks.begin(),
            checks.end(),std::inserter(shared,shared.begin()));

    //removing checked tiles from set
    std::set<Location>::iterator iter;
    for (iter = shared.begin(); iter != shared.end(); ++iter) {

        if (inSight.count(*iter) != 0) {

            inSight.erase(*iter);

        }

    }

    return inSight;

}

/*
     * castle
     * checks if possible castle for King
     * pre: Board is set
     * post: return bool if King and Rook haven't moved and no impeding pieces and no checks
     */
bool King::castle (const Board& board) const {

    ///review conditions for castling https://en.wikipedia.org/wiki/Castling



    return false;

}


