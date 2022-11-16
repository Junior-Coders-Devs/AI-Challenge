#include "knight.h"


Knight::Knight(int row, int column) : Piece(row, column) {

}


void Knight::makeMove(int diffRow, int diffColumn) {

    vector <MoveBy> moves = getMoves();

    bool ok = 0;

    MoveBy currentMove = {diffRow, diffColumn};

    for(auto i : moves) {
        ok |= (i == currentMove && this->isValidMove(diffRow, diffColumn));
    }

    if(ok)
    {
        int currentRow = this->getRow();
        int currentColumn = this->getColumn();

        this->setRow(currentRow + diffRow);
        this->setColumn(currentColumn + diffColumn);
    }

}


vector <Knight::MoveBy>  Knight::getMoves() {
    return this->moves;
}
