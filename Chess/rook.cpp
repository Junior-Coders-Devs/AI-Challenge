#include "rook.h"

Rook::Rook(int row, int column):Piece(row, column){}

/**
 @inheritdoc
*/
void Rook::makeMove(int diffRow, int diffColumn)
{
    if(!Piece::isValidMove(diffRow, diffColumn)) {
        return ;
    }

    if(!isMoveLegal(diffRow, diffColumn))
        return;

    setRow(this->row + diffRow);
    setColumn(this->column + diffColumn);
}


bool Rook::isMoveLegal(int diffRow, int diffColumn)
{
    return (diffRow != 0 && diffColumn == 0) || (diffRow == 0 && diffColumn != 0);
}
