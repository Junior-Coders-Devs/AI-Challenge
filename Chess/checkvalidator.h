#ifndef H_CHECKVALIDATOR
#define H_CHECKVALIDATOR

#include "board.h"
#include "config.h"

class CheckValidator
{
public:
    CheckValidator();
    void isCheck(Board board, Color player);
    void isCheckMate(Board board, Color playerToMove);
};


#endif // H_CHECKVALIDATOR
