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

/*
     * underAttack
     * generates the set of all tiles under attack
     * pre: board exists, pieces are placed
     * post: set of all tiles within sight
     */
std::set<Location> Board::underAttackBy(PieceColor color) const {

    //set of all threatened locations
    std::set<Location> attacked;

    //looping through each position of board to add all attack schemas
    for (size_t i = 0 ; i < ROWS; ++i) {
        for (size_t j = 0; j < COLUMNS; ++j) {

            PcPtr ptr = getPiece(i,j);
            std::set<Location> curPieceSight;

            if (ptr && color) {

                switch (ptr->getPieceType()) {

                    case KING:
                        curPieceSight = kingSight(Location(i,j),ptr->getColor());
                    case QUEEN:
                        curPieceSight = queenSight(Location(i,j),ptr->getColor());
                    case BISHOP:
                        curPieceSight = bishopSight(Location(i,j),ptr->getColor());
                    case KNIGHT:
                        curPieceSight = knightSight(Location(i,j),ptr->getColor());
                    case ROOK:
                        curPieceSight = rookSight(Location(i,j),ptr->getColor());
                    case PAWN:
                        curPieceSight = pawnSight(Location(i,j),ptr->getColor());

                }

            }

            //adding all elements to set
            std::set_union(attacked.begin(),attacked.end(),curPieceSight.begin(),
                    curPieceSight.end(),std::inserter(attacked,attacked.begin()));

        }

    }

    return attacked;

}

///MOVEMENT METHODS FOR ALL PIECES
/*
     * sight
     * methods to get individual movement schemas for pieces
     * pre: pieces are placed
     * post: schemas are returned
     */
