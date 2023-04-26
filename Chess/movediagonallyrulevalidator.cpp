#include "movediagonallyrulevalidator.h"


bool MoveDiagonallyRuleValidator::validateRule(Piece *& movedPiece, int diffRow, int diffCol)
{
    if(!diffRow || !diffCol)
        return true;

    if(abs(diffRow) > 1 || abs(diffCol) > 1)
        return false;

    int row = movedPiece->getRow();
    int column = movedPiece->getColumn();

    Piece * enemyPiece = Board::getInstance()->getPieceForPosition(row + diffRow, column + diffCol);

    if(enemyPiece == NULL)
        return false;

    if(movedPiece->getColor() != enemyPiece->getColor())
        return true;

    return false;
}
