#include "chessrulesvalidator.h"

bool ChessRulesValidator::validateRules(Piece* movedPiece, int diffRow, int diffColumn) {

    for(auto rule: rules) {

        if(!rule->validateRule(movedPiece, diffRow, diffColumn)) {

            return false;
        }
    }

    return true;
}
