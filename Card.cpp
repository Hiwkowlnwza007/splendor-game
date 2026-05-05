#include "Card.h"

//CARD
int Card::GetScore() const{ return score; }

//DEVELOPMENTCARD
DevelopmentCard::DevelopmentCard(int s, Gem c,Gem b,int t)
    :Cost(c),Bonuscolor(b),Tier(t) { score = s; }

Gem DevelopmentCard::GetCost() const{ return Cost; }

Gem DevelopmentCard::GetBonuscolor() const { return Bonuscolor; }

int DevelopmentCard::GetTier() const { return Tier; }

//NOBILITYCARD
NobilityCard::NobilityCard(int s, Gem r)
    :RequiredBonus(r) { score = s; }

Gem NobilityCard::GetRequiredBonus() const{ return RequiredBonus; }


//card type