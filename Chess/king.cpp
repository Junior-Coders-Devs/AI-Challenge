#include "king.h"
#include "movevalidator.h"

King::King(int row, int column, Color color):Piece(row,column, color) {}

/**
 @inheritdoc
*/
void King::makeMove(int diffRow, int diffColumn)
{

    setRow(this->row + diffRow);
    setColumn(this->column + diffColumn);

}

std::vector<position> King::getValidPositions()
{
    std::vector<position> validMoves;

    MoveValidator moveValidator;

    int pieceRow = row;
    int pieceColumn = column;

    for(int targetRow = 1; targetRow <= 8; ++targetRow)
    {
        for(int targetColumn = 1; targetColumn <= 8; ++targetColumn)
        {
            bool pieceMove = King::isValidMove(targetRow - pieceRow, targetColumn - pieceColumn);
            if(pieceMove)
            {
                bool ok = moveValidator.validateMove(targetRow - pieceRow, targetColumn - pieceColumn, pieceRow, pieceColumn);
                if(ok)
                    validMoves.push_back({targetRow - pieceRow, targetColumn - pieceColumn});
            }
        }
    }

    return validMoves;
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
