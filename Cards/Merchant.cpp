//
// Created by Daniella on 17/06/2023.
//

#include "Merchant.h"
#include "../utilities.h"
int getChoiceFromUser(){
    string input;
    int choice=-1;
    while(choice==-1){
        std::getline(std::cin, input);
        try{
            choice= std::stoi(input);
        }
        catch (std::exception&){
            printInvalidInput();
            choice=-1;
            continue;
        }
        if(!(choice>=0 && choice<=2)){
            choice=-1;
            printInvalidInput();
            continue;
        }
    }
    return choice;
}

void Merchant::applyEncounter(Player &player) const {
    printMerchantInitialMessageForInteractiveEncounter(std::cout,player.getName(),player.getCoins());
    int choice=getChoiceFromUser();
    switch (choice) {
        case 0://NOTHING
            printMerchantSummary(std::cout,player.getName(),choice, 0);
            return;
        case 1://HEAL
            if(player.pay(HEAL_COST)){
                player.heal(HEAL_AMOUNT);
                printMerchantSummary(std::cout,player.getName(),choice, HEAL_COST);
                return;
            }
            else{
                printMerchantInsufficientCoins(std::cout);
                printMerchantSummary(std::cout,player.getName(),choice, 0);
                return;
            }
        case 2://BUFF
            if(player.pay(BUFF_COST)){
                player.buff(BUFF_AMOUNT);
                printMerchantSummary(std::cout,player.getName(),choice, BUFF_COST);
                return;
            }
            else{
                printMerchantInsufficientCoins(std::cout);
                printMerchantSummary(std::cout,player.getName(),choice, 0);
                return;
            }

        default://IF YOU HAVE ISSUES CHECK HERE
            return;
    }
}


