#include "Cardgroup.h"
#include "Card.h"
#include "Gamemanager.h"
#include <algorithm>
#include <random>

void Cardgroup :: addcard(DevelopmentCard addcard_) {
    develop.push_back(addcard_);
}

void Cardgroup :: removecard(DevelopmentCard removecard_) {
    removecard_.GetId();
    develop.erase(std::remove(develop.begin(), develop.end(), removecard_), develop.end());

}

int Cardgroup :: sizecard() {
    return develop.size();
}

Gem Playerhand :: calculategem() {
    Gem total_bonus = {0,0,0,0,0,0};
    for (size_t i = 0; i < develop.size(); ++i) {
        Gem cardBonus = develop[i].GetBonuscolor(); 

        total_bonus.White += cardBonus.White;
        total_bonus.Blue  += cardBonus.Blue;
        total_bonus.Green += cardBonus.Green;
        total_bonus.Red   += cardBonus.Red;
        total_bonus.Black += cardBonus.Black;
        total_bonus.Gold  += cardBonus.Gold;
    }

    return total_bonus;
}

void Deck::shuffle() {
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::shuffle(develop.begin(), develop.end(), rng);
    for(int i=0;i<develop.size();++i){
        if(develop[i].GetTier()==1){
            Tier1.push_back(develop[i]);
        }
        if(develop[i].GetTier()==2){
            Tier2.push_back(develop[i]);
        }
        if(develop[i].GetTier()==3){
            Tier3.push_back(develop[i]);
        }
    }
}

DevelopmentCard Deck :: draw(std::vector<DevelopmentCard> draw_) {
    if (develop.empty()) {
        return DevelopmentCard(0, 0, Gem{}, Gem{}, 0);
    }
    DevelopmentCard topCard = develop.back();
    develop.pop_back();
    return topCard;
}