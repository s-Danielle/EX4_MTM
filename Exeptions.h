#include <exception>
#include <string>

class Exeption : public std::exception
{
	public:
		std::string what(){ return message;}
		Exeption()=default;
		explicit Exeption(std::string message);
		Exeption(const Exeption& other)=default;
		~Exeption()=default;
	protected:
		std::string message;
};

class DeckFileNotFound : public Exeption
{
	explicit DeckFileNotFound(){ message = "Deck File Error: File not found"; };
};