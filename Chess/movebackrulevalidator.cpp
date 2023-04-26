#include "movebackrulevalidator.h"


bool MoveBackRuleValidator::validateRule(Piece *& movedPiece, int diffRow, int diffCol)
{
    Color color = movedPiece->getColor();

    if(color == _BLACK && diffRow > 0)
        return false;

    if(color == _WHITE && diffRow < 0)
        return false;

    return true;
}
