#include "StringHashTable.h"

/**
Internal function to find if number is prime
Pre: n - number to check if prime
Post:
Returns: true is n is prime
**/
bool StringHashTable::isPrime(int n) const
{
	if (n <= 1) return false;
	if (n <= 3) return true;

	if (n % 2 == 0 || n % 3 == 0) return false;

	for (int i = 5; i*i <= n; i += 6)
		if (n%i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}

/**
Internal function to find the next prime number
Pre: n - number to find the next prime after
Post:
Returns: Next prime number after n
**/
int StringHashTable::nextPrime(int n) const
{
	if (n <= 1) return 2;

	int prime = n;
	bool found = false;

	while (!found)
	{
		prime++;

		if (isPrime(prime))
			found = true;
	}
	return prime;
}

/**
String Hash function. Adds letters of string and modulos by table size
Pre: s - string to hash
Post:
Returns: hashed string
**/
unsigned int StringHashTable::stringHash(std::string s) const
{
	int len = s.length();
	int n = 0;
	for (int i = 0; i < len; i++)
		n += s[i];
	n %= tableSize;
	return n;
}

/**
Returns load factor of table
Pre:
Post:
Returns: load factor
**/
float StringHashTable::getLoadFactor()
{
	return loadFactor;
}

/**
Returns the value from a given key
Pre: key - key to search for
Post:
Returns: The value from a given key if found, empty string if not
**/
std::string StringHashTable::get(std::string key) const
{
	int hash = stringHash(key);
	for (int i = 0; i < table[hash].getCount(); i++)
	{
		if (table[hash].getData(i).key == key)
		{
			std::string ret = table[hash].getData(i).value;
			return ret;
		}
	}
	return "";
}

/**
Internal function used to insert in rehash(). Does not increase table size
Pre: key - key to insert
	 value - corresponding value
Post: key and value are inserted into the table
Returns: true
**/
bool StringHashTable::rehashInsert(std::string key, std::string value)
{
	int hash = stringHash(key);
	table[hash].addData(tuple(key, value));
	return true;
}

/**
Inserts into table
Pre: key - key to insert
	 value - corresponding value
Post: key and value are inserted into the table
Returns: true
**/
bool StringHashTable::insert(std::string key, std::string value)
{
	int hash = stringHash(key);
	table[hash].addData(tuple(key, value));
	locsUsed++;
	loadFactor = float(locsUsed) / float(tableSize);
	if (loadFactor >= 0.75)
		rehash();
	return true;
}

/**
Rehashes the table to the next bigger size
Pre:
Post: Table's size is the next prime. All keys are in their new appropriate position
Returns:
**/
void StringHashTable::rehash()
{
	int oldSize = tableSize;
	tableSize = nextPrime(tableSize);
	SinglyLinkedList<tuple>* oldTable = table;
	SinglyLinkedList<tuple>* newTable = new SinglyLinkedList<tuple>[tableSize];
	table = newTable;

	for (int i = 0; i < oldSize; i++)
	{
		int listSize = oldTable[i].getCount();
		for (int j = 0; j < listSize; j++)
			rehashInsert(oldTable[i].getData(j).key, oldTable[i].getData(j).value);
	}

	loadFactor = float(locsUsed) / float(tableSize);

	delete[] oldTable;
}

/**
Removes a key from the table
Pre: key - key to remove
Post: key is removed from the table
Returns: true if found and removed, false otherwise
**/
bool StringHashTable::remove(std::string key)
{
	int hash = stringHash(key);
	for (int i = 0; i < table[hash].getCount(); i++)
	{
		if (table[hash].getData(i).key == key)
		{
			table[hash].deleteData(i);
			locsUsed--;
			loadFactor = float(locsUsed) / float(tableSize);
			return true;
		}
	}
	return false;
}
/**
Constructor
Pre:  an interger as the size for the hashtabkle 
Post: store the size to the class and initialize the table pointer with a new memory address by callng new SinglyLinkedList<tuple>[tableSize]
Return:
*/
StringHashTable::StringHashTable(int size)
{
	tableSize = nextPrime(size);
	table = new SinglyLinkedList<tuple>[tableSize];
}

/**
Destructor
Pre:
Post: dynamically allocated LL array is deleted
Return:
**/
StringHashTable::~StringHashTable()
{
	delete[] table;
}

/**
<< overload
Pre: o - left operand, ostream
	 h - this
Post:
Return: the modified ostream
**/
std::ostream & operator<<(std::ostream & o, const StringHashTable& h)
{
	for (int i = 0; i < h.tableSize; i++)
	{
		if (h.table[i].getCount() == 0)
			o << i << ". x\n";
		else
			o << i << ". " << h.table[i] << "\n";
	}
	return o;
}