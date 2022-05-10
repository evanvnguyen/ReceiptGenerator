#include "market.h"
#include <string>
using namespace std;


market::market() {
	name = "NULL";
	address = "NULL";
	storeNum = 0;
	phone = "NULL";
	fax = "NULL";
	email = "NULL";
}
market::market(std::string givenName, std::string givenAddress, int givenStoreNum, std::string givenPhone, std::string givenFax, std::string givenEmail, float givenTax) {
	name = givenName;
	address = givenAddress;
	storeNum = givenStoreNum;
	phone = givenPhone;
	fax = givenFax;
	email = givenEmail;
	tax = givenTax;
}

// Set functions
void market::setName(std::string givenName) {
	name = givenName;
}
void market::setAdd(std::string givenAddress) {
	address = givenAddress;
}
void market::setStoreNum(int givenStoreNum) {
	storeNum = givenStoreNum;
}
void market::setPhone(std::string givenPhone) {
	phone = givenPhone;
}
void market::setFax(std::string givenFax) {
	fax = givenFax;
}
void market::setEmail(std::string givenEmail) {
	email = givenEmail;
}

void market::setTax(double givenTax) {
	tax = givenTax;
}

// Get functions
std::string market::getName() const {
	return name;
}
std::string market::getAdd() const {
	return address;
}
int market::getNumber() const {
	return storeNum;
}
std::string market::getPhone() const {
	return phone;
}
std::string market::getFax() const {
	return fax;
}
std::string market::getEmail() const {
	return email;
}
float market::getTax() const {
	return tax;
}