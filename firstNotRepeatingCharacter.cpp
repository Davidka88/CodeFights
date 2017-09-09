// $Id: firstNotRepeatingCharacter.cpp,v 1.0 2017/08/27 22:58:04 david Exp david $
/***************************************************************************
 * Given a string s, find and return the first instance of a non-repeating *
 * character in it. If there is no such character, return '_'.             *
 *                                                                         *
 * https://codefights.com/interview-practice/task/uX5iLwhc6L5ckSyNC        *
 ***************************************************************************/
#include <string> // codefighter left this out in their example

#define NUMBER_OF_CHARS_IN_ALPHABET 26
#define INDEX_FOR_CHARACTER(Ch) ((Ch) - 'a')	// assumes ascii
//alphabet could be string, but I think access to char array might be faster

// codefighter compiler does not accept this definition of alphabet,why?
//	static char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

char firstNotRepeatingCharacter(std::string s)
{
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	int firstOccurrencePosition[NUMBER_OF_CHARS_IN_ALPHABET];
	unsigned alph_idx;
	unsigned str_idx;
	unsigned answer_idx;
	unsigned len = s.length();
	unsigned lenPlusOne = len + 1;
	char answer = '_';	// default is  not found

	// Initialize
	for (alph_idx = 0; alph_idx < NUMBER_OF_CHARS_IN_ALPHABET; ++alph_idx)
		firstOccurrencePosition[alph_idx] = 0;

	for (str_idx = 0; str_idx < len; ++str_idx) {
		alph_idx = INDEX_FOR_CHARACTER(s[str_idx]);
		if (firstOccurrencePosition[alph_idx] == 0)
			firstOccurrencePosition[alph_idx] = str_idx + 1;
		else
			firstOccurrencePosition[alph_idx] = lenPlusOne;
	}

	// str_idx contains the value len
	answer_idx = lenPlusOne;
	for (alph_idx = 0; alph_idx < NUMBER_OF_CHARS_IN_ALPHABET; ++alph_idx) {
		str_idx = firstOccurrencePosition[alph_idx];
		if (str_idx == 0)
			continue;	// no occurrences
		if (str_idx < answer_idx) {
			answer_idx = str_idx;
			answer = alphabet[alph_idx];
		}
	}

	return answer;
}
