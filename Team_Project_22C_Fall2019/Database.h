#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "BST.h"
#include "StringHashTable.h"
#include "SinglyLinkedList.h"

class Database
{
private:

	std::fstream mainFile;
	std::ifstream newFile;

	//BST: 
	BST<std::string, float> Tree;

	//HashTable 
	int TableSize = 50;
	StringHashTable Table = StringHashTable(TableSize);
	StringHashTable newTable = StringHashTable(TableSize);
	int opsPerformed;

	//LinkList 
	struct triple
	{
		std::string Symbol;
		float StuckPrice, PercentageChanged;
		triple() {};
		triple(std::string symbol, float stuckprice, float pchanged)
		{
			Symbol = symbol;
			StuckPrice = stuckprice;
			PercentageChanged = pchanged;
		};

	};
	SinglyLinkedList<triple> List;
	
public:

	Database(std::string mainFileLoc, std::string newFileLoc);

	void add(std::string ceo, std::string ticker, float macp, float sprice, float pchange);

	void search(std::string c1);

	void remove(std::string ticker);

	void printTree();

	void printhash();

	void printkey();

	void printEfficiency();

	void save(std::string fileLocation);

	void compare(std::string c1, std::string c2);

	void sim(std::string ticker, int count);
};

