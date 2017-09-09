// $Id: addTwoHugeNumbers.cpp,v 1.1 2017/09/01 14:34:10 david Exp david $
#define DB(A) cout << #A "=" << (A) << endl
#define DB1(A) DB(A)
#define DB2(A,B) cout << #A "=" << (A) << " " #B "=" << (B) << endl
#define DB3(A,B,C) cout << #A "=" << (A) \
                         << " " #B "=" << (B) \
						 << " " #C "=" << (C) << endl
// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//

#if 0
Algorithm:
	Scan a and b from head to tail,  reversing each pointer
	set carry=0
	create empty answer
	Scan a and b from tail to head,  reversing each pointer
		at each node, add the two + carry
			add sum mod 10000 to list
			if sum > 100 set carry to 1
			add sum to answer
#endif
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
