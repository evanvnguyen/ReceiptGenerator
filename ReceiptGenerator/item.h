#pragma once
#ifndef item_h
#define item_h

#include <string>

class item {
	private:
		int SKU;
		std::string name;
		int amount;
		float price;

	public:
		item();
		item(int givenSKU, std::string givenName, int invAmount, float givenPrice);

		void setSKU(int givenSKU);
		void setName(std::string givenName);
		void setAmount(int invAmount);
		void setPrice(float givenPrice);

		int getSKU() const;
		std::string getName() const;
		int getAmount() const;
		float getPrice() const;

		void toString() const;
};

#endif