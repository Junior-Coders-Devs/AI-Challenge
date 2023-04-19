#include "pawnchessrulesvalidator.h"
#include "nopiecesonpathrulevalidator.h"
#include "moveforwardrulevalidator.h"
#include "movebackrulevalidator.h"
#include "movediagonallyrulevalidator.h"
#include "movesidewaysrulevalidator.h"
#include "changetoqueenrulevalidator.h"

PawnChessRulesValidator::PawnChessRulesValidator() {
    rules.push_back(new NoPiecesOnPathRuleValidator);
    rules.push_back(new MoveForwardRuleValidator);
    rules.push_back(new MoveBackRuleValidator);
    rules.push_back(new MoveDiagonallyRuleValidator);
    rules.push_back(new MoveSidewaysRuleValidator);
    rules.push_back(new ChangeToQueenRuleValidator);
}
