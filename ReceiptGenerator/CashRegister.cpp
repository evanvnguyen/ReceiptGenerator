#include "item.h"
#include "card.h"
#include "market.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>
#include <ctype.h>
using namespace std;

// UI for transaction
// main called here

void display(market);
void payment(double);
void testCards();

int main()
{
    market Store("Costco", "5401 Katella Ave\n\tCypress, CA 90720", 7801,
                    "(562)-668-5150", "123 1234 123", "us@costco.com");

    // instantiate items here
    vector<int> allSKU = { 7141, 7142, 7143, 7144, 7145 };

    item milk(allSKU[0], "Horizon Milk", 50, 4.99);
    item phone(allSKU[1], "iPhone 13", 50, 799.99);
    item apples(allSKU[2], "Fuji Apples (6ct)", 50, 3.99);
    item webcam(allSKU[3], "Webcam 1080p", 50, 49.99);
    item ps5(allSKU[4], "PlayStation 5 Digital", 50, 399.99);

    map<int, item> items = { { allSKU[0], milk },
                             { allSKU[1], phone },
                             { allSKU[2], apples },
                             { allSKU[3], webcam },
                             { allSKU[4], ps5 } };
    display(Store);

    vector<item> cart;
    double sum = 0;


    int user_input; 
    bool still_buying = true;
    while (still_buying) {
        cout << "  Please scan the SKU of the item (Press 0 to finish): ";
        cin >> user_input;
        if (user_input == 0) {
            break;
        }
        else if (std::find(allSKU.begin(), allSKU.end(), user_input) != allSKU.end()) {
            // get the sum of the item
            sum += items.at(user_input).getPrice();
            cart.push_back(items.at(user_input));
            cout << "  " << items.at(user_input).getName() << " scanned!";
            cout << " ------------------------ " << items.at(user_input).getPrice() << endl;
            cout << "  TOTAL: " << sum << endl;

        }
        else {
            cout << "\n  This item doesnt exist!\n";
        } // throw exception if input not an integer

    }
    cout << "  ---------------------------------------------------------------------\n";
    cout << "  Items in cart: \n";
    for (int i = 0; i < cart.size(); i++) {
        cout <<"  " << cart[i].getSKU() << " " << cart[i].getName() << " " << cart[i].getPrice() << endl;
    }
    cout << "  ---------------------------------------------------------------------\n";
    payment(sum);

    // scan the item here and append it to cart
    // once all sku's are in the cart, update each sku's inventory
    // and access the price.

    return 0;
}

void display(market store) {
    cout << "  <> <> <> <> <> <> <> <> <> Welcome to " << store.getName() << "! <> <> <> <> <> <> <> <> <>" << endl;
    cout << "      You walk into the store and you see these items on the shelf:  \n";
    cout << "  *----------------------------------------------------------------------*\n";
    cout << "  |SKU #7142: iPhone 13 ----------------------------------------- $799.99|\n";
    cout << "  |SKU #7145: PlayStation 5 (Digital) --------------------------- $399.99|\n";
    cout << "  |SKU #7144: 1080p Webcam --------------------------------------- $19.99|\n";
    cout << "  |SKU #7143: Fuji Apples(6ct) ------------------------------------ $1.99|\n";
    cout << "  |SKU #7141: Horizon Milk 16oz ----------------------------------- $1.49|\n";
    cout << "  *----------------------------------------------------------------------*\n";
    cout << "  Excited to purchase some goods, you hastily put some items in your cart.\n";
    cout << "     You make your way to self-checkout, and start using the register.\n";
    cout << "    The register detects your movement and the following prompts pop up:\n";
    cout << "  ---------------------------------------------------------------------\n";
}

void payment(double sum) {

    double tempSum = sum;
    // cash denominations
    vector<double> cash = { 0.01, 0.05, 0.1, 0.25, 0.5, 1.0, 2.0, 5.0, 10.0, 20.0, 50.0, 100.0 };
    
    cout << "  Select your payment type: \n";
    cout << "                         1: CARD\n";
    cout << "                         2: CASH\n";

    string user_input;
    cin >> user_input;

    for (int i = 0; user_input[i]; i++) {
        user_input[i] = tolower(user_input[i]);
    }
    bool still_select = true;
    while (still_select) {
        if (user_input == "card") {
            cout << "Please insert or swipe your card: ";
            cin >> user_input;
            string thisCard = user_input;
            card myCard(thisCard, 1023, 843);

            // card approved
            if (myCard.checkCardNums()) {
                cout << "TYPE: " << myCard.getCardType() << endl;
                myCard.toString();
                break;
            }
            else {
                cout << "This card is not valid.\n";
            }
        }
        else if (user_input == "cash") {
            cout << "This machine only accepts proper denominations:\n";
            cout << "COINS: 0.01, 0.05, 0.1, 0.25, 0.5\n";
            cout << "CASH: 1.0, 2.0, 5.0, 10.0, 20.0, 50.0, 100.0 \n";
            cout << "Please enter cash: ";
            cin >> user_input;

        }
    }
    // call receipt
}

void testCards() {
    /*
    string visa = "4000555566667894";
    card visaCard(visa, 1023, 843);
    cout << "TYPE: " << visaCard.getCardType() << endl;
    visaCard.toString();
    cout << endl << endl;

    string invalidCard = "40005432678943244";
    card invalidCC(invalidCard, 1023, 843);
    cout << invalidCC.getCardType() << endl;
    */
}