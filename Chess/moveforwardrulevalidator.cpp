#include "moveforwardrulevalidator.h"

bool MoveForwardRuleValidator::validateRule(Piece *& movedPiece, int diffRow, int diffCol)
{
    if(diffRow && diffCol)
        return true;

    int row = movedPiece->getRow();
    int column = movedPiece->getColumn();

    Piece * enemyPiece = Board::getInstance()->getPieceForPosition(row + diffRow, column);

    if(enemyPiece == NULL)
        return true;

    return false;
}
