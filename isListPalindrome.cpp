#include <iostream>
using namespace std;

// $Id: isListPalindrome.cpp,v 1.3 2017/08/30 17:21:45 david Exp david $
/****************************************************************************
 * Algorithm:                                                               *
 * Scan forward, reversing each pointer and counting N, the number of nodes *
 * When the end is reached, calculate halfN = N / 2                         *
 * scan backwards halfN nodes, reversing (i.e. restoring each pointer       *
 * set pointers to the end of the front half and the beginning of the       *
 * second half                                                              *
 * Adjust if N is odd                                                       *
 * set the default return value to true                                     *
 * scan the front half backwards; scan to back half normally                *
 * set return value false if the values at any corresponding positions      *
 * don't match                                                              *
 * restore the pointers in the front half as the scan is being done         *
 * return returnValue                                                       *
 ****************************************************************************/

/********************************************************************
 * Given a singly linked list of integers, determine whether or not *
 * it's a palindrome.                                               *
 *                                                                  *
 * https://codefights.com/interview-practice/task/HmNvEkfFShPhREMn4 *
 ********************************************************************/
template<typename T>
struct ListNode {
	ListNode(const T &v) : value(v), next(nullptr) {}
	T value;
	ListNode *next;
};
#define DBG1(A) cout << #A "=" << (A) << endl
#define DBG2(A,B) cout << #A "=" << (A) << " " #B "=" << (B) << endl
  
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
typedef ListNode<int> Node;	// save some typing
bool isListPalindrome(ListNode<int> * l)
{
	Node  *curr_1, *curr_2, *prev, *next;
	unsigned nodeCount = 0; 

	// empty and one element lists are palindromes
	if (l == nullptr)
        return true;
	if (l->next == nullptr)
		return true;

	// Traverse the list forward, reversing each pointer and counting the nodes
	prev = nullptr;
	for (curr_1 = l; curr_1 != nullptr; curr_1 = next) {
		++nodeCount;
		next = curr_1->next;
		curr_1->next = prev;
		prev = curr_1;
	}
	curr_1 = prev;

	// back up halfway, restoring the pointers
	unsigned half_nodeCount = nodeCount / 2;
	unsigned ctr = half_nodeCount;

	bool isEvenNumberOfNodes = (2 * half_nodeCount == nodeCount);
	if (! isEvenNumberOfNodes)
		++ctr;

	Node *tail = prev;
	next = nullptr;
	for (curr_1 = tail; ctr > 0; --ctr) {
		prev = curr_1->next;
		curr_1->next = next;
		next = curr_1;
		curr_2 = curr_1;
		curr_1 = prev;
	}
	if (! isEvenNumberOfNodes)
		curr_2 = curr_2-> next;

	// compare values, starting at the middle and moving outwards
	bool returnValue = true;

	while (curr_2 != nullptr) {
		if (curr_1->value != curr_2->value)
			returnValue = false;

		curr_2 = curr_2->next; // advance rear half pointer

		// restore front half pointer
		prev = curr_1->next;
		curr_1->next = next;
		next = curr_1;
		curr_1 = prev;
	}

	return returnValue;
}

int main ()
{
	Node test6(1);
	Node test5(1);
	Node test4(2);
	Node test3(3);
	Node test2(2);
	Node test1(2);

	test1.next = &test2;
	DBG1(isListPalindrome(&test1));

	return 0;
}
