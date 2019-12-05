#include "Database.h"
#include "Company.h"
#include <iomanip>
/**
Constructor. read the file and store each data to the three data structures (Hash Table, Binary Tree, Link List)
Pre: filelocation represents a file path to data.txt which contains around 50 company objects
Post: opens the file and parses the entries
	  stores the entries to a specific data structure that includes their own search and sorting purposes
	  all the datas are now in the three data structures which all belong to the Database class
Return:
*/
Database::Database(std::string mainFileLoc, std::string newFileLoc)
{
	mainFile.open(mainFileLoc);

	std::string  CEO, Symbol, MarketCap, StuckPrice, PercentageChanged;

	float float_marketCap, float_sprice, float_pchanged;

	if (mainFile)
	{
		while (getline(mainFile, CEO))
		{
			//Store CEO and Symbol into hash table (key,value)
			getline(mainFile, Symbol);
			Table.insert(Symbol, CEO);
			opsPerformed++;

			//Store MarketCap and StuckPrice into BST (convert MarketCap string to float before insertion)
			getline(mainFile, MarketCap);
			float_marketCap = std::stof(MarketCap);
			Tree.insert(Symbol, float_marketCap);

			//Store Percentage Change into Linklist class (convert Stuck price and Percentaged changed from string to float before insertion)
			getline(mainFile, StuckPrice);
			getline(mainFile, PercentageChanged);

			float_sprice = std::stof(StuckPrice);
			float_pchanged = std::stof(PercentageChanged);

			List.addData(triple(Symbol, float_sprice, float_pchanged));
		}
	}
	else
		throw ("File not found!");

	mainFile.close();

	newFile.open(newFileLoc);
	if (newFile)
	{
		while (getline(newFile, Symbol))
		{
			getline(newFile, StuckPrice);
			newTable.insert(Symbol, StuckPrice);
		}
	}
	else
		throw ("File not found!");
	newFile.open(newFileLoc);
}
/**
Add the passed in datas to the three data structures in Database class ((HashTable: Symbol, CEO); (BST: Symbol, Market Cap); (LinkList:Symbol, Stuck Price, Percentage Changed))
Pre: ticker - the company symbol
	 ceo - the company CEO surname
	 macp - the company market cap in billion USD
	 sprice - the company stock price in USD
	 pchange - the company percentage change
Post: Add each datas to the three data strucutres in Database class by calling diffrent insert fucntion from each data structure  Ex. HashTable: insert() , BST: insert() , LinkList: addData()
	  Increase the opsPperformed by one for counting the operation performed
Return:
*/
void Database::add(std::string ceo, std::string ticker, float macp, float sprice, float pchange)
{
	Table.insert(ticker, ceo);
	opsPerformed++;
	Tree.insert(ticker, macp);
	List.addData(triple(ticker, sprice, pchange));
}
/**
Search a company's data by Symbol
Pre: c is the symbol we want to search for
Post: Increase the opsPperformed by one for counting the efficiency
	  check if the ticker exist and then get all the data from that target company by calling each getter functions from HashTable, BST, and LinkList
	  and then pass them to a Company object if the target exists
	  call the overlaod operator from the Company class for the target companmy's datas 
	  Increase the opsPperformed by one for counting the operation performed
Return:
*/
void Database::search(std::string c)
{
	opsPerformed++;
	if (Table.get(c) != "")
	{
		float sPrice, percentageChange;
		for (int i = 0; i < List.getCount(); i++)
		{
			if (List.getData(i).Symbol == c)
			{
				sPrice = List.getData(i).StuckPrice;
				percentageChange = List.getData(i).PercentageChanged;
				break;
			}
		}
		opsPerformed++;
		Company co(c, Table.get(c), Tree.search(c), sPrice, percentageChange);

		std::cout << co << std::endl << std::endl;
	}
}
/**
Remove all the data for a particular company
Pre:  ticker is represents the ticker of the company we want to remove
Post: check if the target exists 
	  remove it from all the data structures by calling remove() and deleatData() in the data strutures
	  Display msg if the target is removed or the targe is not found 
	  Increase the opsPperformed by one for counting the operation performed
Return:
*/
void Database::remove(std::string ticker)
{
	opsPerformed++;
	if (Table.remove(ticker))
	{
		Tree.remove(ticker);

		for (int x = 0; x < List.getCount(); x++)
		{
			if (List.getData(x).Symbol == ticker)
			{
				List.deleteData(x);
				break;
			}
		}
		std::cout << "Company Removed Successfully!!" << std::endl;
	}
	else
	{
		std::cout << "Company not found!\n";
	}
}
/**
Print the Symbol and Market Cap in a Tree-like format (Symbol is key , Market Cap is value)
Pre:  
Post: call the prettyprint function from BST 
Return:
*/
void Database::printTree()
{
	this->Tree.prettyPrint();
}
/**
Print the Symbol and CEO  in a hash table format (Symbol is key, CEO is value)
Pre:
Post: call the overload << operator from hash table so that the hash table format will be display 
Return:
*/
void Database::printhash()
{
	std::cout << this->Table;
	opsPerformed++;
}
/**
Print the Symbol and Market Cap in a sorted order(Symbol is key , CEO is value)
Pre:
Post: call the printInorder function from BST which display the tree in a sorted-order base on the Symbol (key)
Return:
*/
void Database::printkey()
{
	this->Tree.printInOrder();
}
/**
Print the Symbol and Market Cap  in a sorted order (Symbol is key, CEO is value)
Pre:
Post: call the printInorder function from BST which display the tree in a sorted-order base on the Symbol (key)
Return:
*/
void Database::printEfficiency()
{
	std::cout << "Operations performed on the hash table: " << opsPerformed << ".\n"
		<< "Load factor of the HashTable: " << Table.getLoadFactor() * 100 << "%.\n";
}
/**
Output a file to the same data.txt file 
Pre: Take the file path for the data.txt file
Post: Get all the datas from each data structures by calling thier "getter" functions (Ex.get(),search(),getData()) and write them in order to the data.txt file
Return:
*/
void Database::save(std::string fileLocation)
{
	mainFile.open(fileLocation, std::ios::trunc | std::ios::out);
	for (int i = 0; i < List.getCount(); i++)
	{
		std::string ticker = List.getData(i).Symbol;
		mainFile << Table.get(ticker) << std::endl;
		mainFile << ticker << std::endl;
		mainFile << Tree.search(ticker) << std::endl;
		mainFile << List.getData(i).StuckPrice << std::endl;
		mainFile << List.getData(i).PercentageChanged << std::endl;
	}
	mainFile.close();
}
/**
Compare two company's ticker and their datas
Pre: Take two tickers string for comparison
Post: Search if the tickers exist 
	  if the tickers are found in the data structures, store them to Company class for comparison
	  otherwise display "Wrong input!" 
	  during comparison, the function recommends the larger percentage change
Return:
*/
void Database::compare(std::string c1, std::string c2)
{
	bool found1 = false;
	bool found2 = false;

	float sPrice1, percentageChange1, sPrice2, percentageChange2;
	for (int i = 0; i < List.getCount(); i++)
	{
		if (List.getData(i).Symbol == c1)
		{
			sPrice1 = List.getData(i).StuckPrice;
			percentageChange1 = List.getData(i).PercentageChanged;
			found1 = true;
			break;
		}
	} 
	for (int i = 0; i < List.getCount() && found1; i++)
	{
		if (List.getData(i).Symbol == c2)
		{
			sPrice2 = List.getData(i).StuckPrice;
			percentageChange2 = List.getData(i).PercentageChanged;
			found2 = true;
			break;
		}
	}
	if (found1 && found2)
	{
		opsPerformed++;
		Company co1(c1, Table.get(c1), Tree.search(c1), sPrice1, percentageChange1);
		opsPerformed++;
		Company co2(c2, Table.get(c2), Tree.search(c2), sPrice2, percentageChange2);
		std::cout << co1 << std::endl << std::endl << co2 << std::endl << std::endl;
		std::cout << "I recommend buying " << (percentageChange1 > percentageChange2 ? c2 : c1) << " stock." << std::endl << std::endl;
	}
	else
	{
		std::cout << "Wrong input!\n";
	}
}
/**
Compare the same company's ticker overtime
Pre: Take one ticker string and an interger as the amoung of that ticker that the user bought in the past
Post: Search if the tickers exist
	  if the tickers are found in the data structures, compare that with the 
	  same ticker from newData.txt and tell the user how much they would have made or lost
Return:
*/
void Database::sim(std::string ticker, int count)
{
	float prevPrice, nowPrice, profit;
	bool found = false;
	for (int i = 0; i < List.getCount(); i++)
	{
		if (List.getData(i).Symbol == ticker)
		{
			prevPrice = List.getData(i).StuckPrice;
			found = true;
			break;
		}
	}
	if (!found)
	{
		std::cout << "Company not found!\n";
		return;
	}
	nowPrice = stof(newTable.get(ticker));
	profit = (nowPrice - prevPrice) * count;
	std::cout << std::setprecision(2) << std::fixed << ticker << " was priced at $" << prevPrice << " on Nov 14." << std::endl
		<< "Now, it's priced at $" << nowPrice << '.' << std::endl
		<< "If you had bought " << ticker << "on Nov 14, you would have "
		<< (profit <= 0 ? "lost $" : "made $")
		<< (profit <= 0 ? -profit : profit)
		<< ".\n\n";
}
