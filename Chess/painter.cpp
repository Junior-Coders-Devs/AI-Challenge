#include "painter.h"

Painter::Painter() {}

void Painter::initializeWindow() {

    initwindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Chess");
}

void Painter::initializeBoard() {
    // TODO
}

void Painter::initializePieces() {
    initializeBlackPieces();
    initializeWhitePieces();
}

void Painter::initializeBlackPieces() {
    // TODO
}

void Painter::initializeWhitePieces() {

    char s1[60],s2[60],good[60];
    strcpy(s1,"WhiteOnBlack/");
    strcpy(s2,"WoW/");

    for(int j=1;j<=8;j++)
    {
        if(j%2==0)
            strcpy(good,s1);
        else
            strcpy(good,s2);
        initWhitePiece(good,7,j,"pawn.jpg");
    }

    for(int j=1;j<=8;j++)
    {
        if(j%2==1)
            strcpy(good,s1);
        else
            strcpy(good,s2);
        initWhitePiece(good,8,j,pieceLoc[j-1]);
    }
}

void Painter::initWhitePiece(char good[], int i, int j, const char name[])
{
    int diffLin=(i-1)*SQUARE_SIZE;
    int diffCol=(j-1)*SQUARE_SIZE;

    strcat(good,name);
    good[strlen(good)]=0;
    readimagefile(good, OFFSET_Y + diffCol, OFFSET_X + diffLin,
                      OFFSET_Y + diffCol + SQUARE_SIZE, OFFSET_X + diffLin + SQUARE_SIZE);
}

///de schimbat numele de la folderul WoW cu litere mici
