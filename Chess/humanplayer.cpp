#include "humanplayer.h"
#include <iostream>



HumanPlayer::HumanPlayer(Color color, Board board) : Player(color, board) {}


void HumanPlayer::makeMove(Board board)
{
    bool isGameOpen = true;

    while(isGameOpen)
    {
        int row = -1, column = -1;
        int kind = WM_LBUTTONDOWN;

        while(!ismouseclick(kind));
        getmouseclick(kind, row, column);

        element humanPiece = {convertCoordinateX(column),
                              convertCoordinateY(row)
                             };


        bool ok = checkForSamePiece(humanPiece.row, humanPiece.column, board, color);

        if(!ok)
        {
            std::cout << "This is not your piece. Keep your hands out!\n\n";
            continue;
        }

        while(!ismouseclick(kind));
        getmouseclick(kind, row, column);

        element enemyPiece = {convertCoordinateX(column),
                              convertCoordinateY(row)
                             };

        ok = checkForSamePiece(enemyPiece.row, enemyPiece.column, board, color);

        if(ok)
        {
            std::cout << "You are supposed to love your piece, not attack it.\n";
            std::cout << "Human Player wanted to move from position " << humanPiece.row << ' ' << humanPiece.column << " to position " << enemyPiece.row << ' ' << enemyPiece.column << " attacking his own piece\n\n";
            continue;
        }

        bool isEnemyPiece = false;

        ok = checkForEnemyPiece(enemyPiece.row, enemyPiece.column, board, color);

        isEnemyPiece = ok;

        ok = isValidMove(humanPiece, enemyPiece, board, color);

        if(!ok)
        {
            std::cout << "The move is not allowed for this piece\n\n";
            continue;
        }

        std::cout << "Human player moved his piece from position " << humanPiece.row << ' ' << humanPiece.column << " to position " << enemyPiece.row << ' ' << enemyPiece.column << '\n';
        if(isEnemyPiece)
            std::cout << "The human player managed to capture an enemy piece\n\n";
        else std::cout << '\n';
    }
}

bool HumanPlayer::isValidMove(element humanPiece, element enemyPiece, Board board, Color color)
{
    std::vector <Piece*> myPieces = board.getPieces(color);
    for(int pieceIndex = 0; pieceIndex < myPieces.size(); ++pieceIndex)
    {
        int boardRow = myPieces[pieceIndex]->getRow();
        int boardColumn = myPieces[pieceIndex]->getColumn();
        if(boardRow == humanPiece.row && boardColumn == humanPiece.column)
        {
            int diffRow = enemyPiece.row - boardRow;
            int diffColumn = enemyPiece.column - boardColumn;
            bool ok2 = myPieces[pieceIndex]->isValidMove(diffRow, diffColumn);
            if(ok2)
            {
                bool ok = moveValidator.checkMove(diffRow, diffColumn, boardRow, boardColumn);
                if(ok)
                    myPieces[pieceIndex]->makeMove(diffRow, diffColumn);
                return ok;
            }
            return false;
        }
    }
}
