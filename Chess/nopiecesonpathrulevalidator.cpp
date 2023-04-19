#include "nopiecesonpathrulevalidator.h"
#include <cmath>

int getSign(int diff) {

    if(diff == 0) return 0;
    if(diff > 0) return 1;
    return -1;
}

/**
    Validates there are no pieces on the path from current position of the moved piece to target position
    The only exception is where there is an opponent piece on target position. This exception is allowed
*/
bool NoPiecesOnPathRuleValidator::validateRule(Piece*& movedPiece, int diffRow, int diffColumn) {
    int stepRow = getSign(diffRow);
    int stepColumn = getSign(diffColumn);
    int totalSteps = std::max(std::abs(diffRow), std::abs(diffColumn));

    int currentRow = movedPiece->getRow();
    int currentColumn = movedPiece->getColumn();

    for(int steps = 1; steps < totalSteps; steps++) {
        if(Board::getInstance()->getPieceForPosition(currentRow + steps * stepRow, currentColumn + steps * stepColumn) != NULL) {
            return false;
        }
    }

    Piece* pieceOnTargetPosition = Board::getInstance()->getPieceForPosition(currentRow + diffRow, currentColumn + diffColumn);

    return pieceOnTargetPosition == NULL ||
            (pieceOnTargetPosition != NULL && movedPiece->getColor() != pieceOnTargetPosition->getColor());
}
