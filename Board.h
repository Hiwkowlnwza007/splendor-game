#pragma once //do not delete this line
#include "Card.h"
#include "Cardgroup.h"
#include <vector>
#include <string>
//board ไม่ต้องเขียนgemแล้ว คีย์เขียนละ
class Board{
    private:
        Gem board_gem;
        std::vector<NobilityCard> board_nobility;
        std::vector<DevelopmentCard> board_development_tier1;
        std::vector<DevelopmentCard> board_development_tier2;
        std::vector<DevelopmentCard> board_development_tier3;
        Deck board_deck_tier1;
        Deck board_deck_tier2;
        Deck board_deck_tier3;

    public:
        bool gemmanagement(std::string Action, Gem g);//เช็คจำนวนgem บนboard
        void replacecard(int tier, int index); //จั่วการ์ดเพิ่ม
        void setupGems(int num_player);//ตั้งค่าgemบนboardตามจำนวนผู้เล่น
        void setupCards(std::vector<DevelopmentCard>& tier1,//ตั้งค่าการ์ดบนboardตามจำนวนผู้เล่น 
            std::vector<DevelopmentCard>& tier2, 
            std::vector<DevelopmentCard>& tier3, 
            std::vector<NobilityCard>& nobilityCards, 
            int num_player);
};