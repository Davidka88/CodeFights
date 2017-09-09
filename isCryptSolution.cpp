// $Id: isCryptSolution.cpp,v 1.0 2017/08/27 23:01:45 david Exp david $
/****************************************************************************
 * A cryptarithm is a mathematical puzzle for which the goal is to find the *
 * correspondence between letters and digits, such that the given           *
 * arithmetic equation consisting of letters holds true when the letters    *
 * are converted to digits.                                                 *
 *                                                                          *
 * You have an array of strings crypt, the cryptarithm, and an an array     *
 * containing the mapping of letters and digits, solution. The array crypt  *
 * will contain three non-empty strings that follow the structure: [word1,  *
 * word2, word3], which should be interpreted as the word1 + word2 = word3  *
 * cryptarithm.                                                             *
 *                                                                          *
 * If crypt, when it is decoded by replacing all of the letters in the      *
 * cryptarithm with digits using the mapping in solution, becomes a valid   *
 * arithmetic equation containing no numbers with leading zeroes, the       *
 * answer is true. If it does not become a valid arithmetic solution, the   *
 * answer is false.                                                         *
 *                                                                          *
 * https://codefights.com/interview-practice/task/yM4uWYeQTHzYewW9H         *
 ****************************************************************************/
unsigned mapLetterToDigit[256];

unsigned numericValue(string word)
{
	string::iterator cp;
	unsigned answer = 0;

	for (cp = word.begin(); cp < word.end(); ++cp)
		answer = 10 * answer + mapLetterToDigit[*cp];

	return answer;
}

bool isCryptSolution(vector<string> crypt, vector<vector<char>> solution)
{
	vector<string>::iterator word;
	vector<vector<char>>::iterator row;
	unsigned ctr, value[3];

	for (row = solution.begin(); row < solution.end(); ++row)
		mapLetterToDigit[row[0][0]] = row[0][1] - '0';

	for (ctr = 0; ctr < 3; ++ctr) {
		value[ctr] = numericValue(crypt[ctr]);
		if (crypt[ctr].length() > 1 & mapLetterToDigit[crypt[ctr][0]] == 0)
			return false;
	}

	return value[0] + value[1] == value[2];
}
