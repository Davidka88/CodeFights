#define STANDALONE
#define DB(A) cout << #A "=" << (A) << endl
#define DB1(A) DB(A)
#define DB2(A,B) cout << #A "=" << (A) << " " #B "=" << (B) << endl
#define DB3(A,B,C) cout << #A "=" << (A) \
                         << " " #B "=" << (B) \
						 << " " #C "=" << (C) << endl
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

typedef std::vector<std::vector<std::string>> VecTable;

class HashNode {
	friend class HashTable;
	friend ostream& operator<< (ostream& strm, const HashNode& node);
	friend ostream& operator<< (ostream& strm, const HashTable& hashTable);
private:
	string *value;
	HashNode *next; // each table entry is a linked list
public:
	bool operator==(HashNode &other)
	{
		return *this->value == *other.value;
	}
	bool operator<(HashNode &other)
	{
		return *this->value < *other.value;
	}
	string *getname()
	{
		return this->value;
	}
};

ostream& operator<< (ostream& strm, const HashNode& node)
{

	if (node.value == nullptr)
		strm << "No Value";
	else {
		HashNode *nodePtr = node.next;
		strm << *node.value;
		for (; nodePtr != nullptr; nodePtr = nodePtr->next)
			strm << " " << *nodePtr->value;
	}
    return strm;
}

class HashValue {
	friend class HashTable;
	friend ostream& operator<< (ostream& strm, const HashValue& hashValue);
private:
	short index;
	short sequence;
public:
	HashValue() :index(-1),sequence(-1) {}
	HashValue(short ind, short seq) :index(ind),sequence(seq) {}

	bool operator==(HashValue other)
	{
		return this->index == other.index && this->sequence == other.sequence;
	}
};

ostream& operator<< (ostream& strm, const HashValue& hashValue)
{
	strm << hashValue.index << "," << hashValue.sequence;
    return strm;
}

class HashTable {
	friend ostream& operator<< (ostream& strm, const HashTable& table);
private:
	static int const tableSize=1024;
	HashNode table[tableSize];

	short getTableIndex (string *input)
	{
		string::iterator ch;
		unsigned hashSum = 1;

		for (ch = input->begin(); ch < input->end(); ch++) {
			hashSum *= *ch;
			hashSum %= tableSize;
		}

		return hashSum;
	};
public:
	HashTable() {
		for (int i=0; i < tableSize; ++i) {
			table[i].value = nullptr;
			table[i].next = nullptr;
		}
	}

	// Creates hashValue if it does not exist
	HashValue getHashValue(string *input)
	{
		HashValue hashValue;
		HashNode *hashNode;
		short index;
		short sequence;

		index = getTableIndex(input);
		hashNode = &table[index];
		sequence = 0;
		for (; hashNode->next != nullptr; hashNode = hashNode->next) {
			if (*hashNode->value == *input)
				break;
			++sequence;
		}

		if (hashNode->value == nullptr)
			hashNode->value = input;

		hashValue.index = index;
		hashValue.sequence = sequence;

		return hashValue;
	}
};

ostream& operator<< (ostream& strm, const HashTable& hashTable)
{
	HashNode node;
	unsigned ctr;

	for (ctr = 0; ctr < hashTable.tableSize; ++ctr) {
		node = hashTable.table[ctr];
		if (node.value != nullptr)
			strm << setw(4) << right << ctr << ". " << node << endl;
	}

    return strm;
}

void printAnswer(VecTable &table)
{
	VecTable::iterator row;
	vector<string>::iterator item;

	for (row = table.begin(); row < table.end(); row++) {
		for (item = row->begin(); item < row->end(); item++) {
			cout << *item << " " << *item << "\t";
		}
		cout << endl;
	}
}

void loadTable(HashTable &hashTable, VecTable &table)
{
	VecTable::iterator row;
	vector<string>::iterator item;

	for (row = table.begin(); row < table.end(); row++) {
		for (item = row->begin(); item < row->end(); item++)
			hashTable.getHashValue(&*item);
	}
}

std::vector<std::vector<std::string>> groupingDishes(std::vector<std::vector<std::string>> dishes)
{
	HashTable hashTable;

	printAnswer(dishes);
	loadTable(hashTable, dishes);
	cout << hashTable;

	return dishes;
}

int main (int argc, char *argv[])
{
	VecTable testing
		{{"Salad", "Tomato", "Cucumber", "Salad", "Sauce"},
		{"Pizza", "Tomato", "Sausage", "Sauce", "Dough"},
		{"Quesadilla", "Chicken", "Cheese", "Sauce"},
		{"Sandwich", "Salad", "Bread", "Tomato", "Cheese"}};

	VecTable bigger_test
		{{"Chicken Curry", "Fried Rice", "d", "e"},
		{"f", "g", "h", "i"},
		{"x", "Garlic", "Pasta", "Quesadilla"},
		{"Tomato", "Spinach", "Dough", "Pizza"},
		{"Sandwich", "First", "Cucumber", "Cheeseeee"},
		{"Salad", "Tomato Sauce", "Nuts", "Sauce"},
		{"Second", "Sausage", "Rice", "Cheese"},
		{"Chicken", "Nut", "Bread", "Onions"},
		{"Chickens", "Curry Sauce", "a", "b"},
		{"c", "Onion", "Line 39", "Line 40"}};

	VecTable dupTest
		{{"Pasta"},
		{"Quesadilla"},
		{"Pizza"},
		{"Sandwich"}};

	groupingDishes(dupTest);

	return 0;
}
