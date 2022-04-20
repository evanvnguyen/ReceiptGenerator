#pragma once
#ifndef CARD_H
#define CARD_H

#include <string>

class card {
	private:
		long int cardNum;
		std::string cardType; // set to none initially, evaluate in card.cpp. dont pass as parameter
		int expDate;
		int CVV;

	public:
		card();
		~card();
		card(long int givenCardNum, int givenExpDate, int givenCVV);


		void setCardNum(long int givenCardNum);
		std::string setCardType(long int givenCardNum);
		void setExpDate(int givenExpDate);
		void setCVV(int givenCVV);

		int getCardNum() const;
		std::string getCardType() const;
		int getExpDate() const;
		int getCVV() const;

};

#endif