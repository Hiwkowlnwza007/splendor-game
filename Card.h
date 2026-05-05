#pragma once //do not delete this line

struct Gem{
    int White;
    int Blue;
    int Green;
    int Red;
    int Black;
    int Gold;
};

class Card{
protected:
    int score;
public:
    int GetScore() const;
};

class DevelopmentCard : public Card{
private:
    Gem Cost;
    Gem Bonuscolor;
    int Tier;
public:
    DevelopmentCard(int s, Gem c,Gem b,int t);

    Gem GetCost() const;
    Gem GetBonuscolor() const;
    int GetTier() const;
};

class NobilityCard : public Card{
private:
    Gem RequiredBonus;
public:
    NobilityCard(int s, Gem r);

    Gem GetRequiredBonus() const;
};
