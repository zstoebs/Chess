//
// Created by Zachary Stoebner on 12/29/19.
//

#include "Location.h"

Location::Location(const Location& rhs) noexcept : row(rhs.row), column(rhs.column) {
}

Location::Location(u_int32_t row, u_int32_t col) noexcept : row(row), column(col) {}

const Location & Location::operator=(const Location& rhs) {

    if (this != &rhs) {

        row = rhs.row;
        column = rhs.column;

    }

    return *this;

}

Location::Location(Location&& other) noexcept {

    // pilfer
    row = other.row;
    column = other.column;

    // reset
    other.row = 0;
    other.column = 0;
}

Location& Location::operator=(Location&& other) noexcept {
    // pilfer
    row = other.row;
    column = other.column;

    // reset
    other.row = 0;
    other.column = 0;

    return *this;
}

//defining equalities for usage in containers
bool Location::operator==(const Location& rhs) const {

        return row == rhs.row && column == rhs.column;

}

bool Location::operator!=(const Location& rhs) const {
    return !operator==(rhs);
}

bool Location::operator<(const Location& rhs) const {
    return row < rhs.row || (row == rhs.row && column < rhs.column);
}

const u_int32_t& Location::getRow() const {
    return row;
}

const u_int32_t& Location::getColumn() const {
    return column;
}
