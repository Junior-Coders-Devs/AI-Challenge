#ifndef H_MOVEVALIDATOR_V2
#define H_MOVEVALIDATOR_V2

#include "board.h"
#include "chessrulesvalidator.h"
#include "rookchessrulesvalidator.h"
#include "horsechessrulesvalidator.h"
#include "bishopchessrulesvalidator.h"
#include "kingchessrulesvalidator.h"
#include "queenchessrulesvalidator.h"
#include "pawnchessrulesvalidator.h"

class MoveValidatorV2
{
public:
    MoveValidatorV2();

    bool validateMove(int diffRow, int diffCol, int row, int column);

private:
    ChessRulesValidator* getChessRuleValidator(Piece* movedPiece);
};



#endif // H_MOVEVALIDATOR_V2
