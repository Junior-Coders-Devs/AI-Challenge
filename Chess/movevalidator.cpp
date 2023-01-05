#include "movevalidator.h"
#include "board.h"


MoveValidator::MoveValidator() {}

void MoveValidator::setColor(Color color)
{
    this->color = color;
}


bool MoveValidator::validateMove(int diffRow, int diffCol, int row, int column)
{
    if(isHorseMoved(diffRow, diffCol))
        return true;

    int moveX = 0, moveY = 0;
    if(diffRow) moveX = diffRow / std::abs(diffRow);
    if(diffCol) moveY = diffCol / std::abs(diffCol);

    diffRow = std::abs(diffRow), diffCol = std::abs(diffCol);

    bool ok = isPathGood(diffRow, diffCol, row, column, moveX, moveY);

    return ok;
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
