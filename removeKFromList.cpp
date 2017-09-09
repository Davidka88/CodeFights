// $Id: removeKFromList.cpp,v 1.0 2017/08/27 23:01:18 david Exp $
/*********************************************************************
 * Given a singly linked list of integers l and an integer k, remove *
 * all elements from list l that have a value equal to k.            *
 *                                                                   *
 * https://codefights.com/interview-practice/task/gX7NXPBrYThXZuanm  *
 *********************************************************************/
// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * removeKFromList(ListNode<int> * l, int k)
{
    ListNode<int> *curr, *prev, *next;
    
	curr = l;
	while (curr != nullptr) {
        next = curr->next;
    
        if (curr->value != k) {
            prev = curr;
            curr = next;
            continue;
        }
    
        // remove this node
		if (curr == l) {	// remove header node
			l = next;
			delete curr;
			curr = l;
        } else {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
	}

	return l;
}
