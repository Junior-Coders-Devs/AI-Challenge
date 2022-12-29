#ifndef H_PIECE
#define H_PIECE

#include "config.h"

class Piece {

    public:
        Piece(int row, int column, Color color);

        void setRow(int row);
        int getRow() const;


        void setColumn(int column);
        int getColumn() const;

        void setColor(Color color);
        Color getColor() const;

        virtual void makeMove(int diffRow, int diffColumn);
        virtual bool isValidMove(int diffRow, int diffColumn);
        virtual PieceType getType();

    protected:
        int row;
        int column;
        Color color;
};

#endif // H_PIECE
