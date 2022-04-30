#include "inventory.h"
#include <iostream>
#include "item.h"

inventory::inventory() : milk(), candy(), bread(), apple(), eggs(), orange() {
	
	// initialize object args here
	milk.setSKU(0001);
	milk.setName("Horizon Milk 16oz");
	milk.setAmount(50);
	milk.setPrice(4.99);

	candy.setSKU(0002);
	candy.setName("KitKat");
	candy.setAmount(50);
	candy.setPrice(1.49);

	bread.setSKU(0003);
	bread.setName("Fresh Baguette");
	bread.setAmount(50);
	bread.setPrice(3.49);

	apple.setSKU(0004);
	apple.setName("Fiji Apple");
	apple.setAmount(50);
	apple.setPrice(0.25);

	eggs.setSKU(0005);
	eggs.setName("Organic Eggs 12ct");
	eggs.setAmount(50);
	eggs.setPrice(3.99);

	orange.setSKU(0006);
	orange.setName("Farm Fresh Oranges 6ct");
	orange.setAmount(50);
	orange.setPrice(2.99);

}