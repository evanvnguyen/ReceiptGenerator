#include "item.h"
#include <iostream>

using namespace std;

item::item()
{
	SKU = 0;
	price = 0;
	amount = 0;
	name = "NULL";
}

item::item(int givenSKU, string givenName, int givenAmount, float givenPrice)
{
	SKU = givenSKU;
	name = givenName;
	amount = givenAmount;
	price = givenPrice;
}



void item::setSKU(int newSKU)
{
	SKU = newSKU;
}

void item::setName(string newName)
{
	name = newName;
}



void item::setAmount(int newAmount)
{
	amount = newAmount;
}

void item::setPrice(float newPrice)
{
	price = newPrice;
}

int item::getSKU()
{
	return SKU;
}

string item::getName()
{
	return name;
}

int item::getAmount()
{
	return amount;
}

float item::getPrice()
{
	return price;
}
