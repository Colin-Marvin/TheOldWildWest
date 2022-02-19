//
// Created by Colin Marvin on 12/2/21.
//

#ifndef FANTASYFIGHTINGGAME_HERO_H
#define FANTASYFIGHTINGGAME_HERO_H

#include "Weapon.h"

class Hero {
private:
    int health;
    Weapon gun;
    int money;
public:
    Hero(int h, Weapon w, int m);
    Hero();
    void addHealth(int b);
    void loseHealth(int l);
    void setWeapon(Weapon newWeapon);
    void setMoney(int x);
    int getHealth();
    int getWeapon();
    int getMoney();
};


#endif //FANTASYFIGHTINGGAME_HERO_H
