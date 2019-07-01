//Board.cpp
//Description: Defines a board (graph) that connects tiles (BoardNodes) into an 8x8 board
//Author: Zach Stoebner
//Created date: 6-12-19
//Copyright © 2019
// Created by Zachary Stoebner on 2019-06-12.
//

#include "Board.h"
#include "BoardNode.h"
#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"
#include <cstdlib>
#include <memory>
#include <cassert>

///PRIVATE FUNCTIONS
/*
* connectBoard
* connects all tiles on board
* pre: Board exists
* post: all nodes correctly connected if valid connection
*/
void Board::connectTiles() {

    //connecting all the tiles (BoardNode copy constructor doesn't copy pointers)
    for (size_t i = 0; i < ROWS; ++i) {
        for (size_t j = 0; j < COLUMNS; ++j) {

            //connecting all ups
            if (i > 0) {

                board[i][j]->connect(board[i-1][j]);

            }

            //connecting all downs
            if (i < (ROWS - 1)) {

                board[i][j]->connect(nullptr,board[i+1][j]);

            }

            //connecting all lefts
            if (j > 0) {

                board[i][j]->connect(nullptr,nullptr,board[i][j-1]);

            }

            //connecting all rights
            if (j < (COLUMNS - 1)) {

                board[i][j]->connect(nullptr,nullptr,nullptr,board[i][j+1]);

            }

        }

    }

}

/*
* placePieces
* places pieces in appropriate spaces
* pre: Board created and Pieces defined
* post: all approp. BoardNodes point to correct Pieces
*/
void Board::placePieces() {

    for (size_t j = 0; j < COLUMNS; ++j) {

        //placing pawns
        board[1][j]->setPiece(new Pawn(WHITE,1,j));
        board[ROWS-1][j]->setPiece(new Pawn(BLACK,ROWS-2,j));

        ///I know I'm hardcoding here
        switch (j) {

            case 0:
                board[0][j]->setPiece(new Rook(WHITE,0,j));
                board[ROWS-1][j]->setPiece(new Rook(BLACK,ROWS-1,j));
            case 1:
                board[0][j]->setPiece(new Knight(WHITE,0,j));
                board[ROWS-1][j]->setPiece(new Knight(BLACK,ROWS-1,j));
            case 2:
                board[0][j]->setPiece(new Bishop(WHITE,0,j));
                board[ROWS-1][j]->setPiece(new Bishop(BLACK,ROWS-1,j));
            case 3:
                board[0][j]->setPiece(new Queen(WHITE,0,j));
                board[ROWS-1][j]->setPiece(new Queen(BLACK,ROWS-1,j));
            case 4:
                board[0][j]->setPiece(new King(WHITE,0,j));
                board[ROWS-1][j]->setPiece(new King(BLACK,ROWS-1,j));
            case 5:
                board[0][j]->setPiece(new Bishop(WHITE,0,j));
                board[ROWS-1][j]->setPiece(new Bishop(BLACK,ROWS-1,j));
            case 6:
                board[0][j]->setPiece(new Knight(WHITE,0,j));
                board[ROWS-1][j]->setPiece(new Knight(BLACK,ROWS-1,j));
            case 7:
                board[0][j]->setPiece(new Rook(WHITE,0,j));
                board[ROWS-1][j]->setPiece(new Rook(BLACK,ROWS-1,j));


        }

    }


}

///PUBLIC FUNCTIONS
/*
* constructor
* initializes empty board
* post: all indices set to nullptr
*/
Board::Board() {

    //filling board matrix with nodes
    for(size_t i = 0; i < ROWS; ++i) {
        for(size_t j = 0; j < COLUMNS; ++j) {

            //odd rows
            if (i % 2 == 0) {

                switch(j % 2) {

                    case 0:
                        board[i][j] = std::make_shared<BoardNode>(BoardNode(W,i+1,j+1,nullptr));
                    default:
                        board[i][j] = std::make_shared<BoardNode>(BoardNode(B,i+1,j+1,nullptr));

                }

            } else {

                switch(j % 2) {

                    case 0:
                        board[i][j] = std::make_shared<BoardNode>(BoardNode(B,i+1,j+1,nullptr));
                    default:
                        board[i][j] = std::make_shared<BoardNode>(BoardNode(W,i+1,j+1,nullptr));

                }

            }

        }

    }

}

/*
* copy constructor
*/
Board::Board(const Board& rhs) {

    for (size_t i = 0; i < ROWS; ++i) {
        for (size_t j = 0; j < COLUMNS; ++j) {

            board[i][j] = std::make_shared<BoardNode>(BoardNode(*rhs.board[i][j]));

        }
    }

    connectTiles();

}

/*
 * destructor
 */
Board::~Board() {

    for (size_t i = 0; i < ROWS; ++i) {
        for (size_t j = 0; j < COLUMNS; ++j) {

                board[i][j].reset();

        }
    }

}

/*
 * copy assignment operator
 */
const Board & Board::operator=(const Board& rhs) {

    if (this != &rhs) {

        Board tmp(rhs);
        std::swap(board,tmp.board);

    }

    return *this;

}

/*
* setBoard
* creates an 8x8 board and places all pieces
* pre: board object created
* post: all BoardNodes added and pieces set
*/
void Board::resetBoard() {


    for (size_t i = 0; i < ROWS; ++i) {
        for (size_t j = 0; j < COLUMNS; ++j) {

            delete board[i][j]->getPiece();

        }

    }

    placePieces();

}

/*
* hasPiece
* pre: BoardNode at index exists, params must be between 0 and ROWS-1 || COLUMNS-1
* post: returns true if PcPtr is not nullptr, else false
*/
bool Board::hasPiece(size_t row, size_t col) const {

    assert(row < ROWS && col < COLUMNS);

    return board[row][col]->getPiece();
}

/*
     * getPiece
     * gets Piece at given tile
     * pre: BoardNode exists
     * post: returns a const ptr to Piece or nullptr
     */
const PcPtr Board::getPiece(size_t row, size_t col) const {

    assert(row < ROWS && col < COLUMNS);

    return board[row][col]->getPiece();

}