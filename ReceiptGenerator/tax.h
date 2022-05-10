#pragma once
#ifndef TAX_H
#define TAX_H

class tax {
	private:
		float localTax;

		// pre-tax total
		float sum;
	public:
		tax();
		tax(float, float);

		void setTax(float givenLocalTax);
		void setSum(float givenSum);

		float getTax() const;
		float getSum() const;

		float taxAmount() const;

		// after tax total
		float calcTotal() const;
};

#endif