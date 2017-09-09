/**************************************************************************
 * Given a singly linked list of integers l and a non-negative integer n, *
 * move the last n list nodes to the beginning of the linked list         *
 * https://codefights.com/interview-practice/task/5vcioHMkhGqkaQQYt       *
 **************************************************************************/
#include <iostream>
using namespace std;
// $Id: reverseNodesInKGroups.cpp,v 1.14 2017/09/08 17:20:31 david Exp david $
#define DB(A) cout << #A "=" << (A) << endl
#define DB1(A) DB(A)
#define DB2(A,B) cout << #A "=" << (A) << " " #B "=" << (B) << endl
#define DB3(A,B,C) cout << #A "=" << (A) \
                         << " " #B "=" << (B) \
						 << " " #C "=" << (C) << endl

template<typename T>
struct ListNode {
	T value;
	ListNode *next;
	ListNode(const T &v) : value(v), next(nullptr) {}
	ListNode(const T &v, ListNode<int>* const &n) : value(v), next(n) {}
};

void printlist(ListNode<int>* head)
{
	while (head != nullptr) {
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}

typedef ListNode<int> Node;	// save some typing
typedef Node* NodePtr;
Node Test24(24);
Node Test23(23, &Test24);
Node Test22(22, &Test23);
Node Test21(21, &Test22);
Node Test20(20, &Test21);
Node Test19(19, &Test20);
Node Test18(18, &Test19);
Node Test17(17, &Test18);
Node Test16(16, &Test17);
Node Test15(15, &Test16);
Node Test14(14, &Test15);
Node Test13(13, &Test14);
Node Test12(12, &Test13);
Node Test11(11, &Test12);
Node Test10(10, &Test11);
Node Test9(9, &Test10);
Node Test8(8, &Test9);
Node Test7(7, &Test8);
Node Test6(6, &Test7);
Node Test5(5, &Test6);
Node Test4(4, &Test5);
Node Test3(3, &Test4);
Node Test2(2, &Test3);
Node Test1(1, &Test2);

// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * rearrangeLastN(ListNode<int> * l, int n) {

}


int main (int argc, char *argv[])
{
	NodePtr listHead(&Test1);

	cout << "$Id: reverseNodesInKGroups.cpp,v 1.14 2017/09/08 17:20:31 david Exp david $"<< endl;
	if (argc > 1) {
		if (string(argv[1]) == "1") Test1.next = nullptr;
		if (string(argv[1]) == "2") Test2.next = nullptr;
		if (string(argv[1]) == "3") Test3.next = nullptr;
		if (string(argv[1]) == "4") Test4.next = nullptr;
		if (string(argv[1]) == "5") Test5.next = nullptr;
		if (string(argv[1]) == "6") Test6.next = nullptr;
		if (string(argv[1]) == "7") Test7.next = nullptr;
		if (string(argv[1]) == "8") Test8.next = nullptr;
		if (string(argv[1]) == "9") Test9.next = nullptr;
		if (string(argv[1]) == "10") Test10.next = nullptr;
		if (string(argv[1]) == "11") Test11.next = nullptr;
		if (string(argv[1]) == "12") Test12.next = nullptr;
		if (string(argv[1]) == "13") Test13.next = nullptr;
		if (string(argv[1]) == "14") Test14.next = nullptr;
		if (string(argv[1]) == "15") Test15.next = nullptr;
		if (string(argv[1]) == "16") Test16.next = nullptr;
		if (string(argv[1]) == "17") Test17.next = nullptr;
		if (string(argv[1]) == "18") Test18.next = nullptr;
		if (string(argv[1]) == "19") Test19.next = nullptr;
		if (string(argv[1]) == "20") Test20.next = nullptr;
		if (string(argv[1]) == "21") Test21.next = nullptr;
		if (string(argv[1]) == "22") Test22.next = nullptr;
		if (string(argv[1]) == "23") Test23.next = nullptr;
	}

	printlist(listHead);

	printlist(reverseNodesInKGroups(listHead, 6));

	return 0;
}
