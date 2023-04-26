#ifndef H_MOVEFORWARDRULEVALIDATOR
#define H_MOVEFORWARDRULEVALIDATOR


#include "rulevalidator.h"


class MoveForwardRuleValidator : public RuleValidator
{
public:
    bool validateRule(Piece *& movedPiece, int diffRow, int diffCol) override;
};




#endif // H_MOVEFORWARDRULEVALIDATOR
