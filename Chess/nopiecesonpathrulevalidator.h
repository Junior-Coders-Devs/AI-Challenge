#ifndef H_NO_PIECES_ON_PATH_RULE_VALIDATOR
#define H_NO_PIECES_ON_PATH_RULE_VALIDATOR

#include "rulevalidator.h"

class NoPiecesOnPathRuleValidator: public RuleValidator {
    bool validateRule(Piece* movedPiece, int diffRow, int diffColumn) override;
};

#endif // H_NO_PIECES_ON_PATH_RULE_VALIDATOR
