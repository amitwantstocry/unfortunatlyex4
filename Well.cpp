//
// Created by amito on 1/19/2023.
//

#include "Well.h"

Well::Well(): Card("Well") {

}

void Well::applyEncounter(Player &player) const {
    if(player.getJob() != "Ninja"){
        printWellMessage(false);
        player.damage(DAMAGE);
    }
    else{
        printWellMessage(true);
    }

}
