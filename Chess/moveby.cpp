#include "moveby.h"

MoveBy::MoveBy(int diffRow, int diffColumn){
    this->diffRow=diffRow;
    this->diffColumn=diffColumn;
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
