#ifndef H_CHANGETOQUEENRULEVALIDATOR
#define H_CHANGETOQUEENRULEVALIDATOR

#include "rulevalidator.h"

class ChangeToQueenRuleValidator : public RuleValidator
{
public:
    bool validateRule(Piece *& movedPiece, int diffRow, int diffCol);
};


#endif // H_CHANGETOQUEENRULEVALIDATOR
