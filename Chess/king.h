#ifndef H_KING
#define H_KING
#include "piece.h"
class King:public Piece{

public:
    King(int row, int column);
    virtual void makeMove(int difRow, int difColumn);
protected:
    virtual bool isValidMove(int difRow, int difColumn);
private:
    int row;
    int column;
};

#endif // H_KING
