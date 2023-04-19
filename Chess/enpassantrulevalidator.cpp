#include "enpassantrulevalidator.h"


bool EnPassantRuleValidator::validateRule(Piece*& movedPiece, int diffRow, int diffCol)
{
    int row = movedPiece->getRow();
    int column = movedPiece->getColumn();

    Board * board = Board::getInstance();

    PieceType type = movedPiece->getType();
    Color color = movedPiece->getColor();

    if(diffCol == 0)
        return false;

    if((color == WHITE && row != 5) || (color == _BLACK && row != 4))
        return false;

    int numberOfMoves = movedPiece->getNumberOfMoves();

    Piece * enemyPiece = board->getPieceForPosition(row, column + diffCol);

    if(enemyPiece == NULL)
        return false;

    PieceType enemyType = enemyPiece->getType();
    Color enemyColor = enemyPiece->getColor();
    int enemyPieceFirstMove = enemyPiece->getFirstMoveTime();

    if(color == enemyColor)
        return false;

    if(enemyType != PAWN)
        return false;

//    std::cout << enemyType << ' ' << enemyColor << ' ' << enemyPieceFirstMove << '\n';

    if(numberOfMoves != enemyPieceFirstMove)
        return false;

    return true;
}
