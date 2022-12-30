#include "queen.h"
#include "movevalidator.h"

Queen::Queen(int row, int column, Color color): Piece(row, column, color) {}

/**
 * @inheritdoc
*/
void Queen::makeMove(int diffRow, int diffColumn)
{

    setRow(this->row + diffRow);
    setColumn(this->column + diffColumn);

}


std::vector<position> Queen::getValidPositions()
{
    std::vector<position> validMoves;

    MoveValidator moveValidator;

    int pieceRow = row;
    int pieceColumn = column;

    for(int i = 1; i <= 8; ++i)
    {
        for(int j = 1; j <= 8; ++j)
        {
            bool pieceMove = Queen::isValidMove(i - pieceRow, j - pieceColumn);
            if(pieceMove)
            {
                bool ok = moveValidator.checkMove(i - pieceRow, j - pieceColumn, pieceRow, pieceColumn);
                if(ok)
                    validMoves.push_back({i - pieceRow, i - pieceColumn});
            }
        }
    }

    return validMoves;
}

bool Queen::isValidMove(int diffRow, int diffColumn)
{
    return Piece::isValidMove(diffRow, diffColumn) && isMoveLegal(diffRow, diffColumn);
}


bool Queen::isMoveLegal(int diffRow, int diffColumn)
{

    bool ok = false;

    int newRow = this->row + diffRow;
    int newColumn = this->column + diffColumn;

    ok = ok || (newRow + newColumn == this->row + this->column);   ///right to left diagonal
    ok = ok || (newRow - newColumn == this->row - this->column);   ///left to right diagonal
    ok = ok || (diffRow == 0);                                 ///same row
    ok = ok || (diffColumn == 0);                              ///same column
    ok = ok && (diffRow != 0 || diffColumn != 0);

    return ok;

}

PieceType Queen::getType()
{
    return QUEEN;
}
