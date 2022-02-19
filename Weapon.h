//
// Created by Colin Marvin on 12/2/21.
//

#ifndef FANTASYFIGHTINGGAME_WEAPON_H
#define FANTASYFIGHTINGGAME_WEAPON_H

using namespace std;
#include "string"

class Weapon {
private:
    int damage;
    string type;
    int cost;
public:
    Weapon();
    Weapon(int d, string t, int x);
    int getDamage();
    string getType();
    int getCost();
};


#endif //FANTASYFIGHTINGGAME_WEAPON_H
