#include "pawnchessrulesvalidator.h"
#include "nopiecesonpathrulevalidator.h"

PawnChessRulesValidator::PawnChessRulesValidator() {
    rules.push_back(new NoPiecesOnPathRuleValidator);
}
