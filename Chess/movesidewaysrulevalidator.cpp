#include "movesidewaysrulevalidator.h"


bool MoveSidewaysRuleValidator::validateRule(Piece *& movedPiece, int diffRow, int diffCol)
{
    if(diffRow == 0 && diffCol)
        return false;

    return true;
}
