#include "king.h"

King::King(int row, int column, Color color):Piece(row,column, color, "K") {}

/**
 @inheritdoc
*/
void King::makeMove(int diffRow, int diffColumn)
{

    setRow(this->row + diffRow);
    setColumn(this->column + diffColumn);

}

bool King::isMoveLegal(int diffRow, int diffColumn)
{

    return diffRow >= -1 && diffRow <= 1
           && diffColumn >= -1 && diffColumn <= 1
           && !(diffRow == 0 && diffColumn == 0);
}

bool King::isValidMove(int diffRow, int diffColumn)
{
    return Piece::isValidMove(diffRow, diffColumn) && this->isMoveLegal(diffRow, diffColumn);
}

PieceType King::getType()
{
    return KING;
}
