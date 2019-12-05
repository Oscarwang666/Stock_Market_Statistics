#pragma once
#include<iostream>
#include<string>

class Company
{
private:
	std::string ticker;
	std::string CEO;
	float mCap;
	float stockPrice;
	float percentChange;
public:
	Company() {};
	Company(std::string, std::string, float, float, float);

	std::string getTicker();
	std::string getCEO();
	float getMCap();
	float getStockPrice();
	float getPercentChange();

	friend std::ostream& operator<<(std::ostream& o, const Company c);
};

