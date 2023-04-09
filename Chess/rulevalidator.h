#ifndef H_RULE_VALIDATOR
#define H_RULE_VALIDATOR

#include "piece.h"
#include "board.h"

class RuleValidator {
public:
    virtual bool validateRule(Piece* movedPiece, int diffRow, int diffColumn);
};

#endif // H_RULE_VALIDATOR
