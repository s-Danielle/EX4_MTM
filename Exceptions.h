#include <exception>
#include <string>

class Exception : public std::exception
{
	public:
		std::string what(){ return message;}
		Exception()=default;
		explicit Exception(std::string message);
		Exception(const Exception& other)=default;
		~Exception()=default;
	protected:
		std::string message;
};

class DeckFileNotFound : public Exception
{
	explicit DeckFileNotFound(){ message = "Deck File Error: File not found"; };
};