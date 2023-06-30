#include <exception>
#include <string>
#ifndef EXCEPTION_H
#define EXCEPTION_H

class Exception : public std::exception
{
	public:
		std::string what(){ return m_message;}
		Exception()=default;
		explicit Exception(std::string message): m_message(message){};
		Exception(const Exception& other)=default;
		~Exception() override=default;
	protected:
		std::string m_message;
};

class DeckFileNotFound : public Exception
{
	public:
	explicit DeckFileNotFound(){m_message="Deck File Error: File not found";};
};
class DeckFileFormatError : public Exception
{
	public:
	explicit DeckFileFormatError(int lineNum): lineNum(lineNum) { m_message = "Deck File Error: File format error in line "+ std::to_string(lineNum); };

	private:
		int lineNum;
};

class DeckFileInvalidSize : public Exception
{
	public:
	explicit DeckFileInvalidSize(){ m_message = "Deck File Error: Deck size is invalid"; };
};
 class InvalidTeamSize : public Exception
 {
 	public:
 	explicit InvalidTeamSize(){ m_message = "Invalid team size"; };
 };

 class InvalidPlayerName : public Exception
 {
 	public:
 	explicit InvalidPlayerName(){ m_message = "Invalid player name"; };
 };

 class InvalidPlayerClass : public Exception
 {
 	public:
 	explicit InvalidPlayerClass(){ m_message = "Invalid player class"; };
 };

 class InvalidInput : public Exception //
 {
 	public:
 	explicit InvalidInput(){ m_message = "Invalid input"; };
 };
 
#endif //EXCEPTION_H