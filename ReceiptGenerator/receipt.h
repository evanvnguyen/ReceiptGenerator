#pragma once
#ifndef RECEIPT_H
#define RECEIPT_H

#include "item.h"
#include "market.h"
#include "card.h"
#include "tax.h"
#include <vector>

// class that holds the information needed to print out
// on a receipt and has a custom cout
class receipt
{
	private:
		market Store;
		std::vector<item> cart;
		card myCard;
		tax Tax;
		float sum;
		float cash;
	public:

		// card constructor
		receipt(market, std::vector<item>, card, tax, float, float);

		// cash constructor
		receipt(market, std::vector<item>, tax, float, float); 

		void printReceiptCard() const;
		void printReceiptCash() const;
		void printBarcode() const;
		void setStore(market givenStore);
		void setCart(std::vector<item> givenCart);
		void setCard(card givenCard);
		void setTotal(float givenSum);

		market getStore() const;
		std::vector<item> getCart() const;
		card getCard() const;
		float getTotal() const;
};

#endif