// $Id: mergeTwoLinkedLists.cpp,v 1.0 2017/09/02 00:50:24 david Exp david $
#define DB(A) cout << #A "=" << (A) << endl
#define DB1(A) DB(A)
#define DB2(A,B) cout << #A "=" << (A) << " " #B "=" << (B) << endl
#define DB3(A,B,C) cout << #A "=" << (A) \
                         << " " #B "=" << (B) \
						 << " " #C "=" << (C) << endl

typedef ListNode<int> Node;	// save some typing
typedef ListNode<int>* NodePtr;

// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * mergeTwoLinkedLists(ListNode<int> * l1, ListNode<int> * l2)
{
	struct {
		NodePtr head, curr;
	} merged;
	struct {
		NodePtr one, two;
	} currNode;
	struct {
		int list1, list2;
	} value;
	struct {
		bool list1, list2;
	} addFrom;
	NodePtr newNode;

	currNode.one = l1;
	currNode.two = l2;
	merged.head = nullptr;

	while (currNode.one != nullptr && currNode.two != nullptr) {
		value.list1 = currNode.one->value;
		value.list2 = currNode.two->value;
		newNode = new Node;
		if (value.list1 == value.list2) {
			newNode->value = value.list1;
			addFrom.list1 = addFrom.list2 = true;
		} else if (value.list1 < value.list2) {
			newNode->value = value.list1;
			addFrom.list1 = true;
			addFrom.list2 = false;
		} else { // value.list2 < value.list1
			newNode->value = value.list2;
			addFrom.list1 = false;
			addFrom.list2 = true;
		}
		newNode->next = nullptr;

		if (addFrom.list1) {
			if (merged.head == nullptr)
				merged.head = merged.curr = newNode;
			else {
				merged.curr->next = newNode;
				merged.curr = newNode;
			}
			if (addFrom.list2) {
				newNode = new Node;
				*newNode = *merged.curr;
			}
			currNode.one = currNode.one->next;
		}

		if (addFrom.list2) {
			if (merged.head == nullptr)
				merged.head = merged.curr = newNode;
			else {
				merged.curr->next = newNode;
				merged.curr = newNode;
			}
			currNode.two = currNode.two->next;
		}
	}
	
	// At most one input list has not been scanned
	while (currNode.one != nullptr) {
		newNode = new Node;
		newNode->value = currNode.one->value;
		newNode->next = nullptr;
		if (merged.head == nullptr)
			merged.head = merged.curr = newNode;
		else {
			merged.curr->next = newNode;
			merged.curr= newNode;
		}
		currNode.one = currNode.one->next;
	}
	
	while (currNode.two != nullptr) {
		newNode = new Node;
		newNode->value = currNode.two->value;
		newNode->next = nullptr;
		if (merged.head == nullptr)
			merged.head = merged.curr = newNode;
		else {
			merged.curr->next = newNode;
			merged.curr= newNode;
		}
		currNode.two = currNode.two->next;
	}

	return merged.head;
}
