#include "convertvalidator.h"

#include <iostream>

void ConvertValidator::convertPawnIntoQueen(Board * board, PiecePainter *piecePainter)
{
    const int validRows[] = {1, 8};

    for(int i = 1; i <= 8; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            Piece * piece = board->getPieceForPosition(validRows[j], i);

            if(piece == NULL)
                continue;

            Color color = piece->getColor();

            if(piece->getType() == PAWN && j % 2 != color % 2)
            {
                piecePainter->paintPiece(validRows[j], i, QUEEN, color);
                board->deletePiece(validRows[j], i, color);
                board->addPiece(validRows[j], i, color, QUEEN);
            }
        }

    }
}

ConvertValidator::ConvertValidator() {};
