#ifndef H_MOVEDIAGONALLYRULEVALIDATOR
#define H_MOVEDIAGONALLYRULEVALIDATOR

#include "rulevalidator.h"

class MoveDiagonallyRuleValidator : public RuleValidator
{
public:
    bool validateRule(Piece *& movedPiece, int diffRow, int diffCol) override;
};


#endif // H_MOVEDIAGONALLYRULEVALIDATOR
