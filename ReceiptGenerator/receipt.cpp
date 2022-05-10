// receipt.cpp :
// Outputs the receipt onto the screen
#include <iostream>
#include "receipt.h"

using namespace std;

receipt::receipt(market givenStore, std::vector<item> givenCart, card givenCard, tax givenTax, double givenSum) {
	Store = givenStore;
	cart = givenCart;
	myCard = givenCard;
	Tax = givenTax;
	sum = givenSum;
}

void receipt::printReceiptCard() const {
	std::cout << endl;
	std::cout << "            " << Store.getName() << " #" << Store.getNumber() << endl;
	std::cout << "          " << Store.getAdd() << endl;
	std::cout << "       PHONE: " << Store.getPhone() << "\n        FAX : " << Store.getFax() << endl;
	std::cout << endl;

	for (int i = 0; i < cart.size(); i++) {
		std::cout << endl;
		std::cout << "    " << cart[i].getSKU() << " " << cart[i].getName() << " ----- " << cart[i].getPrice();
	}
	// get tax here
	std::cout << endl << endl;
	printf("                         TOTAL: $ %.2f", Tax.getSum());
	std::cout << std::endl << "                 SALES TAX: " << Tax.getTax()*100 << ".0   " << Tax.taxAmount() << endl;
	printf("                         TOTAL: $ %.2f", Tax.calcTotal());
}

void receipt::printReceiptCash() const {

}

void receipt::setStore(market givenStore) {
	Store = givenStore;
}

void receipt::setCart(std::vector<item> givenCart) {
	cart = givenCart;
}

void receipt::setCard(card givenCard) {
	myCard = givenCard;
}

void receipt::setTotal(double givenSum) {
	sum = givenSum;
}

market receipt::getStore() const {
	return Store;
}

std::vector<item> receipt::getCart() const {
	return cart;
}

card receipt::getCard() const {
	return myCard;
}

// pre tax total
double receipt::getTotal() const {
	return sum;
}