#include "movevalidator.h"


MoveValidator::MoveValidator(){}


bool MoveValidator::checkMove(int diffRow, int diffCol, int row, int column)
{
    const std::vector<std::pair<int,int>> moves = {{1, 2}, {1, -2}, {-1, -2}, {-2, 1},
                                           {2, -1}, {2, 1}, {-1, 2}, {-2, -1}};

    bool isHorse = false;

    for(auto j : moves)
        isHorse |= (diffCol == j.second && diffRow == j.first);

    if(isHorse)
        return true;

    int moveX = 0, moveY = 0;
    if(diffRow)
        moveX = diffRow / std::abs(diffRow);
    if(diffCol)
        moveY = diffCol / std::abs(diffCol);

    diffRow = std::abs(diffRow), diffCol = std::abs(diffCol);


    while(diffRow > 0 || diffCol > 0)
    {
        row += moveX;
        column += moveY;
        diffRow--, diffCol--;

        int type = checkCell(row, column);

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

int MoveValidator::checkCell(int row, int column)
{
    Color oppositeColor;

    if(color == _WHITE)
        oppositeColor = _BLACK;
    else oppositeColor = _WHITE;

    bool myColor = checkForColor(board, color, row, column);
    bool diffColor = checkForColor(board, oppositeColor, row, column);

    if(myColor)
        return 1;

    if(diffColor)
        return 0;

    return -1;
}

bool MoveValidator::checkForColor(Board board, Color color, int row, int column)
{
    std::vector<Piece*> pieces = board.getPieces(color);
    for(int i = 0; i < pieces.size(); ++i)
    {
        int boardRow = pieces[i]->getRow();
        int boardColumn = pieces[i]->getColumn();
        if(boardRow == row && boardColumn == column)
            return true;
    }
    return false;
}

void MoveValidator::setBoard(Board board)
{
    this->board = board;
}

void MoveValidator::setColor(Color color)
{
    this->color = color;
}