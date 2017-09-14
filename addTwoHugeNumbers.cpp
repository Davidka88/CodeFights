#define STANDALONE
#ifdef STANDALONE
// $Id: addTwoHugeNumbers.cpp,v 1.1 2017/09/01 14:34:10 david Exp david $
#define DB(A) cout << #A "=" << (A) << endl
#define DB1(A) DB(A)
#define DB2(A,B) cout << #A "=" << (A) << " " #B "=" << (B) << endl
#define DB3(A,B,C) cout << #A "=" << (A) \
                         << " " #B "=" << (B) \
						 << " " #C "=" << (C) << endl
#include <iostream>
#include <sstream>
using namespace std;

template<typename T>
struct ListNode {
	T value;
	ListNode *next;
	ListNode(const T &v) : value(v), next(nullptr) {}
	ListNode(const T &v, ListNode<int>* const &n) : value(v), next(n) {}
	ListNode() : value(0), next(nullptr) {}
};
typedef ListNode<int> Node;	// save some typing
Node Num1_24(24);
Node Num1_23(23, &Num1_24);
Node Num1_22(22, &Num1_23);
Node Num1_21(21, &Num1_22);
Node Num1_20(20, &Num1_21);
Node Num1_19(19, &Num1_20);
Node Num1_18(18, &Num1_19);
Node Num1_17(17, &Num1_18);
Node Num1_16(16, &Num1_17);
Node Num1_15(15, &Num1_16);
Node Num1_14(14, &Num1_15);
Node Num1_13(13, &Num1_14);
Node Num1_12(12, &Num1_13);
Node Num1_11(11, &Num1_12);
Node Num1_10(10, &Num1_11);
Node Num1_9(9, &Num1_10);
Node Num1_8(8, &Num1_9);
Node Num1_7(7, &Num1_8);
Node Num1_6(6, &Num1_7);
Node Num1_5(5, &Num1_6);
Node Num1_4(4, &Num1_5);
Node Num1_3(3, &Num1_4);
Node Num1_2(2, &Num1_3);
Node Num1(1, &Num1_2);

Node Num2_24(123);
Node Num2_23(122, &Num2_24);
Node Num2_22(121, &Num2_23);
Node Num2_21(120, &Num2_22);
Node Num2_20(119, &Num2_21);
Node Num2_19(118, &Num2_20);
Node Num2_18(117, &Num2_19);
Node Num2_17(116, &Num2_18);
Node Num2_16(115, &Num2_17);
Node Num2_15(114, &Num2_16);
Node Num2_14(113, &Num2_15);
Node Num2_13(112, &Num2_14);
Node Num2_12(111, &Num2_13);
Node Num2_11(110, &Num2_12);
Node Num2_10(109, &Num2_11);
Node Num2_9(108, &Num2_10);
Node Num2_8(107, &Num2_9);
Node Num2_7(106, &Num2_8);
Node Num2_6(105, &Num2_7);
Node Num2_5(104, &Num2_6);
Node Num2_4(103, &Num2_5);
Node Num2_3(102, &Num2_4);
Node Num2_2(101, &Num2_3);
Node Num2(100, &Num2_2);

Node Example2_2(8001, nullptr);
Node Example2(1, &Example2_2);

Node Example1_3(1999, nullptr);
Node Example1_2(5432, &Example1_3);
Node Example1(9876, &Example1_2);

ListNode<int> * addTwoHugeNumbers(ListNode<int> * a, ListNode<int> * b);

