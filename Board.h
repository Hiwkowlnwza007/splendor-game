#pragma once //do not delete this line
#include "Card.h"
#include <vector>
#include <string>
//board ไม่ต้องเขียนgemแล้ว คีย์เขียนละ
class Board{
    private:
        Gem board_gem;
        std::vector<NobilityCard> board_nobility;
        std::vector<DevelopmentCard> board_development;
        //std::vector<Deck> board_deck;

    public:
        bool gemmanagement(std::string Action, Gem g);
        void replacecard();
        void setupGems(int num_player);
};