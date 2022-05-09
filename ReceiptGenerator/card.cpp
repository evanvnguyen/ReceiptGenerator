#include "card.h"
#include <iostream>
#include <cmath>
#include <string>

card::card() {
	cardNum = "NULL";
	expDate = 0;
	cardType = "NULL";
	CVV = 0;
}

card::card(std::string givenCardNum, int givenExpDate, int givenCVV) {
	cardNum = givenCardNum;
	expDate = givenExpDate;
	cardType = setCardType(givenCardNum); // to be altered by setCardType();
	CVV = givenCVV;
}

card::~card() {

}

void card::setCardNum(std::string givenCardNum) {
	cardNum = givenCardNum;
}

std::string card::setCardType(std::string givenCardNum) {
	if (!checkCardNums()) {
		return "Invalid";
	}

	// get length
	short int numLength = givenCardNum.length();

	// get first digit
	char firstChar = givenCardNum[0];
	short int first = firstChar - '0';

	// console debug
	//std::cout << "first digit: " << first << std::endl;
	//std::cout << "length: " << numLength << std::endl;


	// visa 
	if ((numLength == 16) && (first == 4)) {
		cardType = "VISA";
	}
	// mastercard 
	else if ((numLength == 16) && (first == 5)) {
		cardType = "MASTERCARD";
	}
	// amex
	else if ((numLength == 15) && (first == 3)) {
		cardType = "AMEX";
	}
	// discover
	else if ((numLength == 16) && (first == 6)) {
		cardType = "DISCOVER";
	}
	else {
		cardType = "Invalid Card";
	}

	return cardType;
}

bool card::checkCardNums() {

	// return false if length is < 15 or > 17
	if (cardNum.length() < 15 || cardNum.length() > 16) {
		//std::cout << cardNum << " is not a valid number." << std::endl;
		return false;
	}

	// check if first
	for (int i = 0; i < cardNum.length(); i++) {
		if (!isdigit(cardNum[i])) {
			return false;
		}
	}

	//std::cout << cardNum << " is a valid number." << std::endl;
	return true;

}

void card::setExpDate(int givenExpDate) {
	expDate = givenExpDate;

}

void card::setCVV(int givenCVV) {
	CVV = givenCVV;

}

std::string card::getCardNum() const {
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

void card::toString() const {
	std::cout << cardType << " ending in " << cardNum.substr(cardNum.length() - 4);
}

