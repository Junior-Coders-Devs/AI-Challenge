#include "knight.h"

Knight::Knight(int row, int column) : Piece(row, column) {}

/**
 @inheritdoc
*/
void Knight::makeMove(int diffRow, int diffColumn) {

    bool valid = Piece::isValidMove(diffRow, diffColumn)
                && this->isJump(diffRow, diffColumn);

    if(!valid)
        return;

    int currentRow = this->getRow();
    int currentColumn = this->getColumn();

    this->setRow(currentRow + diffRow);
    this->setColumn(currentColumn + diffColumn);
}

bool Knight::isJump(int diffRow, int diffColumn)
{
    MoveBy currentMove = {diffRow, diffColumn};

    for(auto _move : this->moves)
        if(_move == currentMove)
            return true;

    return false;
}
