//
// Created by Colin Marvin on 12/17/21.
//

#include "Drinks.h"
#include "string"

using namespace std;

Drinks::Drinks(Hero* p) {
     heroHealth = p -> getHealth();
     heroMoney = p -> getMoney();
     buyDrink()
}

void Drinks::buyDrink() {
    cout << "What kind of drink would you like? We offer bourbon, beer, whiskey, and tequila. " << endl;
    cout << "Enter 'exit' to go back. " << endl;
    string input;
    cin >> input;

    if(input == "bourbon")
    {

    }
}
