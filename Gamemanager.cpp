#include "Gamemanager.h"
#include <iostream>
#include <fstream>   // ตัวอ่านไฟล์
#include <sstream>   // ตัวหั่นข้อความ
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

        int t, s, w, b, g, r, k;
        std::string bonusStr; // เรายังต้องอ่านช่องโบนัสเป็นข้อความมาก่อน

        // หั่นข้อมูลจาก CSV ปกติ
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
        DevelopmentCard newCard(s, cardCost, cardBonus, t);

        // 📦 ยัดการ์ดลงเด็ค
        deck.addcard(newCard);
    }

    file.close();
    std::cout << "โหลดไพ่พัฒนาเสร็จสิ้น" << std::endl;
}

void Gamemanager::loadNobiltyCards(std::vector<NobilityCard>& nobleList){
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

        int s, w, b, g, r, k;

        // หั่นข้อมูลจาก CSV ปกติ
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

        NobilityCard newNoble(s, cardCost);

        AllNobilitycards.push_back(newNoble);
    }

    file.close();
    std::cout << "โหลดไพ่ขุนนางเสร็จสิ้น" << std::endl;

}

void Gamemanager::setupgame(){
    
    //setupcode
}

void Gamemanager::startgame(){
    //startcode
}

void Gamemanager::wincheck(){
    //wincode
}

void Gamemanager::winnerdeclare(){
    //winnerdeclarecode
}