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
#include <set>
#include <stdexcept>
#include "Location.h"

class Board;

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

    /*
     * valid move set schema
     */
    std::set<Location> schema;

    /*
     * Updates valid move set
     */
    virtual std::set<Location> updateValidMoves(const Board*) = 0;


public:

    Piece(PieceColor pieceColor, u_int32_t row, u_int32_t col) : threatened(false),
                                                            color(pieceColor),
                                                            location(row,col),
                                                            moveCount(0),
                                                            schema()
    {}

    /*
     * Piece destructor
     */
    virtual ~Piece() = default;

    /*
     * sets threat of Piece
     */
    virtual void threat() noexcept {

        threatened = !threatened;

    }

    /*
     * getter for threatened field
     */
    virtual bool isThreatened() const noexcept {

        return threatened;

    }

    /*
     * setter for PieceColor field
     */
    virtual void setColor(PieceColor pieceColor) noexcept {

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
    virtual bool move(const Board* board, Location& end) {

        std::set<Location> moves;
        Location prev(location);

            location = end;

            try {
                moves = updateValidMoves(board);
                schema = moves;
            } catch (const std::exception &e) {
                location = prev;
                return false;
            }

            ++moveCount;
            return true;

    }

    virtual u_int32_t getMoveCount() noexcept {

        return moveCount;

    }

    virtual bool canMove(Location& end) {
        return schema.find(end) != schema.end();
    }

    virtual void handleEvent(const Board* board) {

        std::set<Location> moves;
        try {
            moves = updateValidMoves(board);
        } catch (const std::exception& e){
            throw e;
        }

        schema = moves;

    }

};


#endif //CHESS_PIECE_H
