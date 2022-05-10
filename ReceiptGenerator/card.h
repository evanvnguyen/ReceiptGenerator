#pragma once
#ifndef CARD_H
#define CARD_H

#include <string>

class card {
	private:
		std::string cardNum;
		// set to none initially, evaluate in card.cpp. 
		// dont pass as parameter
		std::string cardType; 
		int expDate;
		int CVV;

	public:
		card();
		~card();
		card(std::string givenCardNum, int givenExpDate, int givenCVV);


		void setCardNum(std::string givenCardNum);
		std::string setCardType(std::string givenCardNum);
		void setExpDate(int givenExpDate);
		void setCVV(int givenCVV);

		std::string getCardNum() const;
		std::string getCardType() const;
		bool checkCardNums();

		int getExpDate() const;
		int getCVV() const;

		// output
		void toString() const;
};

#endif