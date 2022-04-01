#include "cashRegister.h"
#include "item.h"
#include <iostream>
using namespace std;

item tempItem(1234, "Temp Item", 10, 2.12);

int main()
{
	cout << tempItem.getAmount();
}