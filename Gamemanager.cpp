#include "Gamemanager.h"
#include "Cardgroup.h"
#include <iostream>
#include <fstream>   // ตัวอ่านไฟล์
#include <sstream>   // ตัวหั่นข้อความ
#include <limits> // ต้องมีอันนี้สำหรับท่าไม้กวาดกวาดขยะ
#include <algorithm>
#include <random>
#include <chrono>
#include <string>
#include <vector> 

void Gamemanager::loadDevelopmentCards(Cardgroup& deck) {
    std::ifstream file("dev_cards.csv");
    std::string line;

    if (!file.is_open()) {
        std::cout << "หาไฟล์ dev_cards.csv ไม่เจอ" << std::endl;
        return;
    }

    std::getline(file, line); // ข้ามหัวตาราง

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string temp;

        int id, t, s, w, b, g, r, k;
        std::string bonusStr; // เรายังต้องอ่านช่องโบนัสเป็นข้อความมาก่อน

        // หั่นข้อมูลจาก CSV ปกติ
        std::getline(ss, temp, ','); id = std::stoi(temp);
        std::getline(ss, temp, ','); t = std::stoi(temp);
        std::getline(ss, temp, ','); s = std::stoi(temp);
        std::getline(ss, bonusStr, ',');
        std::getline(ss, temp, ','); w = std::stoi(temp);
        std::getline(ss, temp, ','); b = std::stoi(temp);
        std::getline(ss, temp, ','); g = std::stoi(temp);
        std::getline(ss, temp, ','); r = std::stoi(temp);
        std::getline(ss, temp, ','); k = std::stoi(temp);

        // 💎 1. ประกอบร่างตะกร้า "ราคา" (Cost)
        Gem cardCost;
        cardCost.White = w;
        cardCost.Blue = b;
        cardCost.Green = g;
        cardCost.Red = r;
        cardCost.Black = k;

        // 💎 2. ประกอบร่างตะกร้า "โบนัส" (Bonus) โดยเช็กจากข้อความที่ได้มา
        Gem cardBonus;
        if (bonusStr == "White") cardBonus.White = 1;
        else if (bonusStr == "Blue") cardBonus.Blue = 1;
        else if (bonusStr == "Green") cardBonus.Green = 1;
        else if (bonusStr == "Red") cardBonus.Red = 1;
        else if (bonusStr == "Black") cardBonus.Black = 1;

        // 🔥 3. สร้างไพ่ และยัดข้อมูลลงไพ่
        DevelopmentCard newCard(id,s, cardCost, cardBonus, t);

        // 📦 ยัดการ์ดลงเด็ค
        deck.addcard(newCard);
    }

    file.close();
    std::cout << "โหลดไพ่พัฒนาเสร็จสิ้น" << std::endl;
}

void Gamemanager::loadNobiltyCards(){
    std::ifstream file("nob_cards.csv");
    std::string line;

    if (!file.is_open()) {
        std::cout << "หาไฟล์ nob_cards.csv ไม่เจอ" << std::endl;
        return;
    }

    std::getline(file, line); // ข้ามหัวตาราง

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string temp;

        int id, s, w, b, g, r, k;

        // หั่นข้อมูลจาก CSV ปกติ
        std::getline(ss, temp, ','); id = std::stoi(temp);
        std::getline(ss, temp, ','); s = std::stoi(temp);
        std::getline(ss, temp, ','); w = std::stoi(temp);
        std::getline(ss, temp, ','); b = std::stoi(temp);
        std::getline(ss, temp, ','); g = std::stoi(temp);
        std::getline(ss, temp, ','); r = std::stoi(temp);
        std::getline(ss, temp, ','); k = std::stoi(temp);

        Gem cardCost;
        cardCost.White = w;
        cardCost.Blue = b;
        cardCost.Green = g;
        cardCost.Red = r;
        cardCost.Black = k;

        NobilityCard newNoble(id,s, cardCost);

        AllNobilitycards.push_back(newNoble);
    }

    file.close();
    std::cout << "โหลดไพ่ขุนนางเสร็จสิ้น" << std::endl;

}

void Gamemanager::setupgame(){
    //รับค่าจำนวนคน
    
    while(true){
        std::cout << "[System]---Please enter the number of player [1-4] : ";
        std::cin >>num_player;
        if(std::cin.fail() || num_player < 1 || num_player > 4){
            std::cout << "[System]---Wrong number of player" << std::endl;
            std::cin.clear();
            //std::cin.ignore( จำนวนสูงสุดที่จะกวาด , สัญลักษณ์ที่จะให้หยุดกวาด );
            //std::numeric_limits<std::streamsize>::max()บอกว่าเอาจนอนันต์
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            continue;
        }

        break;
    }
    //ตั้งชื่อ
    for(int i=0;i<num_player;++i){
        std::string tempname;
        std::cout << "[System]---Enter name for Player " <<(i+1)<<" : ";
        std::cin >> tempname;

        Player newplayer;
        newplayer.setname(tempname);
        players.push_back(newplayer);
    }

    std::cout << "[System]---Preparing the game ";
    Deck dek; // alldevelopmentcard-90
    loadDevelopmentCards(dek); 

    loadNobiltyCards();
    //shuffle nobility
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto rng = std::default_random_engine(seed);
    std::shuffle(AllNobilitycards.begin(), AllNobilitycards.end(), rng);

    dek.shuffle();
    board.setupGems(num_player);

    nowplayerindex = 0;
    isgameover = false;

    std::cout << "[System]---Setup Complete! Ready to Play! " << std::endl;

    board.setupCards(dek.GetTier1(), dek.GetTier2(), dek.GetTier3(), AllNobilitycards, num_player);
    //สับไพ่

    //setupcode
}

void Gamemanager::startgame(){
    setupgame();
    while(isgameover == false){
        std::cout << "\n=============================================" << std::endl;
        std::cout << ">>> It's " << players[nowplayerindex].getname() << "'s turn! <<<" << std::endl;
        std::cout << "=============================================\n" << std::endl;

        wincheck();
    }
    winnerdeclare();
    //startcode
}

void Gamemanager::wincheck(){
    if(nowplayerindex == num_player-1){
        for(int i=0;i<players.size();i++){
            if(players[i].GetScore()>=15){
                isgameover=true;
                break;
            }
        }
    }
    

    //wincode
}

void Gamemanager::winnerdeclare(){
    std::vector<Player> score15;
    for (int i = 0; i < players.size(); i++) {
        if (players[i].GetScore() >= 15) { 
            score15.push_back(players[i]);
        }
    }

    if (score15.size() == 1) {
        std::cout << "\n=============================================" << std::endl;
        std::cout << " 🎉 WINNER IS : " << score15[0].GetName() << " !!! 🎉" << std::endl;
        std::cout << "=============================================\n" << std::endl;
    }

    else if (score15.size() > 1) {
        std::cout << "\n[System]---Tie breaker triggered! Checking development cards..." << std::endl;
        
        Player winner = score15[0];
        int min_cards = winner.cardonhand.sizecard(); 

        for (int i = 1; i < score15.size(); i++) {
            int current_cards = score15[i].cardonhand.sizecard();
            
            if (current_cards < min_cards) {
                winner = score15[i];
                min_cards = current_cards;
            }
        }

        std::cout << "\n=============================================" << std::endl;
        std::cout << " 🎉 WINNER IS : " << winner.GetName() << " !!! 🎉" << std::endl;
        std::cout << " (Won by fewest cards: " << min_cards << " cards!)" << std::endl;
        std::cout << "=============================================\n" << std::endl;
    }
    //winnerdeclarecode
}