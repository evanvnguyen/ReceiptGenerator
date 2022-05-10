#include "item.h"
#include "card.h"
#include "market.h"
#include "receipt.h"
#include "tax.h"

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>
#include <ctime>
#include <cmath>
#include <limits>
#include <iomanip>
// UI for transaction
// main called here

void display(market);
void waitReceipt(); 
void waitPayment();
void waitChange();

void payment(double, market, std::vector<item>);
//(myCard, userInput, sum, taxAmt)
bool cardPayment(market, tax, std::vector<item> cart, double, double);
//(cash, tax, cart, sum, taxamt)
bool cashPayment(market, tax, std::vector<item> cart, double, double);

int main()
{
    market Store("Costco", "5401 Katella Ave\n\t   Cypress, CA 90720", 7801,
                    "(562)-668-5150", "123 1234 123", "us@costco.com", 0.07F);

    // instantiate items here
    std::vector<int> allSKU = { 7141, 7142, 7143, 7144, 7145 };

    item milk(allSKU[0], "Horizon Milk", 2, 4.99F);
    item phone(allSKU[1], "iPhone 13", 50, 799.99F);
    item apples(allSKU[2], "Fuji Apples (6ct)", 50, 3.99F);
    item webcam(allSKU[3], "Webcam 1080p", 50, 49.99F);
    item ps5(allSKU[4], "PlayStation 5 Digital", 50, 399.99F);

    std::map<int, item> items = { { allSKU[0], milk },
                             { allSKU[1], phone },
                             { allSKU[2], apples },
                             { allSKU[3], webcam },
                             { allSKU[4], ps5 } };
    display(Store);

    std::vector<item> cart;
    double sum = 0;

    int user_input; 
    bool still_buying = true;
    while (still_buying) {
        std::cout << "  Please scan the SKU of the item (Press 0 to finish): ";
        std::cin >> user_input;
        user_input = abs(user_input);

        // error handle a bad input
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "  INVALID SCAN! Enter the SKU of the item (Press 0 to finish):  ";
            std::cin >> user_input;

            if (user_input == 0) {
                still_buying = false;
            }
            else if (!std::cin.fail()) {
                break;
            }
            else if (cart.size() == 0) {
                std::cout << "No items scanned. Exiting.\n";
                return 0;
            }
        }

        if (user_input == 0) {
            still_buying = false;
        } // if the sku entered is inside the vector of possible skus
        else if (std::find(allSKU.begin(), allSKU.end(), user_input) != allSKU.end()) {

            // get the sum of the item
            if (items.at(user_input).getAmount() == 0) {
                std::cout << "  This item is out of stock.\n";
                std::cout << "  ---------------------------------------------------------------------\n";
                std::cout << "  Items in cart: \n";
                for (int i = 0; i < cart.size(); i++) {
                    std::cout << "  " << cart[i].getSKU() << " " << cart[i].getName() << " " << cart[i].getPrice() << std::endl;
                }
            }
            else {
                sum += items.at(user_input).getPrice();
                cart.push_back(items.at(user_input));
                items.at(user_input).setAmount(items.at(user_input).getAmount() - 1);
                std::cout << "  " << items.at(user_input).getName() << " stock: " << items.at(user_input).getAmount() << std::endl;
                std::cout << "  " << std::left << std::setw(24) << items.at(user_input).getName() 
                          << std::right << items.at(user_input).getPrice() << std::endl;

            }

            std::cout << "  TOTAL: " << sum << std::endl;
            std::cout << "  ---------------------------------------------------------------------\n";
        }
        else  {
            std::cout << "  This item doesnt exist!\n";
        }
    }
    std::cout << "  ---------------------------------------------------------------------\n";
    std::cout << "  Items in cart: \n";

    for (int i = 0; i < cart.size(); i++) {
        std::cout << "  "  << cart[i].getSKU() << " " << std::setw(24) << std::left << cart[i].getName() << cart[i].getPrice() << std::endl;
    }

    std::cout << "  TOTAL: " << sum << std::endl;
    std::cout << "  ---------------------------------------------------------------------\n";
    if (cart.size() == 0) {
        std::cout << "  No items in cart. Exiting.";
        return 0;
    }
    
    payment(sum, Store, cart);

    return 0;
}

void display(market store) {
    std::cout << "  <> <> <> <> <> <> <> <> <> Welcome to " << store.getName() << "! <> <> <> <> <> <> <> <> <>" << std::endl;
    std::cout << "      You walk into the store and you see these items on the shelf:  \n";
    std::cout << "  *----------------------------------------------------------------------*\n";
    std::cout << "  |SKU #7142: iPhone 13 ----------------------------------------- $799.99|\n";
    std::cout << "  |SKU #7145: PlayStation 5 (Digital) --------------------------- $399.99|\n";
    std::cout << "  |SKU #7144: 1080p Webcam --------------------------------------- $19.99|\n";
    std::cout << "  |SKU #7143: Fuji Apples(6ct) ------------------------------------ $1.99|\n";
    std::cout << "  |SKU #7141: Horizon Milk 16oz ----------------------------------- $1.49|\n";
    std::cout << "  *----------------------------------------------------------------------*\n";
    std::cout << "  Excited to purchase some goods, you hastily put some items in your cart.\n";
    std::cout << "     You make your way to self-checkout, and start using the register.\n";
    std::cout << "    The register detects your movement and the following prompts pop up:\n";
    std::cout << "  ---------------------------------------------------------------------\n";
}

