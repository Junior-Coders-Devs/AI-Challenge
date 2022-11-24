#include "pawn.h"

Pawn::Pawn(int row, int column) : Piece(row, column) {}


/**
  @inheritdoc
*/
void Pawn::makeMove(int diffRow, int diffColumn)
{
    bool ok = true;

    ok &= this->isMoveLegal(diffRow, diffColumn);
    ok &= this->isValidMove(diffRow, diffColumn);

    if(!ok)
        return;

    int currentRow = this->getRow();
    int currentColumn = this->getColumn();

    this->setRow(currentRow + diffRow);
    this->setColumn(currentColumn + diffColumn);
}

bool Pawn::isMoveLegal(int diffRow, int diffColumn)
{
     if(std::abs(diffRow) > 2 || std::abs(diffColumn) > 1)
        return 0;

     if(std::abs(diffRow) == 2 && diffColumn)
        return 0;

     int currentRow = this->getRow();

     if(std::abs(diffRow) == 2 && (currentRow != 2 && currentRow != 7))
        return 0;

     return 1;
}
