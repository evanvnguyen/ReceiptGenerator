#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H
//class to hold all the items of a store, one instance will be created in the ReceiptGenerator.cpp file to be
//the inventory of a particular runtime

#include "item.h"
class inventory {
	private:

		// initialize inventory items here
		item milk;
		item candy;
		item bread;
		item apple;
		item eggs;
		item orange;

	public:

		// inventory is composed of these item objects
		inventory() : milk(), candy(), bread(), apple(), eggs(), orange() {};

		// get member -> get an items member 
		int getSKU() const;
		std::string getName() const;
		int getAmount() const;
		float getPrice() const;

		// set members -> set the amount after specifying a purchase
		void setAmount(int numPurchased);

};

#endif