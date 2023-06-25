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
}