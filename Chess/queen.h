#ifndef H_QUEEN
#define H_QUEEN

#include "piece.h"

class Queen: public Piece{
    public:
        Queen(int row, int column);
        virtual void makeMove(int diffRow, int diffColumn);

    protected:
        virtual bool isValidMove(int diffRow, int diffColumn);

    private:
        int row;
        int column;
        bool isMoveLegal(int diffRow, int diffColumn);
}


#endif //H_QUEEN