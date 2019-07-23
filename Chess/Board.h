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
#include <set>


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

    /*
     * underAttack
     * generates the set of all tiles under attack
     * pre: board exists, pieces are placed
     * post: set of all tiles within sight
     */
    std::set<Location> underAttackBy(PieceColor color) const;

    /*
     * sight
     * methods to get individual movement schemas for pieces
     * pre: pieces are placed
     * post: schemas are returned
     */
    std::set<Location> kingSight(Location location, PieceColor color) const;
    std::set<Location> queenSight(Location location, PieceColor color) const;
    std::set<Location> bishopSight(Location location, PieceColor color) const;
    std::set<Location> knightSight(Location location, PieceColor color) const;
    std::set<Location> rookSight(Location location, PieceColor color) const;
    std::set<Location> pawnSight(Location location, PieceColor color) const;

    /*
     * castle
     * checks if possible castle
     * pre: Board is set
     * post: return bool if King and Rook haven't moved and no impeding pieces and no checks
     */
    bool castle(Location location, PieceColor color) const;

    /*
     * enPassant
     * checks for potential en passant
     * pre: board is set, piece is pawn
     * post: bool returned if pawn can perform en passant
     */
    bool enPassant(Location location, PieceColor color) const;

    /*
    * creates a movement schema for King
    * pre: Piece is King
    * post: set of possible movement Locations returned
    */
    std::set<Location> kingAvailableMoves(Location location,
            PieceColor color ,const std::set<Location>& checks) const;

    /*
     * addLocation
     * adds location to set, wrapped in for loop in sight method
     * pre: sight() is called
     * post: location added and current Piece count in given direction returned
     */
    void addLocation(std::set<Location>& curSet,size_t& curPcCount,
                     size_t row, size_t col) const;

};


#endif //CHESS_BOARD_H
