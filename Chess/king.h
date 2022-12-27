#ifndef H_KING
#define H_KING

#include "piece.h"

class King: public Piece{

    public:
        King(int row, int column);
        void makeMove(int diffRow, int diffColumn);
        bool isValidMove(int diffRow, int diffColumn);

    private:
        bool isMoveLegal(int diffRow, int diffColumn);
};

#endif // H_KING
