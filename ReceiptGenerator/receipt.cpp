// receipt.cpp :
// Outputs the receipt onto the screen
#include <iostream>
#include "receipt.h"

using namespace std;

// card constructor
receipt::receipt(market givenStore, std::vector<item> givenCart, card givenCard, tax givenTax, double givenSum, double givenCash) {
	Store = givenStore;
	cart = givenCart;
	myCard = givenCard;
	Tax = givenTax;
	sum = givenSum;
	cash = givenCash;
}

// cash constructor
receipt::receipt(market givenStore, std::vector<item> givenCart, tax givenTax, double givenSum, double givenCash) {
	Store = givenStore;
	cart = givenCart;
	Tax = givenTax;
	sum = givenSum;
	cash = givenCash;
}

void receipt::printReceiptCard() const {
	// print out store names
	std::cout << endl;
	std::cout << "              " << Store.getName() << " #" << Store.getNumber() << endl;
	std::cout << "            " << Store.getAdd() << endl;
	std::cout << "         PHONE: " << Store.getPhone() << "\n          FAX : " << Store.getFax() << endl;
	std::cout << endl;

	// print out item and their prices
	// ->set width
	for (int i = 0; i < cart.size(); i++) {
		std::cout << endl;
		std::cout << "    " << cart[i].getSKU() << " " << cart[i].getName() << " ----- " << cart[i].getPrice();
	}

	std::cout << endl << endl << "          ";
	myCard.toString();

	// print out amount info
	// ->set width
	std::cout << endl << endl;
	printf("                         TOTAL: $%.2f", Tax.getSum());
	std::cout << std::endl << "                SALES TAX: " << Tax.getTax() * 100 << ".0";
	printf(" $%.2f", Tax.taxAmount());
	printf("\n                         TOTAL: $%.2f", Tax.calcTotal());
}

void receipt::printReceiptCash() const {
	// print out store names
	std::cout << endl;
	std::cout << "              " << Store.getName() << " #" << Store.getNumber() << endl;
	std::cout << "            " << Store.getAdd() << endl;
	std::cout << "         PHONE: " << Store.getPhone() << "\n          FAX : " << Store.getFax() << endl;
	std::cout << endl;

	// print out the items and their price
	// set the width
	for (int i = 0; i < cart.size(); i++) {
		std::cout << endl;
		std::cout << "    " << cart[i].getSKU() << " " << cart[i].getName() << " ----- " << cart[i].getPrice();
	}
	
	// print out amounts
	std::cout << endl << endl;
	printf("                         TOTAL: $%.2f", Tax.getSum());
	std::cout << std::endl << "                SALES TAX: " << Tax.getTax() * 100 << ".0";
	printf(" $%.2f", Tax.taxAmount());
	printf("\n                   CASH PAYMENT: %.2f", cash);
	printf("\n                         CHANGE: %.2f", abs(Tax.calcTotal() - cash));
	printf("\n                         TOTAL: $%.2f", Tax.calcTotal());
}

void receipt::printBarcode() const {

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