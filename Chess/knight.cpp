#include "knight.h"
#include "movevalidator.h"

const std::vector<MoveBy> Knight::moves = Knight::initMoves();

const std::vector<MoveBy> Knight::initMoves() {

    MoveBy m1(1, 2), m2(1, -2), m3(-1, 2), m4(-1, -2), m5(2, 1), m6(2, -1), m7(-2, 1), m8(-2, -1);

    std::vector<MoveBy> knightMoves{m1, m2, m3, m4, m5, m6, m7, m8};

    return knightMoves;
}

Knight::Knight(int row, int column, Color color) : Piece(row, column, color) {}

/**
 @inheritdoc
*/
void Knight::makeMove(int diffRow, int diffColumn) {

    int currentRow = this->getRow();
    int currentColumn = this->getColumn();

    this->setRow(currentRow + diffRow);
    this->setColumn(currentColumn + diffColumn);
}

bool Knight::isMoveLegal(int diffRow, int diffColumn)
{
    MoveBy currentMove = {diffRow, diffColumn};

    for(auto _move : Knight::moves)
        if(_move == currentMove)
            return true;

    return false;
}

bool Knight::isValidMove(int diffRow, int diffColumn)
{
    return Piece::isValidMove(diffRow, diffColumn) && this->isMoveLegal(diffRow, diffColumn);
}

PieceType Knight::getType() {
    return KNIGHT;
}
