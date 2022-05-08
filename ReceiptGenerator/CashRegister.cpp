#include "item.h"
#include "card.h"
#include "market.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

// UI for transaction
// main called here

void display(market);
void displayPayment();
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

    map<item, int> cart;

    int user_input; 
    bool still_buying = true;
    while (still_buying) {
        cout << "  Please scan the SKU of the item (Press 0 to finish): ";
        cin >> user_input;
        if (user_input == 0) {
            break;
        }
        else if (std::find(allSKU.begin(), allSKU.end(), user_input) != allSKU.end()) {
            
            // if item is already in the cart, dont add it. 
            // find the item's qty and +1
            // implement operator< 
            map<item, int>::iterator it = cart.find(items.at(user_input));
            if (cart.end() != it) {
                cart[items.at(user_input)]++;
            }
            else { 
                // if input is new, add item name and set qty to 1
                cart.insert(pair<item, int>(items.at(user_input), 1));
            }
            cout << "  " << items.at(user_input).getName() << " scanned!\n";
        }
        else {
            cout << "\n  This item doesnt exist!";
        } // throw exception if input not an integer

    }
    cout << "  ---------------------------------------------------------------------\n";
    displayPayment();

    cout << "  Items in cart: \n";

    cin >> user_input;

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

void displayPayment() {
    cout << "  Select your payment type: \n";
    cout << "                         1: CARD\n";
    cout << "                         2: CASH";
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