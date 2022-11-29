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

    char pieceLoc[10][60];
    setPieceLocalNames(pieceLoc);
    char s1[60],s2[60],good[60];

    strcpy(s1,"WhiteOnBlack/");
    strcpy(s2,"WoW/");

    initWhitePawns(s1,s2,good);

    for(int j=1;j<=8;j++)
    {
        if(j%2==1)
            strcpy(good,s1);
        else
            strcpy(good,s2);
        initWhitePiece(good,8,j,pieceLoc[j]);
    }
}

void Painter::initWhitePiece(char good[], int i, int j, char name[])
{
    int diffLin=(i-1)*SQUARE_SIZE;
    int diffCol=(j-1)*SQUARE_SIZE;

    strcat(good,name);
    good[strlen(good)]=0;
    readimagefile(good, OFFSET_Y + diffCol, OFFSET_X + diffLin,
                      OFFSET_Y + diffCol + SQUARE_SIZE, OFFSET_X + diffLin + SQUARE_SIZE);
}

void Painter::setPieceLocalNames(char pieceLoc[10][60])
{
    strcpy(pieceLoc[1],"rook.jpg");
    strcpy(pieceLoc[2],"knight.jpg");
    strcpy(pieceLoc[3],"bishop.jpg");
    strcpy(pieceLoc[4],"queen.jpg");
    strcpy(pieceLoc[5],"king.jpg");
    strcpy(pieceLoc[6],"bishop.jpg");
    strcpy(pieceLoc[7],"knight.jpg");
    strcpy(pieceLoc[8],"rook.jpg");

}

void Painter::initWhitePawns(char s1[], char s2[], char good[])
{
    int i,j,diffLin,diffCol;
    i=7;
    diffLin=(i-1)*SQUARE_SIZE;
    for(j=1;j<=8;j++)
    {
        diffCol=(j-1)*SQUARE_SIZE;
        if(j%2==1)
            strcpy(good,s2);
        else strcpy(good,s1);
        strcat(good,"pawn.jpg");
        good[strlen(good)]=0;
        readimagefile(good, OFFSET_Y + diffCol, OFFSET_X + diffLin,
                      OFFSET_Y + diffCol + SQUARE_SIZE, OFFSET_X + diffLin + SQUARE_SIZE);
    }
}
///de schimbat numele de la folderul WoW cu litere mici si calul sa fie "knight.jpg", nu "horse.jpg" :)))
///daca nu s-a schimbat prin git deja
