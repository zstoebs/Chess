//BoardNode.cpp
//Description: Defines nodes for the board graph
//Author: Zach Stoebner
//Created date: 6-12-19
//Copyright © 2019
// Created by Zachary Stoebner on 2019-06-12.
//

#include "BoardNode.h"
#include <cstdlib>
#include <cstddef>
#include <memory>
#include "Piece.h"

/*
* default constructor
* initializes BoardNode fields
* post: BoardNode constructed
*/
BoardNode::BoardNode(TileColor color, size_t rw,
        size_t cl,PcPtr newPiece) : tileColor(color),location(rw,cl), piece(newPiece)
{} //nothing left to do

/*
 * copy constructor
 * copies passed BoardNode
 * pre: BoardNode obj passed
 * post: BoardNode initialized to passed BoardNode's fields
 */
BoardNode::BoardNode(const BoardNode& rhs) : tileColor(rhs.tileColor),
location(rhs.location.row,rhs.location.column), piece(rhs.piece),
up(rhs.up),down(rhs.down),left(rhs.left),right(rhs.right)
{} //nothing left to do

/*
 * destructor
 * deletes BoardNode without memory leaks
 * pre: BoardNode exists
 * post: all fields deleted, no memory leaks (using smart pointers)
 */
BoardNode::~BoardNode() {

    //deleting shared ptrs
    up.reset();
    down.reset();
    left.reset();
    right.reset();

    delete piece;
    piece = nullptr;


}

/*
 * copy assignment operator
 * pre: BoardNode exists and BoardNode passed
 * post:
 */
const BoardNode & BoardNode::operator=(const BoardNode& rhs) {

    if (this != &rhs) {

        BoardNode tmp(rhs);

        std::swap(tileColor,tmp.tileColor);
        std::swap(location.row,tmp.location.row);
        std::swap(location.column,tmp.location.column);
        std::swap(piece,tmp.piece);

    }

    return *this;

}

/*
 * setColor
 * sets TileColor
 * pre: BoardNode exists
 * post: BoardNode's TileColor field set to passed value
 */
void BoardNode::setColor(TileColor newColor) {

    tileColor = newColor;

}

/*
 * setLocation
 * sets row and column of BoardNode
 * pre: BoardNode exists
 * post: Location field set
 */
void BoardNode::setLocation(size_t r, size_t c) {

    location.row = r;
    location.column = c;
}

/*
 * setPiece
 * directs BoardNode's Piece pointer to passed Piece
 * pre: BoardNode exists, Piece arg passed
 * post: Piece pointer points to newPiece
 */
void BoardNode::setPiece(PcPtr newPiece) {

    piece = newPiece;

}

/*
 * getColor
 * gets BoardNode's color
 * pre: BoardNode color exists and is set
 * post: TileColor returned
 */
TileColor BoardNode::getColor() const {

    return tileColor;

}

/*
 * getLocation
 * gets BoardNode's location
 * pre: BoardNode exists
 * post: tuple with row and column returned
 */
Location BoardNode::getLocation() const {

    return Location(location.row,location.column);

}

/*
 * getPiece
 * gets BoardNode's Piece
 * pre: BoardNode exists
 * post: const Piece ptr to BoardNode's piece
 */
const PcPtr BoardNode::getPiece() const {

    return piece;

}

/*
 * connect
 * connects node to other nodes
 * pre: both BoardNodes exist
 * post: connected in specified manner, no malloc
 */
void BoardNode::connect(const NodePtr& up, const NodePtr& down,
                        const NodePtr& left, const NodePtr& right) {

    this->up = up;
    this->down = down;
    this->left = left;
    this->right = right;

}