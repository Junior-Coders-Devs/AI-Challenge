#include "rook.h"

Rook::Rook(int row, int column):Piece(row, column)
{
    this->row=row;
    this->column=column;
}

/**
 @inheritdoc
*/
void Rook::makeMove(int diffRow, int diffColumn)
{
    if(!isValidMove(diffRow,diffColumn))
        return;

    setRow(this->row + diffRow);
    setColumn(this->column + diffColumn);
}


bool Rook::isValidMove(int diffRow, int diffColumn)
{
    bool ok=true;
    int currRow=this->row+diffRow;
    int currColumn=this->column+diffColumn;
    if(currRow>=1 && currRow<=8 && currColumn>=1 && currColumn<=8);
    else
    {
        ok=0;
    }
    if((diffRow!=0 && diffColumn==0) || (diffRow==0 && diffColumn!=0));
    else
    {
        ok=0;
    }
    return ok;
}



