//
// Created by Zachary Stoebner on 2019-06-17.
//

#ifndef CHESS_CHESSDATA_H
#define CHESS_CHESSDATA_H

#include <cstdlib>

//location on board
struct Location {
    size_t row;
    size_t column;

    Location() : row(0), column(0) {}
    Location(size_t rw, size_t cl) : row(rw), column(cl) {}

    const Location & operator=(const Location& rhs) {

        if (this != &rhs) {

            row = rhs.row;
            column = rhs.column;

        }

        return *this;

    }

    //defining equalities for usage in containers
    bool operator==(const Location& rhs) const {

        if (this != &rhs) {

            return row == rhs.row && column == rhs.column;

        }

        return true;

    }

    bool operator!=(const Location& rhs) const {

        if (this != &rhs) {

            return row != rhs.row && column != rhs.column;

        }

        return false;

    }

    bool operator>(const Location& rhs) const {

        return (row > rhs.row) || (row == rhs.row && column > rhs.column);

    }

    bool operator<(const Location& rhs) const {

        return (row < rhs.row) || (row == rhs.row && column < rhs.column);

    }

};

const size_t ROWS = 8;
const size_t COLUMNS = 8;

enum PieceType{KING,QUEEN,BISHOP,KNIGHT,ROOK,PAWN};
enum PieceColor{WHITE,BLACK};

enum TileColor{W,B};

#endif //CHESS_CHESSDATA_H
