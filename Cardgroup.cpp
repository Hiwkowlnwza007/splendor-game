//playerhand+deck
// เพิ่มโค้ดนี้ต่อท้ายshuffleด้วย
// //แยกการ์ดพัฒนาเพื่อส่งให้board
//     std::vector<DevelopmentCard> Tier1;
//     std::vector<DevelopmentCard> Tier2;
//     std::vector<DevelopmentCard> Tier3;

//     for(int i=0;i<develop.size();++i){
//         if(develop[i].Tier==1){
//             Tier1.push_back(develop[i]);
//         }
//         if(develop[i].Tier==2){
//             Tier2.push_back(develop[i]);
//         }
//         if(develop[i].Tier==3){
//             Tier3.push_back(develop[i]);
//         }
//     }
#include "Cardgroup.h"
#include "Card.h"
#include "Gamemanager.h"
#include <algorithm>
#include <random>

void Deck::shuffle() {
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::shuffle(develop.begin(), develop.end(), rng);
    std::vector<DevelopmentCard> Tier1;
    std::vector<DevelopmentCard> Tier2;
    std::vector<DevelopmentCard> Tier3;

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