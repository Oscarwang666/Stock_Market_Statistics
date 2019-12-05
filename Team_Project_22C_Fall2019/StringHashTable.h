#pragma once
#include <string>
#include <iostream>
#include "SinglyLinkedList.h"

class StringHashTable
{
private:
	struct tuple
	{
		std::string key;
		std::string value;
		tuple() {}
		tuple(std::string key, std::string value)
		{
			this->key = key;
			this->value = value;
		}
		friend std::ostream& operator<<(std::ostream& o, const tuple& t)
		{
			o << "(" << t.key << ", " << t.value << ")";
			return o;
		}
	};
	float loadFactor;
	bool isPrime(int n) const;
	int nextPrime(int start) const;
	SinglyLinkedList<tuple>* table;
	int locsUsed;
	int tableSize;
	unsigned int stringHash(std::string s) const;
	void rehash();
	bool rehashInsert(std::string key, std::string value);
	friend std::ostream& operator<<(std::ostream& o, const StringHashTable& h);

public:
	float getLoadFactor();
	std::string get(std::string key) const;
	bool insert(std::string key, std::string value);
	bool remove(std::string key);
	StringHashTable(int size);

	~StringHashTable();
};

