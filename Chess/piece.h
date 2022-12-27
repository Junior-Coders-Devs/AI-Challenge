#ifndef H_PIECE
#define H_PIECE

#include <iostream>

class Piece {

    public:
        Piece(int row, int column);

        void setRow(int row);
        int getRow() const;

        void setColumn(int column);
        int getColumn() const;

        virtual void makeMove(int diffRow, int diffColumn);
        virtual bool isValidMove(int diffRow, int diffColumn);

    protected:
        int row;
        int column;
};

#endif // H_PIECE
