#include "king.h"
King::King(int row, int column):Piece(row,column)
{
    this->row=row;
    this->column=column;
}

/**
 @inheritdoc
*/
void King::makeMove(int diffRow, int diffColumn)
{
    if(!isValidMove(diffRow,diffColumn))
        return;

    setRow(this->row + diffRow);
    setColumn(this->column + diffColumn);
}


bool King::isValidMove(int diffRow, int diffColumn)
{
    bool ok=true;
    int currRow=this->row+diffRow;
    int currColumn=this->column+diffColumn;
    if(currRow>=1 && currRow<=8 && currColumn>=1 && currColumn<=8);
    else
    {
        ok = false;
    }
    if(diffRow>=-1 && diffRow<=1 && diffColumn>=-1 && diffColumn<=1 && !(diffRow==0 && diffColumn==0));
    else
    {
        ok = false;
    }
    return ok;
}
