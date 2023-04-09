#include "bishopchessrulesvalidator.h"
#include "nopiecesonpathrulevalidator.h"

BishopChessRulesValidator::BishopChessRulesValidator() {
    rules.push_back(new NoPiecesOnPathRuleValidator);
}
