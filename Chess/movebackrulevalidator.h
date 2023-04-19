#ifndef H_MOVEBACKRULEVALIDATOR
#define H_MOVEBACKRULEVALIDATOR

#include "rulevalidator.h"

class MoveBackRuleValidator : public RuleValidator
{
public:
    bool validateRule(Piece*& movedPiece, int diffRow, int diffCol) override;
};


#endif // H_MOVEBACKRULEVALIDATOR
