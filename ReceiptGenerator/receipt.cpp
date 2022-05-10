// receipt.cpp :
// Outputs the receipt onto the screen
#include <iostream>
#include "receipt.h"
#include <iomanip>

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
	std::string wat;

	std::cout << std::endl;
	std::cout << "              " << Store.getName() << " #" << Store.getNumber() << std::endl;
	std::cout << "            " << Store.getAdd() << std::endl;
	std::cout << "         PHONE: " << Store.getPhone() << "\n          FAX : " << Store.getFax() << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < cart.size(); i++) {
		std::cout << std::fixed << "  " << cart[i].getSKU() << " " << std::setprecision(2) << std::left << std::setw(25) << cart[i].getName() << std::fixed << cart[i].getPrice() << std::endl;
	}

	std::cout << std::endl << std::endl << "          ";
	myCard.toString();

	std::cout << std::endl << std::endl;
	std::cout << "                        TOTAL: " << std::setw(7) << std::fixed << std::setprecision(2) << std::right << Tax.getSum() << std::endl;
	std::cout << "               SALES TAX " << std::fixed << std::setprecision(2) << std::right << Tax.getTax() * 100 << std::setw(9) << Tax.taxAmount() << std::endl << std::endl;
	std::cout << "                       TOTAL: " << std::setw(7) << std::fixed << std::setprecision(2) << std::right << Tax.calcTotal() << std::endl;
	printBarcode();
	std::cin >> wat;

}

void receipt::printReceiptCash() const {
	std::string wat;

	// print out store names
	std::cout << std::endl;
	std::cout << "              " << Store.getName() << " #" << Store.getNumber() << std::endl;
	std::cout << "            " << Store.getAdd() << std::endl;
	std::cout << "         PHONE: " << Store.getPhone() << "\n          FAX : " << Store.getFax() << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < cart.size(); i++) {
		std::cout << std::fixed << "  " << cart[i].getSKU() << " " << std::setprecision(2) << std::left << std::setw(25) << cart[i].getName() << std::fixed << cart[i].getPrice() << std::endl;

	}
	
	std::cout << std::endl << std::endl;
	std::cout << "                        TOTAL: " << std::setw(7) << std::fixed << std::setprecision(2) << std::right << Tax.getSum() << std::endl;
	std::cout << "               SALES TAX " << std::fixed << std::setprecision(2) << std::right << Tax.getTax() * 100 << std::setw(9) << Tax.taxAmount() << std::endl;
	std::cout << "                 CASH PAYMENT: " << std::setw(7) << std::fixed << std::setprecision(2) << std::right << cash << std::endl;
	std::cout << "                       CHANGE: " << std::setw(7) << std::fixed << std::setprecision(2) << std::right << abs(Tax.calcTotal() - cash) << std::endl << std::endl;
	std::cout << "                        TOTAL: " << std::setw(7) << std::fixed << std::setprecision(2) << std::right << Tax.calcTotal() << std::endl;
	printBarcode();
	std::cin >> wat;

}

void receipt::printBarcode() const {
	std::cout << "\n           Enjoy your visit?\n";
	std::cout << "       Head to costco.com/survey\n";
	std::cout << "        and tell us how we did!\n";
	std::cout << "        Your survey code is 4096\n";
	std::cout << "       Survey expires: 12/31/2021";

	std::cout << "\n\n  || |  |  ||| | | | ||| || |||||| | || \n";
	std::cout << "  || |  |  ||| | | | ||| || |||||| | || \n";
	std::cout << "  || |  |  ||| | | | ||| || |||||| | || \n";
	std::cout << "  || |  |  ||| | | | ||| || |||||| | || \n";
	std::cout << "  || |  |  ||| | | | ||| || |||||| | || \n";
	std::cout << "  || |  |  ||| | | | ||| || |||||| | || \n";
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