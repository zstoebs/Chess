//Piece.h
//Description: Creates a parent class for board pieces
//Author: Zach Stoebner
//Created date: 6-12-19
//Copyright © 2019
// Created by Zachary Stoebner on 2019-06-12.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <cstdlib>
#include <tuple>
#include <set>
#include "ChessData.h"



class Piece {

protected:

    //true if in sight of another piece
    bool threatened;

    //color of piece
    PieceColor color;

    //type of piece
    PieceType pieceType;

    //location of piece
    Location location;

    //move count
    size_t moveCount = 0;


public:

    Piece(PieceColor pieceColor, PieceType type, size_t row, size_t col) : threatened(false),
                                                            color(pieceColor),pieceType(type),
                                                            location(row,col) {}

    /*
     * Piece destructor
     */
    virtual ~Piece() = default;

    /*
     * sets threat of Piece
     */
    virtual void setThreat(bool threat) {

        threatened = threat;

    }

    /*
     * getter for threatened field
     */
    virtual bool isThreatened() const {

        return threatened;

    }

    /*
     * setter for PieceColor field
     */
    virtual void setColor(PieceColor pieceColor) {

        color = pieceColor;

    }

    /*
     * gets the Piece's color
     */
    virtual PieceColor getColor() {

        return color;

    }

    /*
     * gets Piece's type
     */
    virtual PieceType getPieceType() {

        return pieceType;

    }

    /*
     * set Piece's location
     */
    virtual void setLocation(size_t r, size_t c) {

        location = Location(r,c);

    }

    /*
     * get Piece's location
     */
    virtual std::tuple<size_t, size_t> getLocation() const {

        return std::tuple<size_t,size_t>(location.row,location.column);

    }

    /*
     * changes piece's location to given coords
     */

    virtual void move(size_t row, size_t col) {

        location.row = row;
        location.column = col;

    }

    virtual void incrementMoveCount() {

        ++moveCount;

    }

    virtual size_t getMoveCount() {

        return moveCount;

    }


};


#endif //CHESS_PIECE_H
