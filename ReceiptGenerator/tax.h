#pragma once
#ifndef TAX_H
#define TAX_H

class tax {
	private:
		double localTax;

		// pre-tax total
		double sum;
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