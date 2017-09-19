#define STANDALONE
#ifdef STANDALONE
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

#endif // STANDALONE

typedef std::vector<std::vector<std::string>> VecTable;

struct HASHNODE {
	string *value;
	HASHNODE *next;
	bool operator==(HASHNODE &other)
	{
		return this->value == other.value;
	}
	bool operator<(HASHNODE &other)
	{
		return this->value < other.value;
	}
	string *getname()
	{
		return this->value;
	}
};

struct NAMEHASH {
	struct {
		HASHNODE *tableEntry;
		short sequence;
	} hashTable;
	string *getname()
	{
		HASHNODE *hash_1 = this->hashTable.tableEntry;
		short sequence = this->hashTable.sequence;
		for (; sequence > 0; --sequence)
			hash_1 = hash_1->next;
		return hash_1->getname();
	}
	bool operator<(NAMEHASH &other)
	{
		HASHNODE *hash_1 = this->hashTable.tableEntry;
		HASHNODE *hash_2 = other.hashTable.tableEntry;
		short sequence = this->hashTable.sequence;

		for (; sequence > 0; --sequence)
			hash_1 = hash_1->next;

		sequence = other.hashTable.sequence;
		for (; sequence > 0; --sequence)
			hash_2 = hash_2->next;
			
		return *hash_1 < *hash_2;
	}
	bool operator==(NAMEHASH &other)
	{
		HASHNODE *hash_1 = this->hashTable.tableEntry;
		HASHNODE *hash_2 = other.hashTable.tableEntry;
		short sequence = this->hashTable.sequence;

		for (; sequence > 0; --sequence)
			hash_1 = hash_1->next;

		sequence = other.hashTable.sequence;
		for (; sequence > 0; --sequence)
			hash_2 = hash_2->next;
			
		return *hash_1 == *hash_2;
	}
};

struct DISH {
	NAMEHASH name;
	short occurences;
	bool operator<(DISH &other)
	{
		return this->name < other.name;
	}
	bool operator==(DISH &other)
	{
		return this->name == other.name;
	}
};

struct INGREDIENT {
	NAMEHASH name;
	vector<DISH> dish;	// sort this
	bool operator<(NAMEHASH &other)
	{
		return *this < other;
	}
	bool operator==(NAMEHASH &other)
	{
		return *this == other;
	}
};

vector<INGREDIENT> Ingredient_List;	// sort this

class IngredientTableRow {
private:
	string *ingredient;
	vector<string *> dish;
public:
	friend ostream& operator<< (ostream& strm, const IngredientTableRow& row);
	IngredientTableRow() {};
	IngredientTableRow(vector<string *> rowx)
	{
		// I am unable to do the assignments  with an iterator
		ingredient = rowx[0];
		for (int i = 1; i < rowx.size(); ++i)
			dish.push_back(rowx[i]);
	}
};

ostream& operator<< (ostream& strm, const IngredientTableRow& row)
{
	strm << '[';
	strm << row.ingredient;
	strm << *row.dish[0];
	for (int i = 0; i < row.dish.size(); ++i)
		strm << ',' << *row.dish[i];
	//someday I'll figure out why this gives a compiler error
	//vector<string*>::iterator item;
	//for (item = row.dish.begin(); item < row.dish.end(), ++item)
		//strm << ',' << *item;
	strm << ']';

    return strm;
}

#define HASHTABLESIZE 1024

HASHNODE hashTable[HASHTABLESIZE];

unsigned hash_string (string &input)
{
	string::iterator ch;
	unsigned hashSum = 1;

	for (ch = input.begin(); ch < input.end(); ch++)
		hashSum *= *ch;

	return hashSum % HASHTABLESIZE;
}

void printTable(VecTable &table)
{
	VecTable::iterator row;
	vector<string>::iterator item;

	for (row = table.begin(); row < table.end(); row++) {
		for (item = row->begin(); item < row->end(); item++){
			cout << *item << " " << hash_string(*item) << "\t";
		}
		cout << endl;
	}
}

std::vector<std::vector<std::string>> groupingDishes(std::vector<std::vector<std::string>> dishes)
{
	printTable(dishes);
	return dishes;
}

#ifdef STANDALONE
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

	return 0;
}
#endif // STANDALONE
