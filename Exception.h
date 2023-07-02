#include <stdexcept>
#include <string>
#ifndef EXCEPTION_H
#define EXCEPTION_H

class Exception : public std::runtime_error
{
	public:
		
		Exception()=default;
		explicit Exception(std::string message): std::runtime_error(message){};
		Exception(const Exception& other)=default;
		~Exception()=default;
};

class DeckFileNotFound : public Exception
{
	public:
	explicit DeckFileNotFound():Exception("Deck File Error: File not found"){};
};
class DeckFileFormatError : public Exception
{
	public:
	explicit DeckFileFormatError(int lineNum):Exception("Deck File Error: File format error in line "+ std::to_string(lineNum)), lineNum(lineNum) {};

	private:
		int lineNum;
};

class DeckFileInvalidSize : public Exception
{
	public:
	explicit DeckFileInvalidSize(): Exception("Deck File Error: Deck size is invalid"){};
};
 class InvalidTeamSize : public Exception
 {
 	public:
 	explicit InvalidTeamSize():Exception("Invalid team size"){};
 };

 class InvalidPlayerName : public Exception
 {
 	public:
 	explicit InvalidPlayerName():Exception("Invalid player name"){};
 };

 class InvalidPlayerClass : public Exception
 {
 	public:
 	explicit InvalidPlayerClass():Exception("Invalid player class"){};
 };

 class InvalidInput : public Exception //
 {
 	public:
 	explicit InvalidInput():Exception("Invalid input"){};
 };
 
#endif //EXCEPTION_H