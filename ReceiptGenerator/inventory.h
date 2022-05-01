#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.h"

#include <string>

//class to hold all the items of a store, one instance will be created in the ReceiptGenerator.cpp file to be
//the inventory of a particular runtime
class inventory {
	private:

		// users scanned input
		std::string scan;

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

		// confirm SKU for validity and check its inventory
		bool confirmSKU(int scan) const;

		// get member -> get an items member variable
		std::string getName() const;
		int getAmount() const;
		float getPrice() const;

		// set members -> set the amount after specifying a purchase
		void setAmount(int numPurchased);

};

#endif