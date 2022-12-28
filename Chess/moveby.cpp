#include "moveby.h"

MoveBy::MoveBy(){
    diffRow=0;
    diffColumn=0;
}



void MoveBy::setDiffRow(int diffRow) {
    this->diffRow = diffRow;
}

int MoveBy::getDiffRow() const {
    return diffRow;
}

void MoveBy::setDiffColumn(int diffColumn) {
    this->diffColumn = diffColumn;
}

int MoveBy::getDiffColumn() const {
    return diffColumn;
}
