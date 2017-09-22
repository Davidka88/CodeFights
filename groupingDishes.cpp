// $Id: groupingDishes.cpp,v 1.7 2017/09/22 22:29:36 david Exp david $
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
private:
	string *value;
public:
	HashNode() :value(nullptr) {}
	HashNode(const HashNode &node) :value(node.value) {}

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
	else
		strm << *node.value;

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
	friend ostream& operator<< (ostream& strm, const HashTable& hashTable);
private:
	static int const tableSize=256;
	vector<HashNode> table[tableSize];

	short calculateHash(string *input)
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
	/******************************************
	 * mapping hashvalue to name string:      *
	 * use hashvalue to access the hash table *
	 * error if index>= size of table         *
	 * row = hashtable[index]                 *
	 * error if sequence>= size of row        *
	 * get hashNode at index,sequence         *
	 * return hashNode value                  *
	 ******************************************/
	string *mapValueToString(HashValue& hashValue)
	{
		short index = hashValue.index;
		short sequence = hashValue.sequence;
		static struct {
			string index; //("hashvalue index out of range");
			string sequence; //("hashvalue sequence out of range");
		} outOfRange
			{"hashvalue index out of range",
			 "hashvalue sequence out of range"};
		static string itemNotFound("item not found");

		if (index >= tableSize)
			return &outOfRange.index;

		if (sequence > table[index].size())
			return &outOfRange.sequence;

		return table[index][sequence].value;

		return &itemNotFound;
	}

	// Creates hashValue if it does not exist
	HashValue getHashValue(string *input)
	{
		HashValue hashValue;
		HashNode hashNode;
		vector<HashNode>::iterator hn;
		short index;
		short sequence = 0;
		
		index = calculateHash(input);
		hashValue.index = index;

		/// DO WE NEED THIS
		if (table[index].size() == 0) {
			hashValue.sequence = sequence;
			hashNode.value = input;
			table[index].push_back(hashNode);
			return hashValue;
		}

		for (hn = table[index].begin(); hn < table[index].end(); ++hn) {
			if (*hn->value== *input) {
				hashValue.sequence = sequence;
				return hashValue;
			}
			++sequence;
		}

		hashNode.value = input;
		table[index].push_back(hashNode);
		hashValue.sequence = sequence;
		return hashValue;
	}
};

ostream& operator<< (ostream& strm, const HashTable& hashTable)
{
	unsigned ctr,ctr2;

	for (ctr = 0; ctr < hashTable.tableSize; ++ctr) {
		const vector<HashNode>& nodeList = hashTable.table[ctr];
		if (nodeList.size() == 0)
			continue;
		strm << ctr << ". ";
		for (ctr2 = 0; ctr2 < nodeList.size(); ++ctr2)
			strm << " " << ctr2 << ":" << nodeList[ctr2];

		strm << endl;
	}

    return strm;
}

class ResultTable {
	friend ostream& operator<< (ostream& strm, ResultTable& resTbl);
private:
	struct Member {
		HashValue nameHash;
		string name;
		short occurrences;
	};
	struct Row {
		HashValue headHash;
		string  head;
		vector<Member>members;
	};

	vector<Row> table;

public:
	void addToRow(HashValue rowHash, HashValue memberHash)
	{
		unsigned ctr;
		Row *pRow;

		for (ctr = 0; ctr < table.size(); ++ctr) {
			if (table[ctr].headHash == rowHash)
				break;
		}

		if (ctr >= table.size()) {
			Row newRow;
			newRow.headHash = rowHash;
			table.push_back(newRow);
		}

		pRow = &table[ctr];

		for (ctr = 0; ctr < pRow->members.size(); ++ctr) {
			if (pRow->members[ctr].nameHash == memberHash) {
				++pRow->members[ctr].occurrences;
				break;
			}
		}

		if (ctr >= pRow->members.size()) {
			Member newMember;
			newMember.nameHash = memberHash;
			newMember.occurrences = 1;
			pRow->members.push_back(newMember);
		}

	}

	void printTable(HashTable &hashTable)
	{
		vector<Row>::iterator vRow;
		vector<Member>::iterator vMember;

		for (vRow = table.begin(); vRow < table.end(); vRow++) {
			cout << vRow->headHash << " ";
			cout << " " << *hashTable.mapValueToString(vRow->headHash) << ":";

			vMember = vRow->members.begin(); 
			for (; vMember < vRow->members.end(); vMember++) {
				cout <<  " " << vMember->nameHash;
				cout <<  "(" << vMember->occurrences << ")";
				cout << " " << *hashTable.mapValueToString(vMember->nameHash);
			}

			cout << endl;
		}
	}
};

void printAnswer(VecTable &table)
{
	VecTable::iterator row;
	vector<string>::iterator item;

	for (row = table.begin(); row < table.end(); row++) {
		for (item = row->begin(); item < row->end(); item++)
			cout << *item << "\t";

		cout << endl;
	}
}

void loadTables(HashTable &hashT, ResultTable &resTbl, VecTable &table)
{
	VecTable::iterator row;
	vector<string>::iterator item;
	HashValue dinner;
	HashValue hashValue;

	for (row = table.begin(); row < table.end(); row++) {
		for (item = row->begin(); item < row->end(); item++) {
			hashValue = hashT.getHashValue(&*item);
			if (item == row->begin())
				dinner = hashValue;
			else
				resTbl.addToRow(hashValue, dinner);
		}
	}
}

std::vector<std::vector<std::string>> groupingDishes(std::vector<std::vector<std::string>> dishes)
{
	HashTable hashTable;
	ResultTable resultTable;

	printAnswer(dishes);
	loadTables(hashTable, resultTable, dishes);
	cout << "hashTable:" << endl;
	cout << hashTable;	// display table
	cout << "resultTable:" << endl;
	resultTable.printTable(hashTable);

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

	VecTable dupTest1
		{{"Pasta"},
		{"Quesadilla"},
		{"Pizza"},
		{"Sandwich"}};

	VecTable dupTest2
		{{"Pasta","Quesadilla"},
		 {"Pizza", "Sandwich"}};

	groupingDishes(testing);

	return 0;
}