void payment(double sum, market Store, std::vector<item> cart) {

    double tempSum = sum;
    std::string wat;
    
    std::cout << "  Select your payment type: \n";
    std::cout << "  > CASH\n";
    std::cout << "  > CARD\n";
    std::cout << "  > ";

    std::string user_input;
    std::cin >> user_input;

    // error handle a bad input
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "  INVALID ENTRY! Type CASH or CARD:  ";
        std::cin >> user_input;;
    }

    std::cout << "  ---------------------------------------------------------------------\n";

    for (int i = 0; user_input[i]; i++) {
        user_input[i] = tolower(user_input[i]);
    }
    // apply sales tax
    double taxAmt = sum * Store.getTax();
    tax initTax(Store.getTax(), sum);

    // ask for payment options
    bool still_select = true;
    while (still_select) {
        double cash = 0.0;

        if (user_input == "card") { // selects card

            // cardPayment returns false to break the loop.
            still_select = cardPayment(Store, initTax, cart, sum, taxAmt);

        }
        else if (user_input == "cash") { // selects cash

            //cashPayment returns false to break the loop
            still_select = cashPayment(Store, initTax, cart, sum, taxAmt);
        }
        else {
            std::cout << "  Error! Did you mean to type \"cash\" or \"card\"? Try again: ";
            std::cin >> user_input;
        }
    }
}

bool cardPayment(market thisStore, tax thisInitTax, std::vector<item> thisCart, double thisSum, double thisTaxAmt) {
    std::string user_input;
    
    std::cout << "  Please insert or swipe your card: ";
    std::cin >> user_input;
    card myCard(user_input, 1023, 843);

    double cash = 0.0;
    
    if (myCard.checkCardNums()) {
        waitPayment();
        myCard.setCardType(user_input);
        std::cout << "\n  - APPROVED: ";
        myCard.toString();


        printf("\n  - PRE-TAX TOTAL: %.2f\n", thisSum);
        printf("  - TAX AMT: %.2f", thisTaxAmt);
        printf("\n  - YOUR TOTAL AFTER TAX IS: %.2f\n", thisSum + thisTaxAmt);

        waitReceipt();
        // call receipt here
        // and done!
        receipt Receipt(thisStore, thisCart, myCard, thisInitTax, thisSum, cash);
        Receipt.printReceiptCard();

        return false;
    }
    else {
        std::cout << "  This card is not valid.\n";
    }
}

bool cashPayment(market thisStore, tax thisInitTax, std::vector<item> thisCart, double thisSum, double thisTaxAmt) {
    
    double cash = 0;
    double add;
    double leftover;

    printf("  - PRE-TAX TOTAL: %.2f\n", thisSum);
    printf("  - TAX AMT: %.2f", thisTaxAmt);
    thisSum = thisSum + thisTaxAmt;
    printf("\n  - YOUR TOTAL AFTER TAX IS: %.2f\n", thisSum);
    std::cout << "  ---------------------------------------------------------------------\n";

    bool balanceLeft = true;
    while (balanceLeft) {
        std::cout << "  > Please enter cash: ";
        std::cin >> add;
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "  Please deposit a cash value:  ";
            std::cin >> add;
        }
        cash = cash + add;
        leftover = thisSum - cash;
        if (leftover > 0) {
            printf("  - Remaining: %.2f\n", leftover);
        }
        else {
            printf("  - Your change is: %.2f\n", leftover * -1);
            waitReceipt();

            // call receipt here and done!
            receipt Receipt(thisStore, thisCart, thisInitTax, thisSum, cash);
            Receipt.printReceiptCash();
            waitChange();
            return false;

        }
    }
}

// loading functions to make it look nicer
void waitReceipt() {
    int numberOfDots;
    double timeInterval, timeInterval2;

    std::cout << "  ---------------------------------------------------------------------";
    std::cout << "\n  > Thank you for shopping at Costco!";
    std::cout << "\n  > Generating receipt ";
    for (numberOfDots = 0; numberOfDots <= 10; numberOfDots++)
    {
        std::cout << ".";
        for (timeInterval = 0; timeInterval <= 10000000; timeInterval = timeInterval + 0.1);
    }
    std::cout << std::endl;
}

void waitPayment() {
    int numberOfDots;
    double timeInterval;

    std::cout << "  ---------------------------------------------------------------------";
    std::cout << "\n  > Contacting bank ";
    for (numberOfDots = 0; numberOfDots <= 10; numberOfDots++)
    {
        std::cout << ".";
        for (timeInterval = 0; timeInterval <= 10000000; timeInterval = timeInterval + 0.1);
    }
    std::cout << "\n  > Starting transaction ";
    for (numberOfDots = 0; numberOfDots <= 10; numberOfDots++)
    {
        std::cout << ".";
        for (timeInterval = 0; timeInterval <= 10000000; timeInterval = timeInterval + 0.1);
    }
    std::cout << "\n  ---------------------------------------------------------------------";
}

void waitChange() {
    int numberOfDots;
    double timeInterval;

    std::cout << "\n  ---------------------------------------------------------------------";
    std::cout << "\n  > Dispensing change ";
    for (numberOfDots = 0; numberOfDots <= 10; numberOfDots++)
    {
        std::cout << ".";
        for (timeInterval = 0; timeInterval <= 10000000; timeInterval = timeInterval + 0.1);
    }
    std::cout << "\n  > Please collect your change. Thank you for shopping with us!";
}