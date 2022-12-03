#include "piecepainter.h"

PiecePainter::PiecePainter(){}


void PiecePainter::loadPiece(int row, int column)
{
    int diffCol = (column - 1) * SQUARE_SIZE;
    int diffLin = (row - 1) * SQUARE_SIZE;

    char image[PATH_SIZE];

    if((row + column) % 2)
    {
        if(column == 1)
            strcpy(image, BlackOnBlackPaths[row / 2 - 1]);

        else if(column == 2)
            strcpy(image, BlackOnBlackPaths[4]);
    }
    else
    {
        if(column == 1)
            strcpy(image, BlackOnWhitePaths[(8 - row) / 2]);

        else if(column == 2)
            strcpy(image, BlackOnWhitePaths[4]);
    }

    readimagefile(image, OFFSET_X + diffLin, OFFSET_Y + diffCol,
                  OFFSET_X + diffLin + SQUARE_SIZE, OFFSET_Y + diffCol + SQUARE_SIZE);
}
