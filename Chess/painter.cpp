#include "painter.h"


Painter::Painter() {}

void Painter::initializeWindow()
{

    initwindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Chess");
}

void Painter::initializeBoard()
{

    for(int lineIndex = 1; lineIndex <= 8; lineIndex++)
    {
        for(int columnIndex = 1; columnIndex <= 8; columnIndex++)
        {
            char background[PATH_SIZE];

            if((lineIndex + columnIndex) % 2 == 0)
                strcpy(background, EMPTY_WHITE_CELL);
            else
                strcpy(background, EMPTY_BLACK_CELL);

            drawSquare(lineIndex, columnIndex, background);
        }
    }
}

void Painter::initializePieces()
{
    initializeBlackPieces();
    initializeWhitePieces();
}

void Painter::initializeBlackPieces()
{
    piecePainter.paintPiece(1, 1, ROOK, _BLACK);
    piecePainter.paintPiece(1, 2, KNIGHT, _BLACK);
    piecePainter.paintPiece(1, 3, BISHOP, _BLACK);
    piecePainter.paintPiece(1, 4, QUEEN, _BLACK);
    piecePainter.paintPiece(1, 5, KING, _BLACK);
    piecePainter.paintPiece(1, 6, BISHOP, _BLACK);
    piecePainter.paintPiece(1, 7, KNIGHT, _BLACK);
    piecePainter.paintPiece(1, 8, ROOK, _BLACK);

    for(int columnIndex = 1; columnIndex <= 8; columnIndex++) {
        piecePainter.paintPiece(2, columnIndex, PAWN, _BLACK);
    }
}

void Painter::initializeWhitePieces()
{
    piecePainter.paintPiece(8, 1, ROOK, _WHITE);
    piecePainter.paintPiece(8, 2, KNIGHT, _WHITE);
    piecePainter.paintPiece(8, 3, BISHOP, _WHITE);
    piecePainter.paintPiece(8, 4, QUEEN, _WHITE);
    piecePainter.paintPiece(8, 5, KING, _WHITE);
    piecePainter.paintPiece(8, 6, BISHOP, _WHITE);
    piecePainter.paintPiece(8, 7, KNIGHT, _WHITE);
    piecePainter.paintPiece(8, 8, ROOK, _WHITE);

    for(int columnIndex = 1; columnIndex <= 8; columnIndex++){
        piecePainter.paintPiece(7, columnIndex, PAWN, _WHITE);
    }
}

void Painter::drawSquare(int row, int column, char image[])
{
    int diffCol = (column - 1) * SQUARE_SIZE;
    int diffLin = (row - 1) * SQUARE_SIZE;

    line(OFFSET_X + diffLin, OFFSET_Y + diffCol,
         OFFSET_X + diffLin, OFFSET_Y + diffCol + SQUARE_SIZE);

    line(OFFSET_X + diffLin, OFFSET_Y + diffCol + SQUARE_SIZE,
         OFFSET_X + diffLin + SQUARE_SIZE, OFFSET_Y + diffCol + SQUARE_SIZE);

    line(OFFSET_X + diffLin + SQUARE_SIZE, OFFSET_Y + diffCol + SQUARE_SIZE,
         OFFSET_X + diffLin + SQUARE_SIZE, OFFSET_Y + diffCol);

    line(OFFSET_X + diffLin + SQUARE_SIZE, OFFSET_Y + diffCol,
         OFFSET_X + diffLin, OFFSET_Y + diffCol);


    readimagefile(image, OFFSET_X + diffLin, OFFSET_Y + diffCol,
                  OFFSET_X + diffLin + SQUARE_SIZE, OFFSET_Y + diffCol + SQUARE_SIZE);

}
