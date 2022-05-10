//class that holds all the information of a particular item in inventory
#include "item.h"
#include <iostream>
#include <string>

using namespace std;

//base constructor for item where no variables are given
item::item() {
	SKU = 0;
	price = 0;
	amount = 0;
	name = "NULL";
}

//overloaded constructor for an item where everything is given
item::item(int givenSKU, string givenName, int invAmount, float givenPrice) {
	SKU = givenSKU;
	name = givenName;
	amount = invAmount;
	price = givenPrice;
}

//give the item a new SKU
void item::setSKU(int newSKU) {
	SKU = newSKU;
}

//give the item a new name
void item::setName(string newName) {
	name = newName;
}

//sets new amount of item
void item::setAmount(int newAmount) {
	amount = newAmount;
}

//sets new price of item
void item::setPrice(float newPrice) {
	price = newPrice;
}

//returns the SKU of the item
int item::getSKU() const {
	return SKU;
}

//returns the name of the item
string item::getName() const {
	return name;
}

//returns the amount of the item on hand
int item::getAmount() const {
	return amount;
}

//returns the price of the item
float item::getPrice() const {
	return price;
}

//output as string
void item::toString() const {
	std::cout << name << " " << SKU << std::endl;
}
