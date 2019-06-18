//BoardNode.h
//Description: Defines nodes for the board graph
//Author: Zach Stoebner
//Created date: 6-12-19
//Copyright © 2019
// Created by Zachary Stoebner on 2019-06-12.
//

#ifndef CHESS_BOARDNODE_H
#define CHESS_BOARDNODE_H

#include <cstdlib>
#include <tuple>
#include <memory>
#include "Piece.h"
#include "ChessData.h"

typedef Piece* PcPtr;

//discrete enum for tile color

class BoardNode {

private:

    //Node's representative tile color
    TileColor tileColor;

    Location location;

    PcPtr piece;

public:

    typedef std::shared_ptr<BoardNode> NodePtr;
    typedef std::weak_ptr<BoardNode> weakPtr;

    /*
     * default constructor
     * initializes BoardNode fields
     * post: BoardNode constructed
     */
    BoardNode(TileColor color, size_t rw, size_t cl, PcPtr newPiece);

    /*
     * copy constructor
     * copies
     * pre: BoardNode obj passed
     * post: BoardNode initialized to passed BoardNode's fields
     */
    BoardNode(const BoardNode& rhs);

    /*
     * destructor
     * deletes BoardNode without memory leaks
     * pre: BoardNode exists
     * post: all fields deleted, no memory leaks
     */
    ~BoardNode();

    /*
     * copy assignment operator
     * pre: BoardNode exists and BoardNode passed
     * post:
     */
    const BoardNode & operator=(const BoardNode& rhs);

    /*
     * setColor
     * sets TileColor
     * pre: BoardNode exists
     * post: BoardNode's TileColor field set to passed value
     */
    void setColor(TileColor newColor);

    /*
     * setLocation
     * sets row and column of BoardNode
     * pre: BoardNode exists
     * post: Location field set
     */
    void setLocation(size_t r, size_t c);

    /*
     * setPiece
     * directs BoardNode's Piece pointer to passed Piece
     * pre: BoardNode exists, Piece arg passed
     * post: Piece pointer points to newPiece
     */
    void setPiece(PcPtr newPiece);

    /*
     * getColor
     * gets BoardNode's color
     * pre: BoardNode color exists and is set
     * post: TileColor returned
     */
    TileColor getColor() const;

    /*
     * getLocation
     * gets BoardNode's location
     * pre: BoardNode exists
     * post: tuple with row and column returned
     */
    const std::tuple<size_t,size_t> getLocation() const;

    /*
     * getPiece
     * gets BoardNode's Piece
     * pre: BoardNode exists
     * post: const Piece ptr to BoardNode's piece
     */
    const Piece* getPiece() const;

    /*
     * connect
     * connects node to other nodes
     * pre: both BoardNodes exist
     * post: connected in specified manner
     */
    void connect(const NodePtr& up = nullptr, const NodePtr& down = nullptr,
            const NodePtr& left = nullptr, const NodePtr& right = nullptr);

private:
    weakPtr up,down,left,right;
};


#endif //CHESS_BOARDNODE_H
