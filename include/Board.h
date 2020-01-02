//
// Created by Zachary Stoebner on 1/1/20.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "Piece.h"
#include <memory>
#include <vector>

class Board {

private:
  typedef Piece::PieceColor COLOR;

  Board();
  static Board *theBoard;

  int ROWS, COLUMNS;
  std::vector<std::vector<std::shared_ptr<Piece>>> board;
  std::vector<std::shared_ptr<Piece>> pieces;
  std::vector<std::shared_ptr<Piece>> taken;
  bool checkmate;

public:
  static Board *instance();
  void notify();
  std::weak_ptr<Piece> access(Location loc) const;
  bool movePiece(Piece piece, Location &end);
};

Board *Board::theBoard = nullptr;

#endif // CHESS_BOARD_H
