#include "pawn.h"


Pawn::Pawn(int row, int column) : Piece(row, column)
{
    this->setColumn(column);
    this->setRow(row);
}


/**
  @inheritdoc
*/


void Pawn::makeMove(int diffRow, int diffColumn)
{
    bool ok = (this->isPawnMove(diffRow, diffColumn) & this->isValidMove(diffRow, diffColumn));

    if(!ok)
        return;

    int currentRow = this->getRow();
    int currentColumn = this->getColumn();

    this->setRow(currentRow + diffRow);
    this->setColumn(currentColumn + diffColumn);
}

bool Pawn::isPawnMove(int diffRow, int diffColumn)
{
     if(diffRow > 2 || diffColumn > 1)
        return 0;

     int currentRow = this->getRow();

     if(diffRow == 2 && ((currentRow - diffRow) % 5 || diffColumn))
        return 0;

     return 1;
}
