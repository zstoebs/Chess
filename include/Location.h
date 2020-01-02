//
// Created by Zachary Stoebner on 12/29/19.
//

#ifndef CHESS_LOCATION_H
#define CHESS_LOCATION_H

#include "cstdint"

class Location {
private:
  u_int32_t row;
  u_int32_t column;

public:
  Location() = delete;
  explicit Location(const Location &rhs) noexcept;
  explicit Location(u_int32_t row, u_int32_t col) noexcept;
  explicit Location(Location &&other) noexcept;

  Location &operator=(Location &&other) noexcept;
  const Location &operator=(const Location &rhs);
  bool operator==(const Location &rhs) const;
  bool operator!=(const Location &rhs) const;
  bool operator<(const Location &rhs) const;

  const u_int32_t &getRow() const;
  const u_int32_t &getColumn() const;
};

#endif // CHESS_LOCATION_H
