#ifndef H_KING
#define H_KING

#include "piece.h"

class King: public Piece{

    public:
        King(int row, int column);
        virtual void makeMove(int diffRow, int diffColumn);

    protected:
        bool isMoveLegal(int diffRow, int diffColumn);
};

#endif // H_KING
