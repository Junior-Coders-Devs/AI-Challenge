#include "rook.h"
#include "movevalidator.h"

Rook::Rook(int row, int column, Color color):Piece(row, column, color){}

/**
 @inheritdoc
*/
void Rook::makeMove(int diffRow, int diffColumn)
{

    setRow(this->row + diffRow);
    setColumn(this->column + diffColumn);

    numberofMoves++;

    int first = this->getFirstMoveTime();
    if(first == 0)
        this->setFirstMoveTime(numberofMoves);
}


bool Rook::isMoveLegal(int diffRow, int diffColumn)
{
    return (diffRow != 0 && diffColumn == 0) || (diffRow == 0 && diffColumn != 0);
}

bool Rook::isValidMove(int diffRow, int diffColumn)
{
    return Piece::isValidMove(diffRow, diffColumn) && this->isMoveLegal(diffRow, diffColumn);
}

PieceType Rook::getType() {
    return ROOK;
}
