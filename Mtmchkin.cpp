#include "Mtmchkin.h"
#include <memory>
#include <fstream>
#include "Exception.h"
using std::queue;
using std::unique_ptr;

Mtmchkin::Mtmchkin(const std::string &filename) : deck(createDeck(filename)) {
	
}
	


static queue<unique_ptr<Card>> createDeck(const std::string &filename){
	std::ifstream file(filename);
	if(!file.is_open()){
		throw DeckFileNotFound();
	}
	queue<unique_ptr<Card>> deck;
	std::string line;
	int lineNum = 0;
	while(std::getline(file, line)){
		lineNum++;
		Card * currentCard = Card::createNewCard(line); //call factory method
		//handle exceptions
		deck.push(unique_ptr<Card>(currentCard)); //maybe collapse this line into the previous one, no need to ::move
	}
	if(lineNum <= Mtmchkin::MIN_DECK_SIZE){
		throw DeckFileInvalidSize();
		//make sure to not leak memory.
	}
}