//
// Created by Colin Marvin on 12/2/21.
//

#ifndef FANTASYFIGHTINGGAME_SALOON_H
#define FANTASYFIGHTINGGAME_SALOON_H


#include "vector"
#include "Hero.h"
#include "Weapon.h"
#include "Cowboy.h"
#include "Gunstore.h"
#include <fstream>

class Saloon {
private:
    int bossCount;
    int underlingCount;
    int count;
    vector<Cowboy>boss;
    vector<Cowboy>underling;
    fstream progress;
public:
    Hero* Player;
    Saloon();
    void run();
    void drink();
    void gamble();
    void fight();
    void buyGuns();
    void question();
    void checkStats();
};


#endif //FANTASYFIGHTINGGAME_SALOON_H
