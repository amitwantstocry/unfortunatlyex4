//
// Created by amito on 1/19/2023.
//

#include "Merchant.h"

Merchant::Merchant():Card("Merchant") {

}

void Merchant::applyEncounter(Player &player) const {
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    string input;
    while(true){
        getline(std::cin, input);
        if(input == HEAL_POTION) {
            if(player.pay(POTION_PRICE)){
                player.heal(HEAL_POINTS);
                printMerchantSummary(std::cout, player.getName(), 1, POTION_PRICE);
            }
            else{
                printMerchantInsufficientCoins(std::cout);
                printMerchantSummary(std::cout, player.getName(), 1, 0);
            }
            break;
        }
        else if(input == FORCE_BOOST){
            if(player.pay(BOOST_PRICE)){
                player.buff(FORCE_BUFF);
                printMerchantSummary(std::cout, player.getName(), 2, BOOST_PRICE);
            }
            else{
                printMerchantInsufficientCoins(std::cout);
                printMerchantSummary(std::cout, player.getName(), 2, 0);
            }
            break;
        }
        else if(input == EXIT){
            printMerchantSummary(std::cout, player.getName(), 0, 0);
            break;
        }
        else{
            printInvalidInput();
        }
    }


}
