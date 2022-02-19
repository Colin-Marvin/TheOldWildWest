//
// Created by Colin Marvin on 12/2/21.
//

#ifndef FANTASYFIGHTINGGAME_COWBOY_H
#define FANTASYFIGHTINGGAME_COWBOY_H

#include "string"
#include "Weapon.h"

class Cowboy {
private:
    int health;
    Weapon weapon;
    string type;
    int money;
public:
    Cowboy(int h, Weapon g, string t, int m);
    Cowboy();
    void setHealth(int d);
    int getHealth();
    int getWeapon();
    int getMoney();
    string getType();
};


#endif //FANTASYFIGHTINGGAME_COWBOY_H