void printNum(ListNode<int>* head)
{
	while (head != nullptr) {
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}

int main (int argc, char *argv[])
{
	// Shorten input values, if asked to do so
	if (argc > 1) {
		stringstream(argv[1]) >> argc;

		switch (argc) {
		case 1: Num1.next = Num2.next = nullptr; break;
		case 2: Num1_2.next = Num2_2.next = nullptr; break;
		case 3: Num1_3.next = Num2_3.next = nullptr; break;
		case 4: Num1_4.next = Num2_4.next = nullptr; break;
		case 5: Num1_5.next = Num2_5.next = nullptr; break;
		case 6: Num1_6.next = Num2_6.next = nullptr; break;
		case 7: Num1_7.next = Num2_7.next = nullptr; break;
		case 8: Num1_8.next = Num2_8.next = nullptr; break;
		case 9: Num1_9.next = Num2_9.next = nullptr; break;
		case 10: Num1_10.next = Num2_10.next = nullptr; break;
		case 11: Num1_11.next = Num2_11.next = nullptr; break;
		case 12: Num1_12.next = Num2_12.next = nullptr; break;
		case 13: Num1_13.next = Num2_13.next = nullptr; break;
		case 14: Num1_14.next = Num2_14.next = nullptr; break;
		case 15: Num1_15.next = Num2_15.next = nullptr; break;
		case 16: Num1_16.next = Num2_16.next = nullptr; break;
		case 17: Num1_17.next = Num2_17.next = nullptr; break;
		case 18: Num1_18.next = Num2_18.next = nullptr; break;
		case 19: Num1_19.next = Num2_19.next = nullptr; break;
		case 20: Num1_20.next = Num2_20.next = nullptr; break;
		case 21: Num1_21.next = Num2_21.next = nullptr; break;
		case 22: Num1_22.next = Num2_22.next = nullptr; break;
		case 23: Num1_23.next = Num2_23.next = nullptr; break;
		};
	};

	printNum(&Example1);
	cout << "+" << endl;
	printNum(&Example2);
	cout << "=" << endl;
	printNum(addTwoHugeNumbers(&Example1, &Example2));

	cout << endl;

	printNum(&Num1);
	cout << "+" << endl;
	printNum(&Num2);
	cout << "=" << endl;
	printNum(addTwoHugeNumbers(&Num1, &Num2));

	return 0;
}
#endif	// STANDALONE
/***************************************************************************
 * You're given 2 huge integers represented by linked lists. Each linked   *
 * list element is a number from 0 to 9999 that represents a number with   *
 * exactly 4 digits. The represented number might have leading zeros. Your *
 * task is to add up these huge integers and return the result in the same *
 * format.                                                                 *
 *                                                                         *
 * https://codefights.com/interview-practice/task/RvDFbsNC3Xn7pnQfH        *
 *                                                                         *
 * Example:                                                                *
 * For a = [9876, 5432, 1999] and b = [1, 8001], the output should be      *
 * addTwoHugeNumbers(a, b) = [9876, 5434, 0].                              *
 *                                                                         *
 * Algorithm:                                                              *
 *         Scan a and b from head to tail,  reversing each pointer         *
 *         set carry=0                                                     *
 *         create empty answer                                             *
 *         Scan a and b from tail to head,  reversing each pointer         *
 *                 at each node, add the two + carry                       *
 *                         add sum mod 10000 to list                       *
 *                         if sum > 100 set carry to 1                     *
 *                         add sum to answer                               *
 ***************************************************************************/

// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//

typedef ListNode<int> Node;	// save some typing
ListNode<int> * addTwoHugeNumbers(ListNode<int> * a, ListNode<int> * b)
{
	struct {
		Node *a;
		Node *b;
	} head, tail, curr, prev, next;
	struct {
		unsigned a;
		unsigned b;
	} count, addend;
	Node *newNode, *returnValue;
	unsigned sum, carry;
    
	head.a = a;
	head.b = b;
	prev.a = prev.b = nullptr;

	// Traverse the lists, reversing each pointer
	count.a = count.b = 0;
	for (curr.a = head.a; curr.a != nullptr; curr.a = next.a) {
		++count.a;
		next.a = curr.a->next;
		curr.a->next = prev.a;
		prev.a = curr.a;
	}
	for (curr.b = head.b; curr.b != nullptr; curr.b = next.b) {
		++count.b;
		next.b = curr.b->next;
		curr.b->next = prev.b;
		prev.b = curr.b;
	}

	tail.a = prev.a;
	tail.b = prev.b;
	prev.a = prev.b = returnValue = nullptr;

	// Traverse the reversed lists, restoring pointers and adding values
	carry = 0;
	curr.a = tail.a;
	curr.b = tail.b;
	while (count.a > 0 || count.b >> 0) {
		sum = 0;
		if (count.a > 0) {
			--count.a;
			sum += curr.a->value;
			next.a = curr.a->next;
			curr.a->next = prev.a;
			prev.a = curr.a;
			curr.a = next.a;
		}
		if (count.b > 0) {
			--count.b;
			sum += curr.b->value;
			next.b = curr.b->next;
			curr.b->next = prev.b;
			prev.b = curr.b;
			curr.b = next.b;
		}
		sum += carry;
		carry = (sum >= 10000);
		newNode = new Node;
		newNode->value = sum % 10000;
		newNode->next = returnValue;
		returnValue = newNode;
	}

	if (carry > 0) {
		newNode = new Node;
		newNode->value = carry;
		newNode->next = returnValue;
		returnValue = newNode;
	}

	return returnValue;
}
