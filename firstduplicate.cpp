// $Id: firstduplicate.cpp,v 1.0 2017/08/27 23:01:37 david Exp david $
/****************************************************************************
 * Given an array a that contains only numbers in the range from 1 to       *
 * a.length, find the first duplicate number for which the second           *
 * occurrence has the minimal index. In other words, if there are more than *
 * 1 duplicated numbers, return the number for which the second occurrence  *
 * has a smaller index than the second occurrence of the other number does. *
 * If there are no such elements, return -1.                                *
 *                                                                          *
 * https://codefights.com/interview-practice/task/pMvymcahZ8dY4g75q         *
 ****************************************************************************/
#define VALUE_TO_INDEX(Arry,Index_in) (abs(Arry[Index_in]) - 1)
int firstDuplicate(std::vector<int> a)
{
	unsigned i,j;
	unsigned vector_size = a.size();
	int return_value = -1;	// default is not found

	for (i = 0; i < vector_size; ++i) {
		j = VALUE_TO_INDEX(a,i);
		if (a[j] < 0) {
			return_value = j + 1;
			break;
		}
		a[j] = -a[j];	// indicate that the value matching this index is found
	}

	for (i = 0; i < vector_size; ++i) 
		a[i] = abs(a[1]);

	return return_value;
}
