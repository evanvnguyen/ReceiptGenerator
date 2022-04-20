// ReceiptGenerator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "card.h"

using namespace std;
int main()
{
    std::cout << "Hello World!\n";

    // why does my console say the givenCardNum is something random?
    card myCard(40004444999999, 1023, 843);

    cout << myCard.getCardType();
  
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


