#define STANDALONE
// $Id: addTwoHugeNumbers.cpp,v 1.1 2017/09/01 14:34:10 david Exp david $
#define DB(A) cout << #A "=" << (A) << endl
#define DB1(A) DB(A)
#define DB2(A,B) cout << #A "=" << (A) << " " #B "=" << (B) << endl
#define DB3(A,B,C) cout << #A "=" << (A) \
                         << " " #B "=" << (B) \
						 << " " #C "=" << (C) << endl
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

typedef std::vector<std::vector<std::string>> VecTable;

std::vector<std::vector<std::string>> groupingDishes(std::vector<std::vector<std::string>> dishes) {
	return dishes;
}

static const unsigned hashTableSize(1024);

struct ItemHash {
	unsigned hashTableIndex;
	unsigned sequenceNumber;
};

struct Ingredient {
	ItemHash name;
	vector<ItemHash> dinner;
};

struct HashNode {
	string *value;
	HashNode *next;
};

HashNode hashTable[hashTableSize];

vector<HashNode> dinnerTable;

unsigned hash_string (string &input)
{
	string::iterator c;
	unsigned hashSum = 1;

	for (c = input.begin(); c < input.end(); c++)
		hashSum *= *c;

	return hashSum % hashTableSize;
}

unsigned get_hash_value(string &input)
{
	unsigned hashValue = hash_string(input);
	HashNode *curr = &hashTable[hashValue];

	while (curr->next != nullptr) {
		if (*(curr->value) == input)
			return hashValue;
		curr = curr->next;
	}

	// string not in table, curr points to last HashNode
	HashNode *newNode = new HashNode;
	newNode->value = new string(input);
	newNode->next = nullptr;
	curr->next = newNode;

	return hashValue;
}

void printTable(VecTable &table)
{
	VecTable::iterator row;
	vector<string>::iterator item;

	for (row = table.begin(); row < table.end(); row++) {
		for (item = row->begin(); item < row->end(); item++){
			cout << *item << " " << hash_string(*item) << " ";
		}
		cout << endl;
	}
}

int main (int argc, char *argv[])
{
	VecTable testing
		{{"Salad", "Tomato", "Cucumber", "Salad", "Sauce"},
		{"Pizza", "Tomato", "Sausage", "Sauce", "Dough"},
		{"Quesadilla", "Chicken", "Cheese", "Sauce"},
		{"Sandwich", "Salad", "Bread", "Tomato", "Cheese"}};

	// Shorten input values, if asked to do so
	if (argc > 1)
		stringstream(argv[1]) >> argc;

	printTable(testing);
	string str1 ("test");
	string str2 ("test1");
	DB(str1==str2);

	return 0;
}
