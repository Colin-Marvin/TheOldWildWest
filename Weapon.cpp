//
// Created by Colin Marvin on 12/2/21.
//

#include "Weapon.h"
using namespace std;

Weapon::Weapon(int d, string t, int x) { //Parameterized constructor of weapon
    damage = d;
    type = t;
    cost = x;
}

int Weapon::getDamage() { //Returns the damage of the weapon
    return damage;
}

int Weapon::getCost() { //Returns the cost of the weeapon
    return cost;
}

string Weapon::getType() { //Returns the type of the weapon
    return type;
}

Weapon::Weapon() { //Default constructor for weapon
    damage = 5;
    type = "Magnum .22";
    cost = 0;
}
