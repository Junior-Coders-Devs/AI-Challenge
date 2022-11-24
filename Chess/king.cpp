#include "king.h"

King::King(int row, int column):Piece(row,column) {}

/**
 @inheritdoc
*/
void King::makeMove(int diffRow, int diffColumn)
{
    if(!Piece::isValidMove(diffRow, diffColumn)) {
        return ;
    }

    if(!isMoveLegal(diffRow, diffColumn))
        return;

    setRow(this->row + diffRow);
    setColumn(this->column + diffColumn);
}


bool King::isMoveLegal(int diffRow, int diffColumn)
{

    return diffRow >= -1 && diffRow <= 1
        && diffColumn >= -1 && diffColumn <= 1
        && !(diffRow == 0 && diffColumn == 0);
}
