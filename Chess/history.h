#ifndef H_HISTORY
#define H_HISTORY

#include <vector>
#include<string>
#include "config.h"
#include "piece.h"

class History {
public:
    static History* getInstance();
    std::string convertHistoryMove(histMove lastMove);
    void addMove(Piece *piece, position start, bool Taken);

private:
    History();
    static History *instance;
    std::vector<histMove> moveList;
    std::vector<std::string> convertedMoveList;
};





#endif //H_HISTORY
