//
// Created by Daniella on 16/06/2023.
//
#include "Mtmchkin.h"
#include "Exception.h"
#include <iostream>
int main(){
    Mtmchkin *game=nullptr;
    try{
        game=new Mtmchkin("cards.txt");
        while(game->isGameOver()){
            game->playRound();
            game->printLeaderBoard();
        }
        delete game;
        return 0;
        }
        catch(std::bad_alloc &e){
            std::cout<<e.what()<<std::endl;
        }
        catch(std::exception& e){
            std::cout<<e.what()<<std::endl;
            delete game;
            return 0;
        }
        catch(...){
            std::cout<<"An unknown error has occurred"<<std::endl;

            return 0;
        }



    return 0;
}