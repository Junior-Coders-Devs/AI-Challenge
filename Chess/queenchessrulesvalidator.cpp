#include "queenchessrulesvalidator.h"
#include "nopiecesonpathrulevalidator.h"

QueenChessRulesValidator::QueenChessRulesValidator() {
    rules.push_back(new NoPiecesOnPathRuleValidator);
}
