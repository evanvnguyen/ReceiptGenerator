#pragma once
#ifndef item_h
#define item_h
#include <string>

class item {

//private variable not accessible by the program except for get/set funcitons
private:
	int SKU;
	double price;
	int amount;
	std::string name;

//constructors class and functions that need to be defined in cpp file
public:
	item();
	item(int, std::string, int, double);
	void setSKU(int);
	void setName(std::string);
	void setAmount(int);
	void setPrice(double);
	int getSKU();
	std::string getName();
	int getAmount();
	double getPrice();
};

#endif