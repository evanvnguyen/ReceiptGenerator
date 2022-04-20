#include "card.h"
#include <iostream>
#include <cmath>
#include <string>

card::card() {
	cardNum = 0;
	expDate = 0;
	cardType = "NULL";
	CVV = 0;
}

card::card(long int givenCardNum, int givenExpDate, int givenCVV) {
	cardNum = givenCardNum;
	expDate = givenExpDate;
	cardType = setCardType(givenCardNum); // to be altered by setCardType();
	CVV = givenCVV;
}

card::~card() {

}

void card::setCardNum(long int givenCardNum) {
	cardNum = givenCardNum;
}

std::string card::setCardType(long int givenCardNum) {

	// get length
	int numLength = std::to_string(givenCardNum).length();

	// get first digit
	long int temp = givenCardNum;
	long int num = floor(log10(temp)) + 1;
	int first = temp / (int)pow(10, num - 1);

	// console debug
	std::cout << givenCardNum << std::endl;
	std::cout << "first digit: " << first << std::endl;
	std::cout << "length: " << numLength << std::endl;


	// visa (if card length 13-19 and first digit = 4
	if ((numLength == 13) && (first == 4)) {
		cardType = "Visa";
	}
	// amex 
	else if ((numLength == 16) && (first == 5)) {
		cardType = "Mastercard";
	}
	// mastercard
	else if ((numLength == 15) && (first == 3)) {
		cardType = "American Express";
	}
	// discover
	else if ((numLength == 16) && (first == 6)) {
		cardType = "Discover";
	}
	else {
		cardType = "INVALID"; // raise an exception
	}

	return cardType;
}

void card::setExpDate(int givenExpDate) {
	expDate = givenExpDate;

}

void card::setCVV(int givenCVV) {
	CVV = givenCVV;

}

int card::getCardNum() const {
	return cardNum;
}

std::string card::getCardType() const {
	return cardType;
}

int card::getExpDate() const {
	return expDate;
}

int card::getCVV() const {
	return CVV;
}

