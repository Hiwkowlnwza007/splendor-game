#include "Board.h"
//board+gem
// Board::Board(){
//     board_gem.White = 7;
//     board_gem.Blue = 7;
//     board_gem.Green = 7;
//     board_gem.Red = 7;
//     board_gem.Black = 7;
//     board_gem.Gold = 5;
// }

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
//อันนี้setupgemบนboard ละก็commentอันเก่าไว้นะ เผื่อใข้ -Key
void Board::setupGems(int num_player) {
        if (num_player == 2) {
            board_gem.White = 4;
            board_gem.Blue = 4;
            board_gem.Green = 4;
            board_gem.Red = 4;
            board_gem.Black = 4;
        } 
        else if (num_player == 3) {
            board_gem.White = 5;
            board_gem.Blue = 5;
            board_gem.Green = 5;
            board_gem.Red = 5;
            board_gem.Black = 5;
        } 
        else if (num_player == 4) {
            board_gem.White = 7;
            board_gem.Blue = 7;
            board_gem.Green = 7;
            board_gem.Red = 7;
            board_gem.Black = 7;
        }
        
        board_gem.Gold = 5; 
    }