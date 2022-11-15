#include "piece.h"

#ifndef H_BISHOP
#define H_BISHOP

class Bishop: public Piece{
    public:
        Bishop(int row,int column);
        virtual void makeMove(int diffRow,int diffColumn);
    protected:
        virtual bool isValidMove(int diffRow,int diffColumn);
    private:
        int row;
        int column;
}



#endif //H_BISHOP