std::set<Location> Board::kingSight(Location location, PieceColor color) const {

    std::set<Location> schema;
    PcPtr ptr; //holds pointer for ensuring that candidate tile has no piece or opposing piece

    //down movement
    if (location.row < ROWS-1) {

        ptr = getPiece(location.row+1, location.column);

        if (!ptr || ptr->getColor() != color) {

            schema.insert(schema.begin(),Location(location.row+1,location.column));

        }

        //down-left
        if (location.column > 0) {

            ptr = getPiece(location.row+1, location.column-1);

            if (!ptr || ptr->getColor() != color) {

                schema.insert(schema.begin(),Location(location.row+1,location.column-1));

            }

        }

        //down-right
        if (location.column < COLUMNS-1) {

            ptr = getPiece(location.row+1, location.column+1);

            if (!ptr || ptr->getColor() != color) {

                schema.insert(schema.begin(),Location(location.row+1,location.column+1));

            }

        }

    }

    //up movement
    if (location.row > 0) {

        ptr = getPiece(location.row-1, location.column);

        if (!ptr || ptr->getColor() != color) {

            schema.insert(schema.begin(),Location(location.row-1,location.column));

        }

        //up-left
        if (location.column > 0) {

            ptr = getPiece(location.row-1, location.column-1);

            if (!ptr || ptr->getColor() != color) {

                schema.insert(schema.begin(),Location(location.row-1,location.column-1));

            }

        }

        //up-right
        if (location.column < COLUMNS-1) {

            ptr = getPiece(location.row-1, location.column+1);

            if (!ptr || ptr->getColor() != color) {

                schema.insert(schema.begin(),Location(location.row-1,location.column+1));

            }

        }

    }

    //right movement
    if (location.column < COLUMNS-1) {

        ptr = getPiece(location.row, location.column+1);

        if (!ptr || ptr->getColor() != color) {

            schema.insert(schema.begin(),Location(location.row,location.column+1));

        }

    }

    //left movement
    if (location.column > 0) {

        ptr = getPiece(location.row, location.column-1);

        if (!ptr || ptr->getColor() != color) {

            schema.insert(schema.begin(),Location(location.row,location.column-1));

        }

    }

    if (castle(Location(location.row,location.column-4),color)) {
        schema.insert(schema.begin(),Location(location.row,location.column-2));
    }

    if(castle(Location(location.row,location.column+3),color)) {
        schema.insert(schema.begin(),Location(location.row,location.column+2));
    }

    return schema;

}
std::set<Location> Board::queenSight(Location location, PieceColor color) const {

    std::set<Location> schema;

    PcPtr ptr;
    size_t i; //row index
    size_t j; //column index
    size_t pieceCount; //one piece can be in sight in any given direction,
    // but after that she's blind (helper function will return one
    //adding all downward tiles
    ///THINKING OF WAYS TO IMPLEMENT MOVEMENT WITH RECURSION
    for (i = location.row+1, pieceCount = 0; i < ROWS && pieceCount == 0; ++i) {

        ptr = getPiece(i, location.column);

        if (!ptr || ptr->getColor() != color) {

            addLocation(schema,pieceCount,i,location.column);

        }


    }

    //adding all upward tiles
    for (i = location.row-1, pieceCount = 0; i >= 0 && pieceCount == 0; ++i) {

        ptr = getPiece(i, location.column);

        if (!ptr || ptr->getColor() != color) {

            addLocation(schema,pieceCount,i,location.column);

        }

    }

    //adding all leftward tiles
    for (j = location.column-1, pieceCount = 0; j >= 0 && pieceCount == 0; ++j) {

        ptr = getPiece(location.row, j);

        if (!ptr || ptr->getColor() != color) {

            addLocation(schema,pieceCount,location.row,j);

        }

    }

    //adding all rightward tiles
    for (j = location.column+1, pieceCount = 0; j >= 0 && pieceCount == 0; ++j) {

        ptr = getPiece(location.row, j);

        if (!ptr || ptr->getColor() != color) {

            addLocation(schema,pieceCount,location.row,j);

        }

    }


    //adding all down-left diagonal tiles
    for (i = location.row+1, j = location.column-1, pieceCount = 0;
         i < ROWS && j >= 0 && pieceCount == 0; ++i, --j) {

        ptr = getPiece(i, j);

        if (!ptr || ptr->getColor() != color) {

            addLocation(schema,pieceCount,i,j);

        }

    }


    //adding all down-right diagonal tiles
    for (i = location.row+1, j = location.column+1, pieceCount = 0;
         i < ROWS && j < COLUMNS && pieceCount == 0; ++i, ++j) {

        ptr = getPiece(i, j);

        if (!ptr || ptr->getColor() != color) {

            addLocation(schema,pieceCount,i,j);

        }

    }

    //adding all up-left diagonal tiles
    for (i = location.row-1, j = location.column-1, pieceCount = 0;
         i >= 0 && j >= 0 && pieceCount == 0; --i, --j) {

        ptr = getPiece(i, j);

        if (!ptr || ptr->getColor() != color) {

            addLocation(schema,pieceCount,i,j);

        }

    }


    //adding all up-right diagonal tiles
    for (i = location.row-1, j = location.column+1, pieceCount = 0;
         i >= 0 && j < COLUMNS && pieceCount == 0; --i, ++j) {

        ptr = getPiece(i, j);

        if (!ptr || ptr->getColor() != color) {

            addLocation(schema,pieceCount,i,j);

        }

    }

    return schema;

}
std::set<Location> Board::bishopSight(Location location, PieceColor color) const {

    std::set<Location> schema;

    PcPtr ptr;
    size_t i; //row index
    size_t j; //column index
    size_t pieceCount; //one piece can be in sight in any given direction,
    // but after that she's blind (helper function will return one

    //adding all down-left diagonal tiles
    for (i = location.row+1, j = location.column-1, pieceCount = 0;
         i < ROWS && j >= 0 && pieceCount == 0; ++i, --j) {

        ptr = getPiece(i, j);

        if (!ptr || ptr->getColor() != color) {

            addLocation(schema,pieceCount,i,j);

        }

    }


    //adding all down-right diagonal tiles
    for (i = location.row+1, j = location.column+1, pieceCount = 0;
         i < ROWS && j < COLUMNS && pieceCount == 0; ++i, ++j) {

        ptr = getPiece(i, j);

        if (!ptr || ptr->getColor() != color) {

            addLocation(schema,pieceCount,i,j);

        }

    }

    //adding all up-left diagonal tiles
    for (i = location.row-1, j = location.column-1, pieceCount = 0;
         i >= 0 && j >= 0 && pieceCount == 0; --i, --j) {

        ptr = getPiece(i, j);

        if (!ptr || ptr->getColor() != color) {

            addLocation(schema,pieceCount,i,j);

        }

    }


    //adding all up-right diagonal tiles
    for (i = location.row-1, j = location.column+1, pieceCount = 0;
         i >= 0 && j < COLUMNS && pieceCount == 0; --i, ++j) {

        ptr = getPiece(i, j);

        if (!ptr || ptr->getColor() != color) {

            addLocation(schema,pieceCount,i,j);

        }

    }

    return schema;

}
std::set<Location> Board::knightSight(Location location, PieceColor color) const {

    std::set<Location> schema;
    PcPtr ptr; //to check piece color at a candidate location

    //adding downward pair
    if (location.row+2 < ROWS) {

        if (location.column-1 >=0) {

            ptr = getPiece(location.row+2,location.column-1);

            if ( ptr->getColor() != color)
                schema.insert(schema.begin(),Location(location.row+2,location.column-1));

        }

        if (location.column+1 < COLUMNS){

            ptr = getPiece(location.row+2,location.column+1);

            if (ptr->getColor() != color)
                schema.insert(schema.begin(),Location(location.row+2,location.column+1));

        }

    }

    //adding upward pair
    if (location.row-2 >=0) {

        if (location.column-1 >=0) {

            ptr = getPiece(location.row-2,location.column-1);

            if ( ptr->getColor() != color)
                schema.insert(schema.begin(),Location(location.row-2,location.column-1));

        }

        if (location.column+1 < COLUMNS){

            ptr = getPiece(location.row-2,location.column+1);

            if (ptr->getColor() != color)
                schema.insert(schema.begin(),Location(location.row-2,location.column+1));

        }

    }

    //adding leftward pair
    if (location.column-2 >=0) {

        if (location.row-1 >=0) {

            ptr = getPiece(location.row-1,location.column-2);

            if ( ptr->getColor() != color)
                schema.insert(schema.begin(),Location(location.row-1,location.column-2));

        }

        if (location.row+1 < ROWS){

            ptr = getPiece(location.row+1,location.column-2);

            if (ptr->getColor() != color)
                schema.insert(schema.begin(),Location(location.row+1,location.column-2));

        }

    }

    //adding rightward pair
    if (location.column+2 < COLUMNS) {

        if (location.row-1 >=0) {

            ptr = getPiece(location.row-1,location.column+2);

            if ( ptr->getColor() != color)
                schema.insert(schema.begin(),Location(location.row-1,location.column+2));

        }

        if (location.row+1 < ROWS){

            ptr = getPiece(location.row+1,location.column+2);

            if (ptr->getColor() != color)
                schema.insert(schema.begin(),Location(location.row+1,location.column+2));

        }

    }

    return schema;

}
std::set<Location> Board::rookSight(Location location, PieceColor color) const {

    std::set<Location> schema;

    PcPtr ptr;
    size_t i; //row index
    size_t j; //column index
    size_t pieceCount; //one piece can be in sight in any given direction,
    // but after that she's blind (helper function will return one

    //adding all downward tiles
    for (i = location.row+1, pieceCount = 0; i < ROWS && pieceCount == 0; ++i) {

        ptr = getPiece(i, location.column);

        if (!ptr || ptr->getColor() != color) {

            addLocation(schema,pieceCount,i,location.column);

        }


    }

    //adding all upward tiles
    for (i = location.row-1, pieceCount = 0; i >= 0 && pieceCount == 0; ++i) {

        ptr = getPiece(i, location.column);

        if (!ptr || ptr->getColor() != color) {

            addLocation(schema,pieceCount,i,location.column);

        }

    }

    //adding all leftward tiles
    for (j = location.column-1, pieceCount = 0; j >= 0 && pieceCount == 0; ++j) {

        ptr = getPiece(location.row, j);

        if (!ptr || ptr->getColor() != color) {

            addLocation(schema,pieceCount,location.row,j);

        }

    }

    //adding all rightward tiles
    for (j = location.column+1, pieceCount = 0; j >= 0 && pieceCount == 0; ++j) {

        ptr = getPiece(location.row, j);

        if (!ptr || ptr->getColor() != color) {

            addLocation(schema,pieceCount,location.row,j);

        }

    }

    if (location.column == 0 && castle(Location(location.row,location.column),color)) {
        schema.insert(schema.begin(),Location(location.row,location.column+3));
    }

    if (location.column == 8 && castle(Location(location.row,location.column),color)) {
        schema.insert(schema.begin(),Location(location.row,location.column-2));
    }

    return schema;

}
std::set<Location> Board::pawnSight(Location location, PieceColor color) const {

    std::set<Location> schema;
    PcPtr ptr; //to check for piece color at diagonals

    if (color == WHITE && location.row < ROWS-1) {

        //getting forward tile
        if (!hasPiece(location.row+1,location.column)) {

            schema.insert(schema.begin(),Location(location.row+1,location.column));

            //adding initial 2-tile move possibility
            if (location.row == 1) {

                //two tile move
                if (!hasPiece(location.row+2,location.column)) {

                    schema.insert(schema.begin(),Location(location.row+2,location.column));

                }

            }

        }

        //adding diagonal locations if there is a piece to take
        if (location.column > 0) {

            ptr = getPiece(location.row+1,location.column-1);

            if ((ptr && ptr->getColor() != color) || enPassant(location,color)) {

                schema.insert(schema.begin(),Location(location.row+1,location.column-1));

            }

        }

        if (location.column < COLUMNS-1) {

            ptr = getPiece(location.row+1,location.column+1);

            if ((ptr && ptr->getColor() != color) || enPassant(location,color)) {

                schema.insert(schema.begin(),Location(location.row+1,location.column+1));

            }

        }


    }

    if (color == BLACK && location.row > 0) {

        //adding forward tile
        if (!hasPiece(location.row-1,location.column)) {

            schema.insert(schema.begin(),Location(location.row-1,location.column));

            //adding initial 2-tile move possibility
            if (location.row == ROWS-2) {

                //two tile move
                if (!hasPiece(location.row-2,location.column)) {

                    schema.insert(schema.begin(),Location(location.row-2,location.column));

                }

            }

        }

        //adding diagonal tiles if there is a piece to take
        if (location.column > 0) {

            ptr = getPiece(location.row-1,location.column-1);

            if ((ptr && ptr->getColor() != color) || enPassant(location,color)) {

                schema.insert(schema.begin(),Location(location.row-1,location.column-1));

            }

        }

        if (location.column < COLUMNS-1) {

            ptr = getPiece(location.row-1,location.column+1);

            if ((ptr && ptr->getColor() != color) || enPassant(location,color)) {

                schema.insert(schema.begin(),Location(location.row-1,location.column+1));

            }

        }

    }

    return schema;

}

