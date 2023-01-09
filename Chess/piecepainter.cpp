#include "piecepainter.h"

PiecePainter::PiecePainter(){}

/*
     Functionality to paint a piece depending on it's position on the table(row, column), type and color

     @params
     column -> the column on which the piece is located
     row -> the row on which the piece is located
     pieceType -> using the enum PieceType, it identifies the piece type(pawn, knight, king...)
     pieceColor -> using the enum Color, it identifies the piece color(WHITE or BLACK)

*/

void PiecePainter::paintPiece(int row, int column, PieceType pieceType, Color pieceColor)
{
    Color squareColor = getColorForCell(row, column);
    const char* piecePath = piecePathLoader.getPath(squareColor, pieceColor, pieceType);

    int diffCol = (column - 1) * SQUARE_SIZE;
    int diffLin = (8 - row) * SQUARE_SIZE;

    loadPiece(piecePath, diffLin, diffCol);
}

/*
     Functionality to determine the cell color

     @params
     column, row
*/


Color PiecePainter::getColorForCell(int row, int column) {

    if((row + column) % 2 == 0) {

        return _BLACK;
    }

    return _WHITE;
}


/*
    Functionality to load the Piece on the table based on it's position

    @params
    image -> the location of the image
    diffLin -> locating the down right corner of the image(line)
    diffCol -> locating the down right corner of the image(column)
*/


void PiecePainter::loadPiece(const char* image, int diffLin, int diffCol) {

    readimagefile(image, OFFSET_Y + diffCol, OFFSET_X + diffLin,
                  OFFSET_Y + diffCol + SQUARE_SIZE, OFFSET_X + diffLin + SQUARE_SIZE);
}
