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
        int sizecard(std::vector<DevelopmentCard> sizecard_);
};

class Playerhand : public Cardgroup {
    public :
        Gem calculategem(std::vector<DevelopmentCard> calculategem_);
};

class Deck : public Cardgroup {
    public :
        void shuffle(); //ปป ตน card devolop
        DevelopmentCard draw();
};