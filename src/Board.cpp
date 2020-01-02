//
// Created by Zachary Stoebner on 1/1/20.
//

#include "Board.h"
#include "King.h"
#include "Knight.h"
#include "Queen.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Rook.h"

Board::Board() : ROWS(8),COLUMNS(8),board(ROWS,std::vector<std::shared_ptr<Piece>>(COLUMNS,nullptr)), pieces(),checkmate(false){

    try {

        for (int j = 0; j < COLUMNS; ++j) {

            //placing pawns
            board[1][j] = std::make_shared<Pawn>(COLOR::WHITE,1,j);
            board[ROWS-1][j] = std::make_shared<Pawn>(COLOR::BLACK,ROWS-2,j);
            pieces.push_back(board[1][j]);
            pieces.push_back(board[ROWS-1][j]);

            switch (j) {

                case 0:
                    board[0][j] = std::make_shared<Rook>(COLOR::WHITE,0,j);
                    board[ROWS-1][j] = std::make_shared<Rook>(COLOR::BLACK,ROWS-1,j);
                case 1:
                    board[0][j] = std::make_shared<Knight>(COLOR::WHITE,0,j);
                    board[ROWS-1][j] = std::make_shared<Knight>(COLOR::BLACK,ROWS-1,j);
                case 2:
                    board[0][j] = std::make_shared<Bishop>(COLOR::WHITE,0,j);
                    board[ROWS-1][j] = std::make_shared<Bishop>(COLOR::BLACK,ROWS-1,j);
                case 3:
                    board[0][j] = std::make_shared<Queen>(COLOR::WHITE,0,j);
                    board[ROWS-1][j] = std::make_shared<Queen>(COLOR::BLACK,ROWS-1,j);
                case 4:
                    board[0][j] = std::make_shared<King>(COLOR::WHITE,0,j);
                    board[ROWS-1][j] = std::make_shared<King>(COLOR::BLACK,ROWS-1,j);
                case 5:
                    board[0][j] = std::make_shared<Bishop>(COLOR::WHITE,0,j);
                    board[ROWS-1][j] = std::make_shared<Bishop>(COLOR::BLACK,ROWS-1,j);
                case 6:
                    board[0][j] = std::make_shared<Knight>(COLOR::WHITE,0,j);
                    board[ROWS-1][j] = std::make_shared<Knight>(COLOR::BLACK,ROWS-1,j);
                case 7:
                    board[0][j] = std::make_shared<Rook>(COLOR::WHITE,0,j);
                    board[ROWS-1][j] = std::make_shared<Rook>(COLOR::BLACK,ROWS-1,j);

            }
            pieces.push_back(board[0][j]);
            pieces.push_back(board[ROWS-1][j]);

        }

    } catch (const std::exception& e) {

        throw e;
    }
}

Board* Board::instance() {
    if (theBoard == nullptr) {
        theBoard = new Board();
    }
    return theBoard;
}

void Board::notify() {

    try {
        for (auto& piece : pieces) {
            piece->handleEvent(this);
        }
    } catch (const std::exception& e) {
        throw e;
    }
}

bool Board::movePiece(Piece piece, Location& end) {

    const uint32_t i(end.getRow());
    const uint32_t j(end.getColumn());
    const Location prev(piece.getLocation());

    if (piece.canMove(end)) {

        if (board[i][j] == nullptr) {
            /// COMPLETE THIS METHOD
        }

        return true;
    }

    return false;

}
