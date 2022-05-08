#include "inventory.h"
#include <iostream>
#include "item.h"
#include <vector>


/*
inventory::inventory() {
	
	// vector that holds all skus possible
	std::vector<int> allSku = { 0001, 0002, 0003, 0004, 0005, 0006 };

	item milk;
	item candy;
	item bread;
	item apple;
	item eggs;
	item orange;

	// initialize object args here
	milk.setSKU(allSku[0]);
	milk.setName("Horizon Milk 16oz");
	milk.setAmount(50);
	milk.setPrice(4.99);

	candy.setSKU(allSku[1]);
	candy.setName("KitKat");
	candy.setAmount(50);
	candy.setPrice(1.49);

	bread.setSKU(allSku[2]);
	bread.setName("Fresh Baguette");
	bread.setAmount(50);
	bread.setPrice(3.49);

	apple.setSKU(allSku[3]);
	apple.setName("Fiji Apple");
	apple.setAmount(50);
	apple.setPrice(0.25);

	eggs.setSKU(allSku[4]);
	eggs.setName("Organic Eggs 12ct");
	eggs.setAmount(50);
	eggs.setPrice(3.99);

	orange.setSKU(allSku[5]);
	orange.setName("Farm Fresh Oranges 6ct");
	orange.setAmount(50);
	orange.setPrice(2.99);

}
*/

// if SKU matches, confirm it's validity
bool inventory::confirmSKU(int scan) const {
	// call scan in main

	if (std::find(allSku.begin(), allSku.end(), scan) != allSku.end()) {
		// is in vector
		return true;
	}
	return false;
}
