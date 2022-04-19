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
		item(int givenSKU, std::string givenName, int givenAmount, double givenPrice);

		void setSKU(int givenSKU);
		void setName(std::string givenName);
		void setAmount(int givenAmount);
		void setPrice(double givenPrice);

		int getSKU() const;
		std::string getName() const;
		int getAmount() const;
		double getPrice() const;
};

#endif