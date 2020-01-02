//
// Created by Zachary Stoebner on 1/1/20.
//

#include "Board.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

Board::Board()
    : ROWS(8), COLUMNS(8),
      board(ROWS, std::vector<std::shared_ptr<Piece>>(COLUMNS, nullptr)),
      pieces(), taken(), checkmate(false) {

  try {

    for (int j = 0; j < COLUMNS; ++j) {

      // placing pawns
      board[1][j] = std::make_shared<Pawn>(COLOR::WHITE, 1, j);
      board[ROWS - 1][j] = std::make_shared<Pawn>(COLOR::BLACK, ROWS - 2, j);
      pieces.push_back(board[1][j]);
      pieces.push_back(board[ROWS - 1][j]);

      switch (j) {

      case 0:
        board[0][j] = std::make_shared<Rook>(COLOR::WHITE, 0, j);
        board[ROWS - 1][j] = std::make_shared<Rook>(COLOR::BLACK, ROWS - 1, j);
      case 1:
        board[0][j] = std::make_shared<Knight>(COLOR::WHITE, 0, j);
        board[ROWS - 1][j] =
            std::make_shared<Knight>(COLOR::BLACK, ROWS - 1, j);
      case 2:
        board[0][j] = std::make_shared<Bishop>(COLOR::WHITE, 0, j);
        board[ROWS - 1][j] =
            std::make_shared<Bishop>(COLOR::BLACK, ROWS - 1, j);
      case 3:
        board[0][j] = std::make_shared<Queen>(COLOR::WHITE, 0, j);
        board[ROWS - 1][j] = std::make_shared<Queen>(COLOR::BLACK, ROWS - 1, j);
      case 4:
        board[0][j] = std::make_shared<King>(COLOR::WHITE, 0, j);
        board[ROWS - 1][j] = std::make_shared<King>(COLOR::BLACK, ROWS - 1, j);
      case 5:
        board[0][j] = std::make_shared<Bishop>(COLOR::WHITE, 0, j);
        board[ROWS - 1][j] =
            std::make_shared<Bishop>(COLOR::BLACK, ROWS - 1, j);
      case 6:
        board[0][j] = std::make_shared<Knight>(COLOR::WHITE, 0, j);
        board[ROWS - 1][j] =
            std::make_shared<Knight>(COLOR::BLACK, ROWS - 1, j);
      case 7:
        board[0][j] = std::make_shared<Rook>(COLOR::WHITE, 0, j);
        board[ROWS - 1][j] = std::make_shared<Rook>(COLOR::BLACK, ROWS - 1, j);
      }
      pieces.push_back(board[0][j]);
      pieces.push_back(board[ROWS - 1][j]);
    }

  } catch (const std::exception &e) {

    throw e;
  }
}

Board *Board::instance() {
  if (theBoard == nullptr) {
    theBoard = new Board();
  }
  return theBoard;
}

void Board::notify() {

  try {
    for (auto &piece : pieces) {
      piece->handleEvent(this);
    }
  } catch (const std::exception &e) {
    throw e;
  }
}

std::weak_ptr<Piece> Board::access(Location loc) const {
  return std::weak_ptr<Piece>(board[loc.getRow()][loc.getColumn()]);
}

bool Board::movePiece(Piece piece, Location &end) {

  const uint32_t i(end.getRow());
  const uint32_t j(end.getColumn());
  const Location prev(piece.getLocation());

  if (piece.canMove(end)) {

    std::shared_ptr<Piece> takesPiece = nullptr;

    // thankfully shared_ptr swaps are noexcept
    board[i][j].swap(takesPiece);
    board[i][j].swap(board[prev.getRow()][prev.getColumn()]);

    // telling the piece to move
    if (!piece.move(this, end)) {

      // undo swaps
      board[i][j].swap(board[prev.getRow()][prev.getColumn()]);
      board[i][j].swap(takesPiece);
      return false;
    }

    if (takesPiece != nullptr) {
      auto tmpPieces(pieces);
      auto iter(tmpPieces.begin());
      for (; iter != tmpPieces.end() && *iter != takesPiece; ++iter) {
      }

      if (iter != tmpPieces.end())
        tmpPieces.erase(iter);

      // moving taken piece to taken set
      taken.push_back(takesPiece);

      // swapping new pieces set with old
      pieces.swap(tmpPieces);
    }

    return true;
  }

  return false;
}
