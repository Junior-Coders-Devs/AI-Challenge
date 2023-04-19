#ifndef H_MOVESIDEWAYSRULEVALIDATOR
#define H_MOVESIDEWAYSRULEVALIDATOR

#include "rulevalidator.h"

class MoveSidewaysRuleValidator : public RuleValidator
{
public:
    bool validateRule(Piece *& movedPiece, int diffRow, int diffCol) override;

};



#endif // H_MOVESIDEWAYSRULEVALIDATOR
