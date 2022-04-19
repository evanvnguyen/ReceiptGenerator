#pragma once
#ifndef CARD_H
#define CARD_H

#include <string>

class card {
	private:
		int cardNum;
		std::string cardType; // set to none initially, evaluate in card.cpp. dont pass as parameter
		int expDate;
		int CVV;

		void setCardNum(int givenCardNum);
		void setCardType(int givenCardNum);
		void setExpDate(int givenExpDate);
		void setCVV(int givenCVV);

		int getCardNum() const;
		std::string getCardType() const;
		int getExpDate() const;
		int getCVV() const;
	public:
		card();
		~card();
		card(int givenCardNum, int givenExpDate, int givenCVV);

		bool isValid() const;
};

#endif