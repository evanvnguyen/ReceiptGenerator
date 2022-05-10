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
#include <stdio.h>
#include <io.h>

// UI for transaction
// main called here

void display(market);
void waitReceipt(); 
void waitPayment();
void waitChange();
void payment(double, market, std::vector<item>);

int main()
{
    market Store("Costco", "5401 Katella Ave\n\t Cypress, CA 90720", 7801,
                    "(562)-668-5150", "123 1234 123", "us@costco.com", 0.2);

    // instantiate items here
    std::vector<int> allSKU = { 7141, 7142, 7143, 7144, 7145 };

    item milk(allSKU[0], "Horizon Milk", 50, 4.99);
    item phone(allSKU[1], "iPhone 13", 50, 799.99);
    item apples(allSKU[2], "Fuji Apples (6ct)", 50, 3.99);
    item webcam(allSKU[3], "Webcam 1080p", 50, 49.99);
    item ps5(allSKU[4], "PlayStation 5 Digital", 50, 399.99);

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

        if (user_input == 0) {
            break;
        }
        else if (std::find(allSKU.begin(), allSKU.end(), user_input) != allSKU.end()) {

            // get the sum of the item
            sum += items.at(user_input).getPrice();
            cart.push_back(items.at(user_input));

            // update the items amount in the inventory
            items.at(user_input).setAmount(items.at(user_input).getAmount() - 1);
            std::cout << "  " << items.at(user_input).getName() << " stock: " << items.at(user_input).getAmount() << std::endl;


            std::cout << "  " << items.at(user_input).getName() << " scanned!";
            std::cout << " ------------------------ " << items.at(user_input).getPrice() << std::endl;
            std::cout << "  TOTAL: " << sum << std::endl;
            std::cout << "  ---------------------------------------------------------------------\n";

        }
        else {
            std::cout << "\n  This item doesnt exist!\n";
        } // throw exception if input not an integer
    }
    std::cout << "  ---------------------------------------------------------------------\n";
    std::cout << "  Items in cart: \n";

    for (int i = 0; i < cart.size(); i++) {
        std::cout <<"  " << cart[i].getSKU() << " " << cart[i].getName() << " " << cart[i].getPrice() << std::endl;
    }

    std::cout << "  TOTAL: " << sum << std::endl;
    std::cout << "  ---------------------------------------------------------------------\n";
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
    //std::wcout << L"你好" << endl;
}

void payment(double sum, market Store, std::vector<item> cart) {

    double tempSum = sum;
    // cash denominations
    
    std::cout << "  Select your payment type: \n";
    std::cout << "  > CARD\n";
    std::cout << "  > CASH\n";
    std::cout << "  > ";

    std::string user_input;
    std::cin >> user_input;
    std::cout << "  ---------------------------------------------------------------------\n";

    for (int i = 0; user_input[i]; i++) {
        user_input[i] = tolower(user_input[i]);
    }
    // apply sales tax
    float taxAmt = sum * Store.getTax();
    tax initTax(0.2, sum);

    // ask for payment options
    bool still_select = true;
    while (still_select) {
        double cash = 0.0;

        if (user_input == "card") { // selects card
            std::cout << "  Please insert or swipe your card: ";
            std::cin >> user_input;
            std::string thisCard = user_input;
            card myCard(thisCard, 1023, 843);

            // card approved
            if (myCard.checkCardNums()) {
                waitPayment();

                std::cout << "\n  - APPROVED: ";
                myCard.toString();


                printf("\n  - PRE-TAX TOTAL: %.2f\n", sum);
                printf("  - TAX AMT: %.2f", taxAmt);
                printf("\n  - YOUR TOTAL AFTER TAX IS: %.2f\n", sum + taxAmt);

                waitReceipt();
                // call receipt here
                // and done!
                receipt Receipt(Store, cart, myCard, initTax, sum, cash);
                Receipt.printReceiptCard();

                break;
            }
            else {
                std::cout << "  This card is not valid.\n";
            }
        }
        else if (user_input == "cash") { // selects cash
            double cash = 0;
            double add;
            double leftover;

            printf("  - PRE-TAX TOTAL: %.2f\n", sum);
            printf("  - TAX AMT: %.2f", taxAmt);
            sum = sum + taxAmt;
            printf("\n  - YOUR TOTAL AFTER TAX IS: %.2f\n", sum);
            std::cout << "  ---------------------------------------------------------------------\n";

            bool balanceLeft = true;
            while (balanceLeft) {
                std::cout << "  > Please enter cash: ";
                std::cin >> add;
                cash = cash + add;
                leftover = sum - cash;
                if (leftover > 0) {
                    printf("  - Remaining: %.2f\n", leftover);
                }
                else {
                    printf("  - Your change is: %.2f\n", leftover * -1);
                    waitReceipt();

                    // call receipt here and done!
                    receipt Receipt(Store, cart, initTax, sum, cash);
                    Receipt.printReceiptCash();
                    waitChange();
                    break;
                }
            }
            still_select = false;
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
    double timeInterval, timeInterval2;

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
    double timeInterval, timeInterval2;

    std::cout << "\n  ---------------------------------------------------------------------";
    std::cout << "\n  > Dispensing change ";
    for (numberOfDots = 0; numberOfDots <= 10; numberOfDots++)
    {
        std::cout << ".";
        for (timeInterval = 0; timeInterval <= 10000000; timeInterval = timeInterval + 0.1);
    }
    std::cout << "\n  > Please collect your change. Thank you for shopping with us!";
}