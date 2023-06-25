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
            std::cout << "please reenter:" << std::endl;
            continue;
        }
        if(!(choice>=0 && choice<=2)){
            printInvalidInput();
            std::cout << "please reenter:" << std::endl;
            continue;
        }
    }
    return choice;
}
void Merchant::applyEncounter(Player &player) const {
    printMerchantInitialMessageForInteractiveEncounter(std::cout,player.getName(),player.getCoins());
    int choice=getChoiceFromUser();
    switch (choice) {
        case 1:
            if(player.pay(5)){
                player.heal(1);
                printMerchantSummary(std::cout,player.getName(),choice, 5);
            }
            else{
                printMerchantInsufficientCoins(std::cout);
            }
            break;
        case 2:
            if(player.pay(10)){
                player.buff(1);
                printMerchantSummary(std::cout,player.getName(),choice, 10);
            }
            else{
                printMerchantInsufficientCoins(std::cout);
            }
            break;
        default:
            return;
    }
}