/*
     * castle
     * checks if possible castle
     * pre: Board is set, location given is that of a rook
     * post: return bool if King and Rook haven't moved and no impeding pieces and no checks
     */
bool Board::castle(Location location, PieceColor color) const {

    if ((location.row != 0 && location.row != ROWS-1)
    || (location.column != 0 && location.column != COLUMNS-1)) {
        return false;
    }

    PcPtr curPtr = getPiece(location.row,location.column);

    if (curPtr && curPtr->getPieceType() == ROOK && curPtr->getMoveCount() == 0) {

        std::set<Location> checks;

        //ensuring color positions are correct otherwise invalid castle
        if (location.row == ROWS-1) {

            if (color != BLACK) {
                return false;
            }
            checks = underAttackBy(WHITE);

        }

        if (location.row == 0) {

            if (color != WHITE) {
                return false;
            }
            checks = underAttackBy(BLACK);
        }

        //checking if impeding pieces
        for (size_t i = 1; i < 5; ++i) {

            //rook at A1 or A8
            if (location.column == 0) {

                //checking for threats to king
                if (i+2 < 4 && checks.find(Location(location.row,i+2)) != checks.end()) {

                    return false;

                }

                PcPtr ptr = getPiece(location.row, i);

                if (i == 4 && ptr && ptr->getPieceType() == KING
                && ptr->getMoveCount() == 0 && !ptr->isThreatened() && ptr->getColor() == color) {

                    return true;

                } else if (ptr) {

                    return false;

                }

                //rook at H1 or H8
            } else {

                //checking for threats to king
                if (i < 3
                && checks.find(Location(location.row,location.column-i)) != checks.end()) {

                    return false;

                }

                PcPtr ptr = getPiece(location.row, location.column - i);

                if (i == 3 && ptr && ptr->getPieceType() == KING
                && ptr->getMoveCount() == 0 && !ptr->isThreatened() && ptr->getColor() == color) {

                    return true;

                } else if (ptr || i > 3) {

                    return false;

                }

            }

        }

    }

    return false;

}

