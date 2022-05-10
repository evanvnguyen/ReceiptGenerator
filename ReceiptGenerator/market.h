#pragma once
#ifndef MARKET_H
#define MARKET_H

#include <string>

//class that holds the physical information of the store
class market {
	private:
		std::string name;
		std::string address;
		int storeNum;
		std::string phone;
		std::string fax;
		std::string email;
		float tax;
	public:
		// Empty and overloaded constructors
		market();
		market(std::string givenName, std::string givenAddress, int givenStoreNum, std::string givenPhone, std::string givenFax, std::string givenEmail, float tax);

		// Set functions
		void setName(std::string givenName);
		void setAdd(std::string givenAddress);
		void setStoreNum(int givenStoreNum);
		void setPhone(std::string givenPhone);
		void setFax(std::string givenFax);
		void setEmail(std::string givenEmail);
		void setTax(float givenTax);

		// Get functions
		std::string getName() const;
		std::string getAdd() const;
		int getNumber() const;
		std::string getPhone() const;
		std::string getFax() const;
		std::string getEmail() const;
		float getTax() const;
};

#endif