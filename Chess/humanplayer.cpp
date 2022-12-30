#include "humanplayer.h"
#include <iostream>



HumanPlayer::HumanPlayer(Color color, Board board) : Player(color, board) {}


bool HumanPlayer::getMove(Board board, Piece* &piece, int &diffRow, int &diffCol)
{

    int row = -1, column = -1;
    int kind = WM_LBUTTONDOWN;

    waitForClick(kind, row, column);


    position humanPiece =
    {
        convertCoordinateX(column),
        convertCoordinateY(row)
    };

    piece = board.getPieceForPosition(humanPiece.row, humanPiece.column);

    if(piece == NULL)
        return 0;

    if(piece->getColor() == _BLACK)
        return 0;


    waitForClick(kind, row, column);

    position enemyPiece =
    {
        convertCoordinateX(column),
        convertCoordinateY(row)
    };

    diffRow = enemyPiece.row - humanPiece.row;
    diffCol = enemyPiece.column - humanPiece.column;

    Piece * EnemyPiece = board.getPieceForPosition(enemyPiece.row, enemyPiece.column);


    if(EnemyPiece != NULL && EnemyPiece->getColor() == piece->getColor())
        return 0;

    return 1;
}


void HumanPlayer::waitForClick(int kind, int &row, int &column)
{

    while(!ismouseclick(kind));
    getmouseclick(kind, row, column);
}
