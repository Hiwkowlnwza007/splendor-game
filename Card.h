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
    int id;
public:
    int GetScore() const;
    int GetId() const;
};

class DevelopmentCard : public Card{
private:
    Gem Cost;
    Gem Bonuscolor;
    int Tier;
public:
    DevelopmentCard(int id_, int s, Gem c,Gem b,int t);

    Gem GetCost() const;
    Gem GetBonuscolor() const;
    int GetTier() const;
};

class NobilityCard : public Card{
private:
    Gem RequiredBonus;
public:
    NobilityCard(int id_, int s, Gem r);

    Gem GetRequiredBonus() const;
};
