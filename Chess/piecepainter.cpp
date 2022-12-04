#include "piecepainter.h"

PiecePainter::PiecePainter(){}


void PiecePainter::paintPiece(int column, int row, PieceType pieceType, Color pieceColor)
{

    Color squareColor = getColorForCell(row, column);
    const char* piecePath = piecePathLoader.getPath(squareColor, pieceColor, pieceType);

    int diffCol = (column - 1) * SQUARE_SIZE;
    int diffLin = (row - 1) * SQUARE_SIZE;

    loadPiece(piecePath, diffLin, diffCol);
}

Color PiecePainter::getColorForCell(int row, int column) {

    if((row + column) % 2 == 0) {

        return _WHITE;
    }

    return _BLACK;
}

void PiecePainter::loadPiece(const char* image, int diffLin, int diffCol) {

    readimagefile(image, OFFSET_X + diffLin, OFFSET_Y + diffCol,
                  OFFSET_X + diffLin + SQUARE_SIZE, OFFSET_Y + diffCol + SQUARE_SIZE);
}
