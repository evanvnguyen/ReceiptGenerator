// ReceiptGenerator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "card.h"

using namespace std;
int main()
{
    std::cout << "Hello World!\n";

    string amex = "324123412341234";
    card amexCard(amex, 1023, 843);
    cout << amexCard.getCardType() << endl;

    string visa = "4000555566667894";
    card visaCard(visa, 1023, 843);
    cout << visaCard.getCardType() << endl;

    string mastercard = "5412545451124422";
    card masterCard(mastercard, 1023, 843);
    cout << masterCard.getCardType() << endl;

    string discover = "6000555566667894";
    card discoverCard(discover, 1023, 843);
    cout << discoverCard.getCardType() << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


