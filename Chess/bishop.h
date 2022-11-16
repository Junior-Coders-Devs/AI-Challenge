#ifndef H_BISHOP
#define H_BISHOP

#include "piece.h"
class Bishop: public Piece{
    public:
        Bishop(int row, int column);
        virtual void makeMove(int diffRow, int diffColumn);

    protected:
        virtual bool isValidMove(int diffRow, int diffColumn);

    private:
        int row;
        int column;
        bool isMoveLegal(int diffRow, int diffColumn);
}



#endif //H_BISHOP