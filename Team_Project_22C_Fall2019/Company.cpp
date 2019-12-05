#include "Company.h"
/**
Constructor. Creates a company object with the following unique attributes
Pre: ticker - the company symbol
	 CEO - the company CEO surname
	 mcap - the company market cap in billion USD
	 stockPrice - the company stock price in USD
	 percentageChange - the company percentage change
Post:
Return:
*/
Company::Company(std::string ticker, std::string ceo, float mCap, float stockPrice, float percentChange)
{
	this->ticker = ticker;
	this->CEO = ceo;
	this->mCap = mCap;
	this->stockPrice = stockPrice;
	this->percentChange = percentChange;
}
/**
Ticker getter function
Pre:  
Post:
Return: returns the ticker 
*/
std::string Company::getTicker()
{
	return ticker;
}
/**
CEO getter function
Pre: 
Post:
Return:  returns the CEO 
*/
std::string Company::getCEO()
{
	return CEO;
}
/**
Market Cap getter function
Pre: 
Post:
Return: returns the market cap
*/
float Company::getMCap()
{
	return mCap;
}
/**
Stock price getter function
Pre: 
Post:
Return: returns the stock price
*/
float Company::getStockPrice()
{
	return stockPrice;
}
/**
Percentage change getter function
Pre: 
Post:
Return: returns the percentage changed 
*/
float Company::getPercentChange()
{
	return percentChange;
}
/**
operator overload for displaying all the data from the Company class
Pre: o references to an output stream
	 c represents the Company object
Post: make the class memebers in order for display
Return: an ostream that contains the class's datas in a format  
*/
std::ostream & operator<<(std::ostream & o, const Company c)
{
	o	<< "Ticker: " << c.ticker << "\n"
		<< "CEO: " << c.CEO << "\n"
		<< "Market Cap: " << c.mCap << "\n"
		<< "Stock Price: " << c.stockPrice << "\n"
		<< "Percent Change: " << c.percentChange;
	return o;
}