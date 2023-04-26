#ifndef H_MOVEVALIDATOR
#define H_MOVEVALIDATOR

#include "board.h"
#include "chessrulesvalidator.h"
#include "rookchessrulesvalidator.h"
#include "horsechessrulesvalidator.h"
#include "bishopchessrulesvalidator.h"
#include "kingchessrulesvalidator.h"
#include "queenchessrulesvalidator.h"
#include "pawnchessrulesvalidator.h"

class MoveValidator
{
public:
    MoveValidator();

    bool validateMove(int diffRow, int diffCol, int row, int column);

private:
    ChessRulesValidator* getChessRuleValidator(Piece* movedPiece);
};



#endif // H_MOVEVALIDATOR
