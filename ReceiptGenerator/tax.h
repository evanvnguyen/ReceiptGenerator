#pragma once
#ifndef TAX_H
#define TAX_H

class tax {
	private:
		double localTax;

		double sum; // pre-tax total
	public:
		tax();
		tax(double, double);

		void setTax(double givenLocalTax);
		void setSum(double givenSum);

		double getTax() const;
		double getSum() const;

		double taxAmount() const;
		// after tax total
		double calcTotal() const;
};

#endif