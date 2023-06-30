#include "StringUtils.h"
#include <string>
#include <cctype>
#include <cassert>

/**this whole file would have been redundant if i could use istringstream. 
 * this course makes me go AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA some times,
 * but mama didn't raise no quitter.
*/
int countWords(const std::string& str)
{
	int count = 0;
	bool inWord = false;
	for (char c : str)
	{
		if (isspace(c))
		{
			inWord = false;
		}
		else if (!inWord)
		{
			count++;
			inWord = true;
		}
	}
	return count;
}

std::string extractNthWord(std::string& str, int N)
//extracts the N-th word from str and returns it.
//can handle multiple spaces between words.
//returns the word without the spaces.
{
assert(N > 0 && countWords(str) >= N);
std::string word;
int wordNum = 0;
bool inWord = false;
for (char c : str)
{
	if (isspace(c))
	{
		inWord = false;
	}
	else if (!inWord)
	{
		wordNum++;
		inWord = true;
	}
	if (wordNum == N && !isspace(c))
	{
		word += c;
	}
}
return word;
}

/**
 * removes leading and trailing spaces from str.
 * i dont know if we are allowed to use this function, but i dont care
 * worst case ill rewrite it with pointers.
*/
std::string& strip(std::string& str)
{
	while (isspace(str[0]))
	{
		str.erase(0, 1);
	}
	while (isspace(str[str.length() - 1]))
	{
		str.erase(str.length() - 1, 1);
	}
	return str;
}
