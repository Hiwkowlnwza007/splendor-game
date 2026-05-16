#pragma once //do not delete this line
#include "Card.h"
#include <vector>
#include <algorithm>
#include <random>

class Cardgroup {
    protected :
        std::vector<DevelopmentCard> develop;
    public :
        void addcard(DevelopmentCard addcard_);
        void removecard(DevelopmentCard removecart_);
        int sizecard();
};

class Playerhand : public Cardgroup {
    public :
        Gem calculategem();
};

class Deck : public Cardgroup {
    private :
        std::vector<DevelopmentCard> Tier1;
        std::vector<DevelopmentCard> Tier2;
        std::vector<DevelopmentCard> Tier3;
    public :
        void shuffle();
        std::vector<DevelopmentCard> getTier1() const { return Tier1; }
        std::vector<DevelopmentCard> getTier2() const  { return Tier2; }
        std::vector<DevelopmentCard> getTier3() const  { return Tier3; } 
        DevelopmentCard draw(std::vector<DevelopmentCard> draw_);
};