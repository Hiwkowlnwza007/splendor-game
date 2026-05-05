#pragma once //do not delete this line
#include "Player.h"
#include <vector>
#include "Board.h"

class Gamemanager{
private:
    std::vector<Player> players;
    Board board;
    bool isgameover = false;
    int nowplayerindex = 0;
public:
    void setupgame();
    void startgame();
    void wincheck();
    void winnerdeclare(); 
};
