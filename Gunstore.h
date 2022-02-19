//
// Created by Colin Marvin on 12/2/21.
//

#ifndef FANTASYFIGHTINGGAME_GUNSTORE_H
#define FANTASYFIGHTINGGAME_GUNSTORE_H


#include "vector"
#include "Weapon.h"
#include "Hero.h"

class Gunstore{
private:
    int hMoney;
    vector<Weapon>stock;
public:
    Gunstore(Hero* f);
    void getStock();
    Weapon buy();
    int pay(int w);
};


#endif //FANTASYFIGHTINGGAME_GUNSTORE_H
