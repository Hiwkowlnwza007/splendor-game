//[ฝากเพิ่มnameลงในclassนี้ด้วย]=>privete
//[กับฟังก์ชันGatname(); รวมถึงฟังก์ชันsetname();ที่รับค่าnameจากภายนอกละเอาไปใส่ในprivete]=>public
#include <iostream>
#include "Player.h"
#include <string>
#include <vector>
#include "Board.h"

//function


// === Set Zero  ===
Player :: Player(){
    score = 0;
    gemonhand.White = 0 ;
    gemonhand.Blue = 0 ;
    gemonhand.Green = 0 ;
    gemonhand.Red = 0 ;
    gemonhand.Black = 0 ;
    gemonhand.Gold = 0 ;

}

// 
void Player :: takeThreeGems(std::string color1, std::string color2, std::string color3){

    if (color1 == "White") {gemonhand.White += 1 ;}
    if (color1 == "Blue") {gemonhand.Blue += 1 ;}
    if (color1 == "Green") {gemonhand.Green += 1 ;}
    if (color1 == "Red") {gemonhand.Red += 1 ;}
    if (color1 == "Black") {gemonhand.Black += 1 ;}
    if (color1 == "Gold") {gemonhand.Gold += 1 ;}

    if (color2 == "White") {gemonhand.White += 1 ;}
    if (color2 == "Blue") {gemonhand.Blue += 1 ;}
    if (color2 == "Green") {gemonhand.Green += 1 ;}
    if (color2 == "Red") {gemonhand.Red += 1 ;}
    if (color2 == "Black") {gemonhand.Black += 1 ;}
    if (color2 == "Gold") {gemonhand.Gold += 1 ;}

    if (color3 == "White") {gemonhand.White += 1 ;}
    if (color3 == "Blue") {gemonhand.Blue += 1 ;}
    if (color3 == "Green") {gemonhand.Green += 1 ;}
    if (color3 == "Red") {gemonhand.Red += 1 ;}
    if (color3 == "Black") {gemonhand.Black += 1 ;}
    if (color3 == "Gold") {gemonhand.Gold += 1 ;}

    checkgemlimit();

}


void Player :: checkgemlimit(){
while  ((gemonhand.White + gemonhand.Blue + gemonhand.Green + 
            gemonhand.Red + gemonhand.Black + gemonhand.Gold) > 10) {
       
        int totalGems = gemonhand.White + gemonhand.Blue + gemonhand.Green +      //คำนวณเหรีญปัจจุบันบนมือผู้เล่น
                        gemonhand.Red + gemonhand.Black + gemonhand.Gold;
       

        std::cout << " คุณมีเหรียญเกิน 10 เหรียญ "  << std::endl;
        std::cout << "คุณต้องคืนเหรียญอีก: " << totalGems - 10  << " เหรียญ" << std::endl;
        std::cout << "เหรียญที่คุณมีตอนนี้ -> " << "White: " << gemonhand.White << " , " << "Blue: "  << gemonhand.Blue  << " , "<< "Green: " << gemonhand.Green << " , " << "Red: "   << gemonhand.Red   << " , "<< "Black: " << gemonhand.Black << " , "<< "Gold: "  << gemonhand.Gold  << std::endl;

       
        std::string chosenColor;
        std::cout << "กรอกสีที่ต้องการคืนทีละ 1 เหรียญ (พิมพ์ White,Blue,Green,Red,Black,Gold): ";    // เอาเหรียญที่ออก
        std::cin >> chosenColor;

       
        if (chosenColor == "White" && gemonhand.White > 0) {   
            gemonhand.White - 1;
            std::cout << " คืนเหรียญ White สำเร็จ" << std::endl;
        } 
        else if (chosenColor == "Blue" && gemonhand.Blue > 0) {
            gemonhand.Blue-1;
            std::cout << " คืนเหรียญ Blue สำเร็จ" << std::endl;
        } 
        else if (chosenColor == "Green" && gemonhand.Green > 0) {
            gemonhand.Green-1;
            std::cout << " คืนเหรียญ Green สำเร็จ" << std::endl;
        } 
        else if (chosenColor == "Red" && gemonhand.Red > 0) {
            gemonhand.Red-1;
            std::cout << " คืนเหรียญ Red สำเร็จ" << std::endl;
        } 
        else if (chosenColor == "Black" && gemonhand.Black > 0) {
            gemonhand.Black-1;
            std::cout << " คืนเหรียญ Black สำเร็จ" << std::endl;
        } 
        else if (chosenColor == "Gold" && gemonhand.Gold > 0) {
            gemonhand.Gold-1;
            std::cout << " คืนเหรียญ Gold สำเร็จ" << std::endl;
        } 
        else {
           
            std::cout << " คุณไม่มีเหรียญสีนี้ให้คืน หรือพิมพ์ชื่อสีไม่ถูกต้อง กรุณากรอกใหม่" << std::endl;
        }
    }

   
    std::cout << " ตอนนี้เหรียญบนมือของคุณถูกต้องตามกฎแล้ว " << std::endl;
}




