#include "piece.h"
#include "movevalidator.h"


Piece::Piece(int row, int column, Color color) {
    this->row = row;
    this->column = column;
    this->color = color;
}

/**
    Functionality to move a piece by diffRow rows and diffColumn columns

    @params
    diffRow -> difference in rows (positive - up, negative - down)
    diffColumn -> difference in columns (positive - right, negative - left)
*/
void Piece::makeMove(int diffRow, int diffColumn) {
    // To be implemented by every type of piece
}

std::vector<MoveBy> Piece::getValidPositions()
{
   std::vector<MoveBy> validMoves;

    MoveValidator moveValidator;

    int pieceRow = row;
    int pieceColumn = column;

    for(int targetRow = 1; targetRow <= 8; ++targetRow)
    {
        for(int targetColumn = 1; targetColumn <= 8; ++targetColumn)
        {
            bool pieceMove = this->isValidMove(targetRow - pieceRow, targetColumn - pieceColumn);
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

bool Piece::isValidMove(int diffRow, int diffColumn){

    bool ok = true;

    ok = ok && (diffRow + row >= 1);
    ok = ok && (diffRow + row <= 8);
    ok = ok && (diffColumn + column >= 1);
    ok = ok && (diffColumn + column <= 8);

    return ok;
}

void Piece::setRow(int row) {
    this->row = row;
}

int Piece::getRow() const {
    return row;
}

void Piece::setColumn(int column) {
    this->column = column;
}

int Piece::getColumn() const {
    return column;
}

void Piece::setColor(Color color) {
    this->color = color;
}

Color Piece::getColor() const {
    return color;
}

PieceType Piece::getType() {}
