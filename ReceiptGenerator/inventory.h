#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H
//class to hold all the items of a store, one instance will be created in the ReceiptGenerator.cpp file to be
//the inventory of a particular runtime

#include "item.h"
class inventory {
	private:
		// initialize the inventory here
		item milk(0001, "Horizon Milk 16oz", 50, 3.99);
	public:
};

#endif