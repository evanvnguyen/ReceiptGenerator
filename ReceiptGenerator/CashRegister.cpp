#include "item.h"
#include "card.h"
#include <iostream>
#include <vector>
using namespace std;

// UI for transaction
// main called here

string scanItem(string);
bool checkScan(string);

int main()
{
    vector<string> itemsPassed;
    
    string user_input;
    bool still_buying = true;

    /*while (still_buying) {
        cout << "Please scan your item (Press F to finish): ";
        cin >> user_input;
        scanItem(user_input);
    }
    */

    /*Test Cards Here
    string amex = "324123412341234";
    card amexCard(amex, 1023, 843);
    cout << amexCard.getCardType() << endl;
    amexCard.toString();
    cout << endl;
    */
    
    string visa = "4000555566667894";
    card visaCard(visa, 1023, 843);
    cout << visaCard.getCardType() << endl;
    visaCard.toString();
    cout << endl;

    /*
    string mastercard = "5412545451124422";
    card masterCard(mastercard, 1023, 843);
    cout << masterCard.getCardType() << endl;

    string discover = "6000555566667894";
    card discoverCard(discover, 1023, 843);
    cout << discoverCard.getCardType() << endl;
    */

    string invalidCard = "40005432678943244";
    card invalidCC(invalidCard, 1023, 843);
    cout << invalidCC.getCardType() << endl;
    

    return 0;
}

string scanItem(string scanned_item) {
    // scan item loop

    if (checkScan(scanned_item)) {
        cout << "good scan!\n";
        return scanned_item;
    }
    else {

        cout << "not a good scan!\n";
        checkScan(scanned_item);
        
    }

}

bool checkScan(string scanned_item) {
    // iterate through the scanned_item string and check if it contains only digits
    // if we detect a letter, then return false
    // if only digits, then return true

    for (int i = 0; i < scanned_item.length(); i++) {
        if ((scanned_item[i] < '0') || (scanned_item[i] > '9')) {
            //cout << "bad scan \n";
            return false;
        }
    }

    //cout << "good scan \n";
    
    return true;
}

