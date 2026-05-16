#pragma once //do not delete this line
//head class
//player

class Player {
private:
    std::string name;
    Gem gemonhand;
    Cardgroup reservecard ;
    int score;
    Playerhand cardonhand;
    std::vector<NobilityCard> nobilityonhand;


public:
    Player(); //constructor
    void takeThreeGems(std::string color1, std::string color2, std::string color3);
    void takeTwoGems(std::string color,Board &board_gem);
    void buyCard();
    void reseraveCard();
    void checkgemlimit();
    void checkgetNobilityCard();
    /////////////////////////////////////////////////
    Gem Getgemonhand() const {return gemonhand;}
    Cardgroup Getreservecard() const {return reservecard;}
    int Getscore() const {return score;}
    Playerhand Getcardonhand() const {return cardonhand;}
    std::vector<NobilityCard> Getnobilityonhand() const {return nobilityonhand;}












};