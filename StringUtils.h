#ifndef STRINGUTILS_H
#define STRINGUTILS_H
#include <string>
//self explanatory, returns the number of words in str, ignoring spaces.
int countWords(const std::string& str);

//extracts the N-th word from str and returns it.
//caveat: for the first word, N=1 (human style counting).
//undefined behavior if N is not a valid word number(theres an assert for that, but dont count on it)
std::string extractNthWord(std::string& str, int N);

/**@param str: input to strip
 * @return: reference to str.
 * removes leading and trailing spaces from str.
 * */
 std::string& strip(std::string& str);

#endif //STRINGUTILS_H