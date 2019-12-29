//Piece.h
//Description: Creates a parent class for board pieces
//Author: Zach Stoebner
//Created date: 6-12-19
//Copyright © 2019
// Created by Zachary Stoebner on 2019-06-12.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <cstdint>
#include "Location.h"

class Piece {

public:

    enum PieceColor {WHITE,BLACK};

protected:

    //true if in sight of another piece
    bool threatened;

    //color of piece --> false = white, true = black
    enum PieceColor color;

    //location of piece
    Location location;

    //move count
    u_int32_t moveCount;


public:

    Piece(PieceColor pieceColor, u_int32_t row, u_int32_t col) : threatened(false),
                                                            color(pieceColor),
                                                            location(row,col) {}

    /*
     * Piece destructor
     */
    virtual ~Piece() = default;

    /*
     * sets threat of Piece
     */
    virtual void threat() {

        threatened = !threatened;

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
     * get Piece's location
     */
    virtual const Location& getLocation() const {

        return location;

    }

    /*
     * changes piece's location to given coords
     */

    virtual void move(u_int32_t row, u_int32_t col) {

        location = Location(row,col);

    }

    virtual void incrementMoveCount() {

        ++moveCount;

    }

    virtual u_int32_t getMoveCount() {

        return moveCount;

    }

    virtual bool canMove(Location end) = 0;


};


#endif //CHESS_PIECE_H
