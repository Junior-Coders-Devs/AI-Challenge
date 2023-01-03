#include "movevalidator.h"


MoveValidator::MoveValidator() {}


void MoveValidator::setBoard(Board *board)
{
    this->board = board;
}

void MoveValidator::setColor(Color color)
{
    this->color = color;
}


bool MoveValidator::checkMove(int diffRow, int diffCol, int row, int column)
{
    bool isHorse = MoveValidator::isHorseMoved(diffRow, diffCol);

    if(isHorse)
        return true;

    int moveX = 0, moveY = 0;
    if(diffRow)
        moveX = diffRow / std::abs(diffRow);
    if(diffCol)
        moveY = diffCol / std::abs(diffCol);

    diffRow = std::abs(diffRow), diffCol = std::abs(diffCol);

    bool ok = isPathGood(diffRow, diffCol, row, column, moveX, moveY);

    return ok;
}


bool MoveValidator::isHorseMoved(int diffRow, int diffCol)
{
    const std::vector<std::pair<int,int>> moves = {{1, 2}, {1, -2}, {-1, -2}, {-2, 1},
        {2, -1}, {2, 1}, {-1, 2}, {-2, -1}
    };

    bool isHorse = false;

    for(auto j : moves)
        isHorse |= (diffCol == j.second && diffRow == j.first);

    return isHorse;
}


bool MoveValidator::isPathGood(int diffRow, int diffCol, int row, int column, int moveX, int moveY)
{
    while(diffRow > 0 || diffCol > 0)
    {
        MoveValidator::makeMove(row, column, moveX, moveY);

        diffRow--, diffCol--;

        int type = validateCell(row, column);

        if(type == 1)
            return 0;

        if(type == 0)
        {
            if(std::max(diffRow, 0) + std::max(diffCol, 0) == 0)
                return 1;
            else
                return 0;
        }

    }

    return 1;
}


void MoveValidator::makeMove(int &row, int &column, int moveX, int moveY)
{
    row += moveX;
    column += moveY;
}


int MoveValidator::validateCell(int row, int column)
{
    Color oppositeColor;

    if(color == _WHITE)
        oppositeColor = _BLACK;
    else oppositeColor = _WHITE;

    bool myColor = checkForColor(color, row, column);
    bool diffColor = checkForColor(oppositeColor, row, column);

    if(myColor)
        return 1;

    if(diffColor)
        return 0;

    return -1;
}

bool MoveValidator::checkForColor(Color color, int row, int column)
{
    std::vector<Piece*> pieces = board->getPieces(color);
    for(int i = 0; i < pieces.size(); ++i)
    {
        int boardRow = pieces[i]->getRow();
        int boardColumn = pieces[i]->getColumn();
        if(boardRow == row && boardColumn == column)
            return true;
    }
    return false;
}
