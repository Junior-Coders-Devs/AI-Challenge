#include "movevalidator.h"
#include "board.h"


MoveValidator::MoveValidator() {}

bool MoveValidator::validateMove(int diffRow, int diffCol, int row, int column)
{
    Piece* movedPiece = Board::getInstance()->getPieceForPosition(row, column);
    ChessRulesValidator* rulesValidator = getChessRuleValidator(movedPiece);

    return rulesValidator->validateRules(movedPiece, diffRow, diffCol);
}

ChessRulesValidator* MoveValidator::getChessRuleValidator(Piece* movedPiece) {
    switch(movedPiece->getType()) {
        case PAWN:
            return new PawnChessRulesValidator;
        case KING:
            return new KingChessRulesValidator;
        case QUEEN:
            return new QueenChessRulesValidator;
        case BISHOP:
            return new BishopChessRulesValidator;
        case KNIGHT:
            return new KnightChessRulesValidator;
        case ROOK:
            return new RookChessRulesValidator;
    }

    return NULL;
}
