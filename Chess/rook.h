#ifndef H_ROOK
#define H_ROOK
#include "piece.h"
class Rook:public Piece{

public:
    Rook(int row, int column);
    virtual void makeMove(int difRow, int difColumn);
protected:
    virtual bool isValidMove(int difRow, int difColumn);
private:
    int row;
    int column;
};

#endif // H_ROOK
