#include "rookchessrulesvalidator.h"
#include "nopiecesonpathrulevalidator.h"

RookChessRulesValidator::RookChessRulesValidator() {
    rules.push_back(new NoPiecesOnPathRuleValidator);
}
