//
// Created by Zachary Stoebner on 1/1/20.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <vector>
#include <memory>
#include "Piece.h"

class Board {

private:

    typedef Piece::PieceColor COLOR;

    Board();
    static Board* theBoard;

    int ROWS, COLUMNS;
    std::vector<std::vector<std::shared_ptr<Piece>>> board;
    std::vector<std::shared_ptr<Piece>> pieces;
    bool checkmate;

public:

    static Board* instance();
    void notify();
    bool movePiece(Piece piece, Location& end);

};

Board* Board::theBoard = nullptr;

#endif //CHESS_BOARD_H
