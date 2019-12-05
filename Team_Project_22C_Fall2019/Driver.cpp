#include "Database.h"
#include "Company.h"
#include <iostream>
#include <string>

/**
Add user input data to Database class
Pre: d - the Database object we want to store the items in
	 ticker - the company symbol
	 ceo - the company CEO surname
	 mcap - the company market cap in billion USD
	 sprice - the company stock price in USD
	 pchange - the company percentage change
Post: Add each datas to the Database class by using the add fuction from Database class 
Return:
*/
void add(Database &d, std::string ceo, std::string ticker, float mcap, float sprice, float pchange)
{
	d.add(ceo, ticker, mcap, sprice, pchange);
	std::cout << "Company Added Successfully!!" << std::endl;
}
/**
Remove all the data for a particular company
Pre: d - the Database object we want to clear the items from
	 ticker - the company symbol
Post: Remove a company's datas base on their Symbol(ticker) by calling the remove function from Datbase class
Return:
*/
void remove(Database &d, std::string ticker)
{
	d.remove(ticker);
}
/**
Convert a string to Upper case
Pre: in represents the string we want to convert to all capitalization 
Post: converts the string to its upper case by modifying the ASCII Value
Return: an capitalized version of the string variable
*/
std::string toUpper(std::string in)
{
	std::string ret = in;
	for (int i = 0; i < in.length(); i++)
	{
		if (ret[i] >= 97 && ret[i] <= 122)
			ret[i] -= 32;
	}
	return ret;
}

int main()
{
	std::string fileLoc="data.txt";
	std::string newFileLoc = "newData.txt";
	
	int n;
	bool  cont = true;
	try
	{
		Database d(fileLoc, newFileLoc);

		while (cont)
		{
			std::cout << "1. Add Company\n"
				<< "2. Remove Company\n"
				<< "3. Search and Display a Company\n"
				<< "4. List Companies in hash table sequence\n"
				<< "5. List Companies in Alphabetical Order\n"
				<< "6. Print indented tree\n"
				<< "7. Efficiency\n"
				<< "8. Compare Companies\n"
				<< "9. Stock Purchase Simulator\n"
				<< "10. Quit\n";
			std::cin >> n;
			system("cls");
			if (n == 1) {
				std::cout << "ADD COMPANY" << std::endl;
				std::string ticker, ceo, sprice, mcap, pchange;
				float float_sprice, float_mcap, float_pchange;
				std::cout << "Enter the Stock Ticker: ";
				std::cin >> ticker;
				ticker = toUpper(ticker);
				std::cout << "Enter the CEO's last name: ";
				std::cin >> ceo;
				ceo = toUpper(ceo);
				bool invalidArgument = true;
				while (invalidArgument)
				{
					try {
						std::cout << "Enter the stock price: ";
						std::cin >> sprice;
						float_sprice = stof(sprice);
						std::cout << "Enter the market cap in billions: ";
						std::cin >> mcap;
						float_mcap = stof(mcap);
						std::cout << "Enter the percentage change: ";
						std::cin >> pchange;
						float_pchange = stof(pchange);
						add(d, ceo, ticker, float_mcap, float_sprice, float_pchange);
						invalidArgument = false;
					}
					catch (std::invalid_argument)
					{
						std::cout << "Invalid input!\n";
					}
				}
				
			}
			else if (n == 2) {
				std::cout << "REMOVE COMPANY" << std::endl;
				std::string ticker;
				std::cout << "Enter the Stock Ticker: ";
				std::cin >> ticker;
				ticker = toUpper(ticker);
				remove(d, ticker);
			}
			else if (n == 3) {
				std::cout << "SEARCH COMPANY" << std::endl;
				std::string ticker;
				std::cout << "Enter the Stock Ticker: ";
				std::cin >> ticker;
				ticker = toUpper(ticker);
				std::cout << std::endl;
				d.search(ticker);
			}
			else if (n == 4) {
				d.printhash();
			}
			else if (n == 5) {
				d.printkey();
			}
			else if (n == 6) {
				d.printTree();
			}
			else if (n == 7) {
				std::cout << "HASHTABLE EFFICIENCY" << std::endl;
				d.printEfficiency();
			}
			else if (n == 8) {
				std::cout << "COMPARE COMPANIES" << std::endl;
				std::string ticker1, ticker2;
				std::cout << "Enter the ticker of the first company: ";
				std::cin >> ticker1;
				ticker1 = toUpper(ticker1);
				std::cout << "Enter the ticker of the second company: ";
				std::cin >> ticker2;
				ticker2 = toUpper(ticker2);
				system("cls");
				d.compare(ticker1, ticker2);
			}
			else if (n == 9) {
				std::string ticker;
				int count;
				std::cout << "PURCHSE SIMULATOR" << std::endl;
				std::cout << "This module simulates what would have happened if you bought a certain stock on Nov 14th and sold it today.\n";
				std::cout << "Enter a ticker: ";
				std::cin >> ticker;
				std::cout << "How many did you buy: ";
				std::cin >> count;
				std::cout << std::endl;
				d.sim(toUpper(ticker), count);
			}
			else if (n == 10) {
				std::cout << "Thank you for using our program." << std::endl;
				cont = false;
				d.save(fileLoc);
				break;
			}
			else
				std::cout << "Please enter a valid menu option!" << std::endl;
			std::cout << std::endl;
		}
	}
	catch (const char* e)
	{
		std::cout << e << std::endl;
	}
	system("pause");
}