bool Board::enPassant(Location location, PieceColor color) const {

    PcPtr ptr1 = getPiece(location.row,location.column-1);
    PcPtr ptr2 = getPiece(location.row,location.column+1);

    //ensuring within valid tile ranges
    if ((location.row == 3 || location.row == 4)
        && (location.column >= 0 && location.column < COLUMNS-1)) {

        //returning white en passant
        if (color == WHITE && location.row == 4) {

            return
                    (ptr1 && ptr1->getColor() != color && ptr1->getMoveCount() == 1)
                    ||
                    (ptr2 && ptr2->getColor() != color && ptr2->getMoveCount() == 1);

            //returning black en passant
        } else if (color == BLACK && location.row == 3) {

            return
                    (ptr1 && ptr1->getColor() != color && ptr1->getMoveCount() == 1)
                    ||
                    (ptr2 && ptr2->getColor() != color && ptr2->getMoveCount() == 1);

        }

    }

    return false;

}

/*
* creates a movement schema for King
* pre: Piece is King
* post: set of possible movement Locations returned
*/
std::set<Location> Board::kingAvailableMoves(Location location,
                                             PieceColor color ,const std::set<Location>& checks) const {

    std::set<Location> inSight = kingSight(location,color);

    //getting the intersection of the two sets
    std::set<Location> shared;
    std::set_intersection(inSight.begin(),inSight.end(),checks.begin(),
                          checks.end(),std::inserter(shared,shared.begin()));

    //removing checked tiles from set
    std::set<Location>::iterator iter;
    for (iter = shared.begin(); iter != shared.end(); ++iter) {

        if (inSight.count(*iter) != 0) {

            inSight.erase(*iter);

        }

    }

    return inSight;

}

/*
    * addLocation
    * adds location to set, wrapped in for loop in sight method
    * pre: sight() is called
    * post: location added and current Piece count in given direction returned
    */
void Board::addLocation(std::set<Location>& curSet,size_t& curPcCount,
                        size_t row, size_t col) const {

    if (hasPiece(row,col)) {

        ++curPcCount;

    }

    if (curPcCount < 2) {

        curSet.insert(curSet.begin(),Location(row,col));

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

    placePieces();

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

