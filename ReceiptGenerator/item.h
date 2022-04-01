#pragma once
#ifndef item_h
#define item_h
#include <string>

class item {

private:
	int SKU;
	float price;
	int amount;
	string name;

public:
	item();
	item(int, string, int, float);
	void setSKU(int);
	void setName(string);
	void setAmount(int);
	void setPrice(float);
	int getSKU();
	string getName();
	int getAmount();
	float getPrice();
};

#endif