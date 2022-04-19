#include "card.h"


card::card() {
	cardNum = 0;
	expDate = 0;
	cardType = "NULL";
	CVV = 0;
}
card::card(int givenCardNum, int givenExpDate, int givenCVV) {
	cardNum = givenCardNum;
	expDate = givenExpDate;
	cardType = "NULL"; // to be altered by setCardType();
	CVV = givenCVV;
}
card::~card() {

}

void card::setCardNum(int givenCardNum) {

}
void card::setCardType(int givenCardNum) {

}
void card::setExpDate(int givenExpDate) {

}
void card::setCVV(int givenCVV) {

}

int card::getCardNum() const {

}
std::string card::getCardType() const {

}
int card::getExpDate() const {

}
int card::getCVV() const {

}
bool card::isValid() const {

}
