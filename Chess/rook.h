#ifndef H_ROOK
#define H_ROOK

#include "piece.h"

class Rook : public Piece
{

public:
    Rook(int row, int column, Color color);
    void makeMove(int diffRow, int diffColumn);
    bool isValidMove(int diffRow, int diffColumn);
    PieceType getType();
private:
    bool isMoveLegal(int diffRow, int diffColumn);
};

#endif // H_ROOK
