//
// Created by Colin Marvin on 12/17/21.
//

#ifndef FANTASYFIGHTINGGAME_DRINKS_H
#define FANTASYFIGHTINGGAME_DRINKS_H

using namespace std;
#include "string"
#include <iostream>
#include "Hero.h"

class Drinks {
private:
    int heroHealth;
    int heroMoney;
public:
    Drinks(Hero* p);
    void buyDrink();
};


#endif //FANTASYFIGHTINGGAME_DRINKS_H
