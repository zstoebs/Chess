//Board.h
//Description: Declares a board (graph) that connects tiles (BoardNodes) into an 8x8 board
//Author: Zach Stoebner
//Created date: 6-12-19
//Copyright © 2019
// Created by Zachary Stoebner on 2019-06-12.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "BoardNode.h"
#include "Piece.h"
#include <cstdlib>
#include <memory>


class Board {

public:

    /*
     * constructor
     * initializes empty board
     * post: all indices set to nullptr
     */
    Board();

    /*
     * copy constructor
     */
    Board(const Board& rhs);

    /*
     * destructor
     */
    ~Board();

    /*
     * copy assignment operator
     */
    const Board & operator=(const Board& rhs);

    /*
     * resetBoard
     * creates an 8x8 board and places all pieces
     * pre: board object created
     * post: all BoardNodes added and pieces set
     */
    void resetBoard();

    /*
     * hasPiece
     * pre: BoardNode at index exists
     * post: returns true if PcPtr is not nullptr, else false
     */
    bool hasPiece(size_t row, size_t col) const;

    /*
     * getPiece
     * gets Piece at given tile
     * pre: BoardNode exists
     * post: returns a const ptr to Piece or nullptr
     */
    const PcPtr getPiece(size_t row, size_t col) const;

private:

    //matrix to hold BoardNodes
    BoardNode::NodePtr board[ROWS][COLUMNS];

    /*
     * connectBoard
     * connects all tiles on board
     * pre: Board exists
     * post: all nodes correctly connected if valid connection
     */
    void connectTiles();

    /*
     * placePieces
     * places pieces in appropriate spaces
     * pre: Board created and Pieces defined
     * post: all approp. BoardNodes point to correct Pieces
     */
    void placePieces();

};


#endif //CHESS_BOARD_H
