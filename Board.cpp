#include "Board.h"
//board+gem
Board::Board(){
    board_gem.White = 7;
    board_gem.Blue = 7;
    board_gem.Green = 7;
    board_gem.Red = 7;
    board_gem.Black = 7;
    board_gem.Gold = 5;
}

bool Board::gemmanagement(std::string Action, Gem g){
    if(Action == "take"){
        if(board_gem.White < g.White){} return false;
        if(board_gem.Blue < g.Blue){} return false;
        if(board_gem.Green < g.Green){} return false;
        if(board_gem.Red < g.Red){} return false;
        if(board_gem.Black < g.Black){} return false;
        if(board_gem.Gold < g.Gold){} return false;

        board_gem.White -= g.White;
        board_gem.Blue -= g.Blue;
        board_gem.Green -= g.Green;
        board_gem.Red -= g.Red;
        board_gem.Black -= g.Black;
        board_gem.Gold -= g.Gold;
        return true;
    }

    if(Action == "return"){
        board_gem.White += g.White;
        board_gem.Blue += g.Blue;
        board_gem.Green += g.Green;
        board_gem.Red += g.Red;
        board_gem.Black += g.Black;
        board_gem.Gold += g.Gold;
        return true;
    }
}

void Board::replacecard(){

}