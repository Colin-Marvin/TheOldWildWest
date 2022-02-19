//
// Created by Colin Marvin on 12/2/21.
//

#include "Hero.h"
using namespace std;

Hero::Hero(int h, Weapon w, int m) { //Used in creating a load game, rather than a new one
    health = h;
    gun = w;
    money = m;
}

void Hero::addHealth(int b) { //Adds health to the user
    health+=b;
}

void Hero::setMoney(int x) { //Changes the users money
    money+=x;
}

int Hero::getHealth() { //Returns the users health
    return health;
}

int Hero::getMoney() { //Returns the users money
    return money;
}

int Hero::getWeapon() { //Returns the weapons damage
    return gun.getDamage();
}

Hero::Hero() { //Default constructor, used in the new game creation
    health = 100;
    gun = Weapon();
    money = 100;
}

void Hero::loseHealth(int l) { //Subtracts health
    health-=l;
}

void Hero::setWeapon(Weapon newWeapon) { //Changes current weapon to weapon returned
    gun = newWeapon;
}