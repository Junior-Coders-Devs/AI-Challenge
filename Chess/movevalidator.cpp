#include "movevalidator.h"
#include "board.h"
#include <sstream>

MoveValidator::MoveValidator() {
    std::string temp="MoveValidator";
    log = new ChessLog();
}

void MoveValidator::setColor(Color color)
{
    this->color = color;
}


bool MoveValidator::validateMove(int diffRow, int diffCol, int row, int column)
{
    if(isHorseMoved(diffRow, diffCol))
        return true;
    if(isCastling(diffRow, diffCol, row, column)){
        return true;
    }
    int moveX = 0, moveY = 0;
    if(diffRow) moveX = diffRow / std::abs(diffRow);
    if(diffCol) moveY = diffCol / std::abs(diffCol);

    diffRow = std::abs(diffRow), diffCol = std::abs(diffCol);

    bool ok = isPathGood(diffRow, diffCol, row, column, moveX, moveY);

    return ok;
}

bool MoveValidator::isCastling(int diffRow, int diffColumn, int row, int column){
    this->wasCastling = false;
    if(diffRow > 0){
        return false;
    }
    std::string temp="diffRow :"+std::to_string(diffRow);
    log->Debug(temp);
    temp="diffCol :" + std::to_string(diffColumn);
    log->Debug(temp);
    temp="row :" + std::to_string(row);
    log->Debug(temp);
    temp="column :" + std::to_string(column);
    log->Debug(temp);
    Board* board = Board::getInstance();
    Piece* pieceOnPosition = board->getPieceForPosition(row, column);
    Piece* otherPiece = board->getPieceForPosition(row + diffRow, column + diffColumn);
    if(pieceOnPosition == NULL || otherPiece == NULL){
        return false;
    }
    temp="pieceOnPosition :" + pieceOnPosition->getShortName();
    log->Debug(temp);
    temp="otherPiece :" + otherPiece->getShortName();
    log->Debug(temp);
    if(!((pieceOnPosition->getShortName() == "K" && otherPiece->getShortName() == "R") || (pieceOnPosition->getShortName() == "R" && otherPiece->getShortName() == "K"))){
        return false;
    }
    temp="passedCastling1\n";
    log->Debug(temp);
    int moveX;
    if(diffColumn<0){
        moveX=-1;
    }
    else{
        moveX=1;
    }
    while(diffColumn!=0){
        diffColumn-=moveX;
        column+=moveX;
        Piece* piece = board->getPieceForPosition(row, column);
        if(piece!=NULL && piece->getShortName()!="K"){
            return false;
        }
    }
    this->wasCastling=true;
    return true;
}
void MoveValidator::setWasCastling(bool wasCastling){
    this->wasCastling=wasCastling;
}
bool MoveValidator::getWasCastling(){
    return this->wasCastling;
}
bool MoveValidator::isHorseMoved(int diffRow, int diffCol)
{
    bool isHorse = false;

    for(auto j : Knight::moves)
        isHorse |= (diffCol == j.getDiffColumn() && diffRow == j.getDiffRow());

    return isHorse;
}


bool MoveValidator::isPathGood(int diffRow, int diffCol, int row, int column, int moveX, int moveY)
{
    while(diffRow > 0 || diffCol > 0)
    {
        row += moveX;
        column += moveY;

        diffRow--, diffCol--;

        int result = validateCell(row, column);

        if(result == 1)
            return 0;

        if(result == 0)
        {
            if(std::max(diffRow, 0) + std::max(diffCol, 0) == 0)
                return 1;
            else
                return 0;
        }
    }
    return 1;
}


int MoveValidator::validateCell(int row, int column)
{
    Color oppositeColor;

    if(color == _WHITE)
        oppositeColor = _BLACK;
    else oppositeColor = _WHITE;

    bool myColor = checkForColor(color, row, column);
    bool diffColor = checkForColor(oppositeColor, row, column);

    if(myColor) return 1;
    if(diffColor) return 0;

    return -1;
}

bool MoveValidator::checkForColor(Color color, int row, int column)
{
    Board* board = Board::getInstance();
    Piece* pieceOnPosition = board->getPieceForPosition(row, column);

    if(pieceOnPosition == NULL)
        return false;

    return pieceOnPosition->getColor() == color;
}
