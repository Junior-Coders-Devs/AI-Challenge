#include "bishop.h"

Bishop::Bishop(int row, int column): Piece(row, column) {}

/**
 @inheritdoc
*/
void Bishop::makeMove(int diffRow, int diffColumn){

    setRow(this->row + diffRow);
    setColumn(this->column + diffColumn);

}

bool Bishop::isValidMove(int diffRow, int diffColumn)
{
    return Piece::isValidMove(diffRow, diffColumn) && isMoveLegal(diffRow, diffColumn);
}


bool Bishop::isMoveLegal(int diffRow, int diffColumn)
{
    bool ok = false;

    int newRow = this->row + diffRow;
    int newColumn = this->column + diffColumn;

    ok = ok || (newRow+newColumn == this->row+this->column);   ///right to left diagonal
    ok = ok || (newRow-newColumn == this->row-this->column);   ///left to right diagonal
    ok = ok && (diffRow != 0 || diffColumn != 0);

    return ok;
}
