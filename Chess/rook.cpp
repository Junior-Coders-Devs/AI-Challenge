#include "rook.h"

Rook::Rook(int row, int column):Piece(row, column){}

/**
 @inheritdoc
*/
void Rook::makeMove(int diffRow, int diffColumn)
{

    setRow(this->row + diffRow);
    setColumn(this->column + diffColumn);

}


bool Rook::isMoveLegal(int diffRow, int diffColumn)
{
    return (diffRow != 0 && diffColumn == 0) || (diffRow == 0 && diffColumn != 0);
}

bool Rook::isValidMove(int diffRow, int diffColumn)
{
    return Piece::isValidMove(diffRow, diffColumn) && this->isMoveLegal(diffRow, diffColumn);
}
