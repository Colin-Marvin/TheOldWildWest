//
// Created by Colin Marvin on 12/2/21.
//

#include "Cowboy.h"

Cowboy::Cowboy(int h, Weapon g, string t, int m) { //Creates a parameterized cowboy
    health = h;
    weapon = g;
    type = t;
    money = m;
}

void Cowboy::setHealth(int d) { //Changes the health of the cowboy
    health -= d;
}

Cowboy::Cowboy() { //Default constructor for the cowboy
    health = 10;
    weapon = Weapon();
    type = "Cowboy";
    money = 100;
}

int Cowboy::getHealth() { //Returns the health of the cowboy
    return health;
}

int Cowboy::getWeapon() { //Returns the weapons damage
    return weapon.getDamage();
}

int Cowboy::getMoney() { //Returns the money of the cowboy
    return money;
}

string Cowboy::getType() { //Returns the type of the cowboy
    return type;
}
