#pragma once
#ifndef item_h
#define item_h

#include <string>

class item {
	//private variable not accessible by the program except for get/set funcitons
	private:
		int SKU;
		std::string name;
		int amount;
		double price;

	//constructors class and functions that need to be defined in cpp file
	public:
		item();
		item(int givenSKU, std::string givenName, int invAmount, float givenPrice);

		void setSKU(int givenSKU);
		void setName(std::string givenName);
		void setAmount(int invAmount);
		void setPrice(double givenPrice);

		int getSKU() const;
		std::string getName() const;
		int getAmount() const;
		float getPrice() const;

		void toString() const;
};

#endif