#include "inventory.h"
#include <map>
#include <iostream>
#include "item.h"

using namespace std;

item tempItem = new item(1234, "Temp", 2, 2.12);

map<item, int> stock = { {1, 20} };