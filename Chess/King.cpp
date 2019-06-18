//King.h
//Description: Extends Piece to King subclass
//Author: Zach Stoebner
//Created date: 6-12-19
// Created by Zachary Stoebner on 2019-06-12.
//

#include "King.h"

///PUBLIC FUNCTIONS
/*
* default constructor
* post: King is initialized
*/
King::King(PieceColor pieceColor, size_t row, size_t col) : Piece(pieceColor,KING,row,col) {}

/*
 * gets sight schema for Piece
 */
std::set<Location> King::sight() const {

    std::set<Location> schema;
    Location newLo;

    //down movement
    if (location.row < ROWS-1) {

        newLo = Location(location.row+1,location.column);

        schema.insert(schema.begin(),newLo);

        //down-left
        if (location.column > 0) {

            newLo = Location(location.row+1,location.column-1);
            schema.insert(schema.begin(),newLo);

        }

        //down-right
        if (location.column < COLUMNS-1) {

            newLo = Location(location.row+1,location.column+1);
            schema.insert(schema.begin(),newLo);

        }

    }

    //up movement
    if (location.row > 0) {

        newLo = Location(location.row-1,location.column);
        schema.insert(schema.begin(),newLo);
        //up-left
        if (location.column > 0) {

            newLo = Location(location.row-1,location.column-1);
            schema.insert(schema.begin(),newLo);

        }

        //up-right
        if (location.column < COLUMNS-1) {

            newLo = Location(location.row-1,location.column+1);
            schema.insert(schema.begin(),newLo);

        }

    }

    //right movement
    if (location.column < COLUMNS-1) {

        newLo = Location(location.row,location.column+1);
        schema.insert(schema.begin(),newLo);

    }

    //left movement
    if (location.column > 0) {

        newLo = Location(location.row,location.column-1);
        schema.insert(schema.begin(),newLo);

    }

    return schema;

}

/*
* creates a movement schema for Piece
* pre: Piece is King
* post: set of possible movement Locations returned
*/
std::set<Location> King::availableMoves(const std::set<Location>& checks) {


    std::set<Location> inSight = sight();

    //getting the intersection of the two sets
    std::set<Location> shared;
    std::set_intersection(inSight.begin(),inSight.end(),checks.begin(),
            checks.end(),std::inserter(shared,shared.begin()));

    std::set<Location>::iterator iter;
    for (iter = shared.begin(); iter != shared.end(); ++iter) {

        if (inSight.count(*iter) != 0) {

            inSight.erase(*iter);

        }

    }

    return inSight;

}