void Player :: takeTwoGems(std::string color,Board &board_gem){

    std::cout << "สีที่กองกลางเหลือมากกว่าหรือเท่ากับ 4 อัน " << std::endl;
    int canPickCount = 0; 

    if (board_gem.GetWhite() >= 4) { std::cout << " White เหลือ " << board_gem.GetWhite() << " เหรียญ" << std::endl; canPickCount = canPickCount + 1; }
    if (board_gem.GetBlue()  >= 4) { std::cout << " Blue เหลือ " << board_gem.GetBlue() << " เหรียญ" << std::endl;   canPickCount = canPickCount + 1; }
    if (board_gem.GetGreen() >= 4) { std::cout << " Green เหลือ " << board_gem.GetGreen() << " เหรียญ " << std::endl; canPickCount = canPickCount + 1; }
    if (board_gem.GetRed()   >= 4) { std::cout << " Red เหลือ " << board_gem.GetRed() << " เหรียญ" << std::endl;     canPickCount = canPickCount + 1; }
    if (board_gem.GetBlack() >= 4) { std::cout << " Black เหลือ " << board_gem.GetBlack() << " เหรียญ " << std::endl; canPickCount = canPickCount + 1; }

   
    if (canPickCount == 0) {
        std::cout << "[ ไม่สามารถทำแอคชั่นนี้ได้  ไม่มีเหรียญสีไหนในกองกลางเหลือถึง 4 เหรียญ" << std::endl;
        return; 
    }
    std::cout << "--------------------------------------------------------" << std::endl;


    
    std::string chosenColor;
    bool isSuccess = false; 

    while (isSuccess == false) {
        std::cout << "กรอกชื่อสีที่คุณต้องการหยิบเบิ้ล 2 เหรียญ: ";
        std::cin >> chosenColor;

        
        if (chosenColor == "White" && board_gem.GetWhite() >= 4) {
            gemonhand.White = gemonhand.White + 2; 
           
            isSuccess = true;                   
            std::cout << " หยิบเหรียญ White 2 อัน สำเร็จ!" << std::endl;
        }
        else if (chosenColor == "Blue" && board_gem.GetBlue() >= 4) {
            gemonhand.Blue = gemonhand.Blue + 2;
            isSuccess = true;
            std::cout << " หยิบเหรียญ Blue 2 อัน สำเร็จ!" << std::endl;
        }
        else if (chosenColor == "Green" && board_gem.GetGreen() >= 4) {
            gemonhand.Green = gemonhand.Green + 2;
            isSuccess = true;
            std::cout << " หยิบเหรียญ Green 2 อัน สำเร็จ!" << std::endl;
        }
        else if (chosenColor == "Red" && board_gem.GetRed() >= 4) {
            gemonhand.Red = gemonhand.Red + 2;
            isSuccess = true;
            std::cout << " หยิบเหรียญ Red 2 อัน สำเร็จ!" << std::endl;
        }
        else if (chosenColor == "Black" && board_gem.GetBlack() >= 4) {
            gemonhand.Black = gemonhand.Black + 2;
            isSuccess = true;
            std::cout << " หยิบเหรียญ Black 2 อัน สำเร็จ!" << std::endl;
        }
        else {
          
            std::cout << "ผิดพลาด! สีนี้ไม่สามารถหยิบเบิ้ลได้ หรือพิมพ์ชื่อสีไม่ถูกต้อง กรุณากรอกใหม่" << std::endl;
        }
    }

    
    checkgemlimit();
}

