#include "tax.h"

tax::tax() {
	localTax = 0.0;
	sum = 0.0;
}

tax::tax(float givenLocalTax, float givenSum) {
	localTax = givenLocalTax;
	sum = givenSum;
}

void tax::setTax(float givenLocalTax) {
	localTax = givenLocalTax;
}

void tax::setSum(float givenSum) {
	sum = givenSum;
}

float tax::getTax() const {
	return localTax;
}

float tax::getSum() const {
	return sum;
}

float tax::taxAmount() const {
	float taxAmount = sum * localTax;

	return taxAmount;
}

// after tax total
float tax::calcTotal() const{
	
	float totalAfter = sum + (sum * localTax);

	return totalAfter;
}