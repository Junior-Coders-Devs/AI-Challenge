#include "knight.h"
#include "movevalidator.h"

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

    for(auto _move : this->moves)
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
