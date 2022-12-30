#include "pawn.h"
#include "movevalidator.h"

Pawn::Pawn(int row, int column, Color color) : Piece(row, column, color) {}


/**
  @inheritdoc
*/
void Pawn::makeMove(int diffRow, int diffColumn)
{
    int currentRow = this->getRow();
    int currentColumn = this->getColumn();

    this->setRow(currentRow + diffRow);
    this->setColumn(currentColumn + diffColumn);

}

bool Pawn::isMoveLegal(int diffRow, int diffColumn)
{
     if(diffRow == 0 && diffColumn == 0)
        return 0;

     if(std::abs(diffRow) > 2 || std::abs(diffColumn) > 1)
        return 0;

     if(std::abs(diffRow) == 2 && diffColumn)
        return 0;

     int currentRow = this->getRow();

     if(std::abs(diffRow) == 2 && (currentRow != 2 && currentRow != 7))
        return 0;

     return 1;
}

bool Pawn::isValidMove(int diffRow, int diffColumn)
{
    return Piece::isValidMove(diffRow, diffColumn) && this->isMoveLegal(diffRow, diffColumn);
}

PieceType Pawn::getType() {
    return PAWN;
}
