#ifndef H_CHECKVALIDATOR
#define H_CHECKVALIDATOR

#include "board.h"
#include "config.h"

class CheckValidator
{
    public:
        CheckValidator();
        void isCheck(Color player);
        void isCheckMate(Color playerToMove);
    private:
        bool isCheckPosition(int row,int column, Color player);
};


#endif // H_CHECKVALIDATOR
