//Board.cpp
//Description: Defines a board (graph) that connects tiles (BoardNodes) into an 8x8 board
//Author: Zach Stoebner
//Created date: 6-12-19
//Copyright © 2019
// Created by Zachary Stoebner on 2019-06-12.
//

#include "Board.h"
#include "BoardNode.h"
#include <cstdlib>
#include <memory>

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
void Board::placePieces() {}

///PUBLIC FUNCTIONS
/*
* constructor
* initializes empty board
* post: all indices set to nullptr
*/
Board::Board() {

    for (size_t i = 0; i < ROWS; ++i) {
        for (size_t j = 0; j < COLUMNS; ++j) {

            board[i][j] = nullptr;

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

    //reset
    delete this;

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

    placePieces();

}