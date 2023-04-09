#ifndef H_CHESS_RULES_VALIDATOR
#define H_CHESS_RULES_VALIDATOR

#include "piece.h"
#include "board.h"
#include "rulevalidator.h"

class ChessRulesValidator {
public:
    bool validateRules(Piece* movedPiece, int diffRow, int diffColumn);

protected:
    std::vector<RuleValidator*> rules;
};

#endif // H_CHESS_RULES_VALIDATOR
