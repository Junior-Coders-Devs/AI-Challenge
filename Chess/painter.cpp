#include "painter.h"


Painter::Painter() {}

void Painter::initializeWindow()
{

    initwindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Chess");
}

void Painter::initializeBoard()
{

    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++)
        {
            char background[PATH_SIZE];

            if((i + j) % 2 == 0)
                strcpy(background, _WHITE);
            else
                strcpy(background, _BLACK);

            drawSquare(i, j, background);
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

    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 2; j++)
        {
            piecePainter.loadPiece(i, j);
        }
    }

}

void Painter::initializeWhitePieces()
{
    // TODO
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
