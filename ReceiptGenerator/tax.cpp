#include "tax.h"

tax::tax() {
	localTax = 0.0;
	sum = 0.0;
}

tax::tax(double givenLocalTax, double givenSum) {
	localTax = givenLocalTax;
	sum = givenSum;
}

void tax::setTax(double givenLocalTax) {
	localTax = givenLocalTax;
}

void tax::setSum(double givenSum) {
	sum = givenSum;
}

double tax::getTax() const {
	return localTax;
}

double tax::getSum() const {
	return sum;
}

double tax::taxAmount() const {
	double taxAmount = sum * localTax;

	return taxAmount;
}

// after tax total
double tax::calcTotal() const{
	
	double totalAfter = sum + (sum * localTax);

	return totalAfter;
}