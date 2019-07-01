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
Pawn::Pawn(PieceColor pieceColor, size_t row, size_t col) : Piece(pieceColor,PAWN,row,col),
                                                            justMoved2(false) {}

/*
 * creates movement schema for Piece
 */
std::set<Location> Pawn::sight(const Board& board) const {

    std::set<Location> schema;
    PcPtr ptr; //to check for piece color at diagonals

    if (color == WHITE && location.row < ROWS-1) {

        //getting forward tile
        if (!board.hasPiece(location.row+1,location.column)) {

                schema.insert(schema.begin(),Location(location.row+1,location.column));

            //adding initial 2-tile move possibility
            if (location.row == 1) {

                //two tile move
                if (!board.hasPiece(location.row+2,location.column)) {

                    schema.insert(schema.begin(),Location(location.row+2,location.column));

                }

            }

        }

        //adding diagonal locations if there is a piece to take
        if (location.column > 0) {

            ptr = board.getPiece(location.row+1,location.column-1);

            if ((ptr && ptr->getColor() != this->color) || enPassant(board)) {

                schema.insert(schema.begin(),Location(location.row+1,location.column-1));

            }

        }

        if (location.column < COLUMNS-1) {

            ptr = board.getPiece(location.row+1,location.column+1);

            if ((ptr && ptr->getColor() != this->color) || enPassant(board)) {

                schema.insert(schema.begin(),Location(location.row+1,location.column+1));

            }

        }


    }

    if (color == BLACK && location.row > 0) {

        //adding forward tile
        if (!board.hasPiece(location.row-1,location.column)) {

            schema.insert(schema.begin(),Location(location.row-1,location.column));

            //adding initial 2-tile move possibility
            if (location.row == ROWS-2) {

                //two tile move
                if (!board.hasPiece(location.row-2,location.column)) {

                    schema.insert(schema.begin(),Location(location.row-2,location.column));

                }

            }

        }

        //adding diagonal tiles if there is a piece to take
        if (location.column > 0) {

            ptr = board.getPiece(location.row-1,location.column-1);

            if ((ptr && ptr->getColor() != this->color) || enPassant(board)) {

                schema.insert(schema.begin(),Location(location.row-1,location.column-1));

            }

        }

        if (location.column < COLUMNS-1) {

            ptr = board.getPiece(location.row-1,location.column+1);

            if ((ptr && ptr->getColor() != this->color) || enPassant(board)) {

                schema.insert(schema.begin(),Location(location.row-1,location.column+1));

            }

        }

    }

    return schema;

}

/*
* checks if possible en passant
*/
bool Pawn ::enPassant(const Board& board) const {

    PcPtr ptr1 = board.getPiece(location.row,location.column-1);
    PcPtr ptr2 = board.getPiece(location.row,location.column+1);

    //ensuring within valid tile ranges
    if ((location.row == 3 || location.row == 4)
    && (location.column > 0 && location.column < COLUMNS-1)) {

        //returning white en passant
        if (color == WHITE && location.row == 4) {

            return
                    (ptr1 && ptr1->getColor() != this->color && ptr1->getMoveCount() == 1)
                    ||
                    (ptr2 && ptr2->getColor() != this->color && ptr2->getMoveCount() == 1);

        //returning black en passant
        } else if (color == BLACK && location.row == 3) {

            return
                    (ptr1 && ptr1->getColor() != this->color && ptr1->getMoveCount() == 1)
                    ||
                    (ptr2 && ptr2->getColor() != this->color && ptr2->getMoveCount() == 1);

        }

    }

    return false;

}

/*
 * changes field for a pawn that has just moved 2 tiles from start
 */
void Pawn::setJustMoved2(bool state) {

    justMoved2 = state;

}

/*
 * returns Boolean if pawn just moved 2 tiles from start
 */
bool Pawn::hasJustMoved2() const {

    return justMoved2;

}
