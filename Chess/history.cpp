
#include "history.h"
#include <iostream>
History* History::instance = NULL;

History::History(){}

History* History::getInstance(){
    if(instance == NULL){
        instance = new History;
    }
    return instance;
}
std::string History::convertHistoryMove(histMove lastMove){
    std::string temp;
    int ind=lastMove.ind;
    temp+=std::to_string(ind);
    temp+=". ";
    temp+=lastMove.pieceShortName;
    if(lastMove.pieceShortName==""){
        if(lastMove.isTaken==1){
            temp.push_back(char(lastMove.from.column+96));
            temp.push_back('x');
        }
    }
    else{
        temp+=lastMove.isTaken?"x":"";
    }
    temp.push_back(char(lastMove.to.column+96));
    temp.push_back(char(lastMove.to.row+48));
    ///std::cout<<temp<<'\n';
    return temp;

}
void History::addMove(Piece* piece, position start, bool Taken){
    histMove temp;
    position finish;
    finish.row = piece->getRow();
    finish.column = piece->getColumn();
    temp.from = start;
    temp.to = finish;
    temp.color=piece->getColor();
    temp.pieceShortName=piece->getShortName();
    temp.ind=moveList.size()+1;
    temp.isTaken=Taken;
    convertedMoveList.push_back(convertHistoryMove(temp));
    moveList.push_back(temp);
}
