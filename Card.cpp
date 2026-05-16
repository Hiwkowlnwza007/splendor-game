#include "Card.h"

//       ___   _   ___ ___  
//      / __| /_\ | _ \   \ 
//     | (__ / _ \|   / |) |
//      \___/_/ \_\_|_\___/ 
//
int Card::GetScore() const{ return score; }
int Card::GetId() const{ return id; }

//      ___  _____   _____ _    ___  ___ __  __ ___ _  _ _____    ___   _   ___ ___  
//     |   \| __\ \ / / __| |  / _ \| _ \  \/  | __| \| |_   _|  / __| /_\ | _ \   \ 
//     | |) | _| \ V /| _|| |_| (_) |  _/ |\/| | _|| .` | | |   | (__ / _ \|   / |) |
//     |___/|___| \_/ |___|____\___/|_| |_|  |_|___|_|\_| |_|    \___/_/ \_\_|_\___/ 
//
DevelopmentCard::DevelopmentCard(int id_, int s, Gem c,Gem b,int t)
    :Cost(c),Bonuscolor(b),Tier(t) { score = s; id = id_; }

Gem DevelopmentCard::GetCost() const{ return Cost; }

Gem DevelopmentCard::GetBonuscolor() const { return Bonuscolor; }

int DevelopmentCard::GetTier() const { return Tier; }

//      _  _  ___  ___ ___ _    ___ _______   __   ___   _   ___ ___  
//     | \| |/ _ \| _ )_ _| |  |_ _|_   _\ \ / /  / __| /_\ | _ \   \ 
//     | .` | (_) | _ \| || |__ | |  | |  \ V /  | (__ / _ \|   / |) |
//     |_|\_|\___/|___/___|____|___| |_|   |_|    \___/_/ \_\_|_\___/ 
//
NobilityCard::NobilityCard(int id_, int s, Gem r)
    :RequiredBonus(r) { score = s; id = id_; }

Gem NobilityCard::GetRequiredBonus() const{ return RequiredBonus; }


//card type
//Small font