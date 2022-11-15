#include "bishop.h"

Bishop::Bishop(int row,int column){
    this->row=row;
    this->column=column;
}

/**
 * Functionality to move a bishop by diffRow rows and diffRow columns
 * @params
 * diffRow -> difference in rows (positive - up, negative - down)
 * diffColumn -> difference in columns (positive - right, negative - left)
*/
void Bishop::makeMove(int diffRow,int diffColumn){
    if(!isValidMove(diffRow,diffColumn))
        return;
    setRow(this->row + diffRow);
    setColumn(this->column + diffColumn);
}

bool Bishop::isValidMove(int diffRow,int diffColumn){
    
    bool ok = true, diagonal = false;
    int newRow=this->row+diffRow;
    int newColumn=this->column+diffColumn;

    ok = ok && (newRow>=1 && newRow<=8);
    ok = ok && (newColumn>=1 && newColumn<=8);
    
    diagonal = diagonal || (newRow+newColumn == this->row+this->column);   ///right to left diagonal
    diagonal = diagonal || (newRow-newColumn == this->row-this->column);   ///left to right diagonal

    ok = ok & diagonal;

    return ok;
}