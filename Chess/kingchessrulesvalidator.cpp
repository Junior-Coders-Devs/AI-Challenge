#include "kingchessrulesvalidator.h"
#include "nopiecesonpathrulevalidator.h"

KingChessRulesValidator::KingChessRulesValidator() {
    rules.push_back(new NoPiecesOnPathRuleValidator);
}
