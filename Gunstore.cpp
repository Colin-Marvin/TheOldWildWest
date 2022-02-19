//
// Created by Colin Marvin on 12/2/21.
//

#include "Gunstore.h"
#include "Hero.h"
#include "Weapon.h"
#include <iostream>
using namespace std;

void Gunstore::getStock() { //Iterates through the stock vector and lists the properties of each item
    for(int i = 0; i < stock.size(); i ++)
    {
        cout << "We have: " << endl;
        cout << "(" << i+1 << ") " << stock[i].getType() << ", which does " << stock[i].getDamage() << " damage, and costs $" << stock[i].getCost() << "." << endl;
    }
}

Weapon Gunstore::buy() { //Prompts the user to enter what weapon they want, and returns that weapon from the stock vector
    cout << "What gun would you like to buy? Please answer with what number in the stock the weapon is. Enter -1 to leave." << endl;
    int x;
    cin >> x;
    int a = stock[x-1].getCost();
    if(x >= stock.max_size())
    {
        cout << "Please enter a valid input" << endl;
        buy();
    }
    else if(a > hMoney)
    {
        cout << "You do not have enough money to purchase that weapon. ";
        buy();
    }
    else if(x==-1)
    {
    }
    else
    {
        return stock[x-1];
    }
}

Gunstore::Gunstore(Hero* f) //Gets how much money the user has and populates the stock vector
{
    hMoney = f -> getMoney();
    Weapon gs1 = Weapon(20, "Desert Eagle", 150);
    Weapon gs2 = Weapon(30, "AK-47", 300);
    Weapon gs3 = Weapon(50, "Ray Gun", 500);
    stock.push_back(gs1);
    stock.push_back(gs2);
    stock.push_back(gs3);
}

int Gunstore::pay(int w) { //Returns the stock of each item in the vector
    if(w == stock[0].getDamage())
    {
        return stock[0].getCost();
    }
    else if(w == stock[1].getDamage())
    {
        return stock[1].getCost();
    }
    else
    {
        return stock[2].getCost();
    }
}
