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

            if((i + j) % 2)
                drawSquare(i, j, 0, "Backgrounds/Black.jpg");
            else
                drawSquare(i, j, 1, "Backgrounds/White.jpg");

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
        for(int j = 1; j <= 8; j++)
        {
            if((i + j) % 2)
            {
                if(j == 1)
                {
                    if(i == 2)
                        loadPiece(i, j, "BlackOnBlack/knight.jpg");
                    else if(i == 4)
                        loadPiece(i, j, "BlackOnBlack/queen.jpg");
                    else if(i == 6)
                        loadPiece(i, j, "BlackOnBlack/bishop.jpg");
                    else
                        loadPiece(i, j, "BlackOnBlack/rook.jpg");
                }
                else if(j == 2)
                    loadPiece(i, j, "BlackOnBlack/pawn.jpg");
            }
            else
            {
                if(j == 1)
                {
                    if(i == 7)
                        loadPiece(i, j, "BlackOnWhite/knight.jpg");
                    else if(i == 5)
                        loadPiece(i, j, "BlackOnWhite/king.jpg");
                    else if(i == 3)
                        loadPiece(i, j, "BlackOnWhite/bishop.jpg");
                    else
                        loadPiece(i, j, "BlackOnWhite/rook.jpg");
                }
                else if(j == 2)
                    loadPiece(i, j, "BlackOnWhite/pawn.jpg");
            }
        }
    }

}

void Painter::initializeWhitePieces()
{
    // TODO
}

void Painter::drawSquare(int row, int column, int patrat, char image[])
{
    int diffCol = (column - 1) * SQUARE_SIZE;
    int diffLin = (row - 1 ) * SQUARE_SIZE;

    line(OFFSET_X + diffLin, OFFSET_Y + diffCol,
         OFFSET_X + diffLin, OFFSET_Y + diffCol + SQUARE_SIZE);

    line(OFFSET_X + diffLin, OFFSET_Y + diffCol + SQUARE_SIZE,
         OFFSET_X + diffLin + SQUARE_SIZE, OFFSET_Y + diffCol + SQUARE_SIZE);

    line(OFFSET_X + diffLin + SQUARE_SIZE, OFFSET_Y + diffCol + SQUARE_SIZE,
         OFFSET_X + diffLin + SQUARE_SIZE, OFFSET_Y + diffCol);

    line(OFFSET_X + diffLin + SQUARE_SIZE, OFFSET_Y + diffCol,
         OFFSET_X + diffLin, OFFSET_Y + diffCol);

    if(patrat == 0)
    {

        readimagefile(image, OFFSET_X + diffLin, OFFSET_Y + diffCol,
                      OFFSET_X + diffLin + SQUARE_SIZE, OFFSET_Y + diffCol + SQUARE_SIZE);
    }
    else if(patrat == 1)
    {

        readimagefile(image, OFFSET_X + diffLin, OFFSET_Y + diffCol,
                      OFFSET_X + diffLin + SQUARE_SIZE, OFFSET_Y + diffCol + SQUARE_SIZE);
    }
}

void Painter::loadPiece(int row, int column, char image[])
{
    int diffCol = (column - 1) * SQUARE_SIZE;
    int diffLin = (row - 1 ) * SQUARE_SIZE;

    readimagefile(image, OFFSET_X + diffLin, OFFSET_Y + diffCol,
                  OFFSET_X + diffLin + SQUARE_SIZE, OFFSET_Y + diffCol + SQUARE_SIZE);
}
