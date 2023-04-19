#ifndef H_ENPASSANTRULEVALIDATOR
#define H_ENPASSANTRULEVALIDATOR

#include "rulevalidator.h"

class EnPassantRuleValidator : public RuleValidator
{
public:
    bool validateRule(Piece *& movedPiece, int diffRow, int diffCol) override;
};



#endif // H_ENPASSANTRULEVALIDATOr

