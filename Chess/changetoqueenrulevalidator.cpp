#include "changetoqueenrulevalidator.h"

bool ChangeToQueenRuleValidator::validateRule(Piece*& movedPiece, int diffRow, int diffCol)
{
    Board * board = Board::getInstance();

    int row = movedPiece->getRow();
    int column = movedPiece->getColumn();

    Color color = movedPiece->getColor();

    if((color == _BLACK && row + diffRow == 1) || (color == _WHITE && row + diffRow == 8))
    {
        board->deletePiece(row, column, color);
        board->addQueen(row, column, color);
        movedPiece = board->getPieceForPosition(row, column);
    }

    return true;
}
