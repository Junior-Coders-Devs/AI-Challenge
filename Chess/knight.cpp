#include "knight.h"


/**
 @inheritdoc
*/


Knight::Knight(int row, int column) : Piece(row, column) {

}


void Knight::makeMove(int diffRow, int diffColumn) {


    bool valid = this->isValidMove(diffRow, diffColumn) & this->isJump(diffRow, diffColumn);

    if(valid)
    {
        int currentRow = this->getRow(), currentColumn = this->getColumn();

        this->setRow(currentRow + diffRow);
        this->setColumn(currentColumn + diffColumn);

    }

}

bool Knight::isJump(int diffRow, int diffColumn)
{
    bool ok = 0;

    std::vector <MoveBy> moves = this->moves;

    MoveBy currentMove = {diffRow, diffColumn};

    for(auto i : moves)
        ok |= (i == currentMove);

    return ok;
}
