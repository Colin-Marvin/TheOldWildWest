//
// Created by Colin Marvin on 12/2/21.
//

#include "Saloon.h"
#include "Hero.h"
#include "Gunstore.h"
#include <iostream>
#include <ctime>
#include "Drinks.h"

using namespace std;

void Saloon::drink()  { //Potion aspect of the code
    cout << "How many drinks would you like? Each drink costs $5 and you gain 10 health." << endl;
    int x;
    cin>>x;
    Player -> addHealth(10*x);
    Player -> setMoney(-5*x);
    cout << "You regain " << 10*x << " health for the price of $" << 5*x << "." << endl;
}

void Saloon::gamble() { //Alternate way to earn in-game currency
    srand(time(NULL));
    cout << "Welcome to roulette. Would you like to place a bet on red, black, or green? Answer r for red, b for black, g for green, and l to leave." << endl;
    string x; //Variable to get what color the player bets
    cin >> x;
    int y;
    cout << "How much are you willing to wager? Enter a number, or -1 to exit. " << endl;
    cin >> y; //Number for how large of a bet will be placed
    int ball = rand() % 38; //Range of roulette, creates random number in the range
    if (y != -1) {
        if (x == "g") {
            if (ball % 19 == 0) {
                cout << "You landed on green!! You get 10x prize!!" << endl;
                Player->setMoney(10 * y);
            } else {
                cout << "You lose." << endl;
                Player->setMoney(-y);
            }
        } else if (x == "b") {
            if (ball % 2 == 0) {
                cout << "You landed on black!! You get $" << y << endl;
                Player->setMoney(y);
            } else {
                cout << "You lose." << endl;
                Player->setMoney(-y);
            }
        } else if (x == "r") {
            if (ball % 2 == 1) {
                cout << "You landed on red!! You get $" << y << endl;
                Player->setMoney(y);
            } else {
                cout << "You lose." << endl;
                Player->setMoney(-y);
            }
        } else if (x == "l") {}
        else {
            cout << "Please enter a valid input." << endl;
            gamble();
        }
    }
}

void Saloon::fight() { //Fighting sequence
    if(count % 2 == 1) //Alternates the type of cowboy being fought, this being the boss cowboy portion
    {
        count++;
        cout << "You are fighting " << boss[bossCount].getType() << " #" << bossCount + 1 << ". " << endl;
        while(boss[bossCount].getHealth() >= 0)
        {
            cout << "Your health: " << Player -> getHealth() << ". Opponents health: " << boss[bossCount].getHealth() << endl;
            boss[bossCount].setHealth(Player -> getWeapon()); //Sets the health of the opponent to their health minus the damage from the players gun
            Player -> loseHealth(boss[bossCount].getWeapon()); //Sets the health of the player to their health minus the damage from the opponents gun
            if(Player -> getHealth() <= 0)
            {
                cout << "You lose. :( " << endl;
                break;
            }
        }
        if(boss[bossCount].getHealth() <= 0)
        {

            bossCount ++;
            cout << "You win the fight! You earn $" << boss[bossCount-1].getMoney() << "!" << endl;
            Player ->setMoney(boss[bossCount-1].getMoney());
        }
        else
            cout << "You lose! :(" << endl;
    }
    else //Underling portion of the fighting process
    {
        count++;
        cout << "You are fighting " << underling[underlingCount].getType() << " #" << underlingCount + 1 << ". " << endl;
        while(underling[underlingCount].getHealth() >= 0)
        {
            cout << "Your health: " << Player -> getHealth() << ". Opponents health: " << underling[underlingCount].getHealth() << endl;
            underling[underlingCount].setHealth(Player -> getWeapon());
            Player -> loseHealth(underling[underlingCount].getWeapon());
            if(Player -> getHealth() <= 0)
            {
                cout << "You lose. :( " << endl;
                break;
            }
        }
        if(underling[underlingCount].getHealth() <= 0)
        {
            underlingCount ++;
            cout << "You win the fight! You earn $" << underling[underlingCount-1].getMoney() << "!" << endl;
            Player ->setMoney(underling[underlingCount-1].getMoney());
        }
        else
            cout << "You lose! :(" << endl;
    }
}

Saloon::Saloon() { //Creates the saloon and populates the enemy vectors and sets the counts for interation
    Weapon weap = Weapon();
    Cowboy aa = Cowboy(10, weap, "Lackey", 100);
    Cowboy bb = Cowboy(10, weap, "Lackey", 100);
    Cowboy cc = Cowboy(10, weap, "Lackey", 100);
    Cowboy dd = Cowboy(10, weap, "Lackey", 100);
    underling.push_back(aa);
    underling.push_back(bb);
    underling.push_back(cc);
    underling.push_back(dd);

    Weapon bw1 = Weapon(20, "Desert Eagle", 100);
    Weapon bw2 = Weapon(25, "Desert Eagle", 100);
    Weapon bw3 = Weapon(30, "Desert Eagle", 100);
    Weapon bw4 = Weapon(50, "Bazooka", 100);
    Cowboy b1 = Cowboy(30, bw1, "Boss Cowboy", 300);
    Cowboy b2 = Cowboy(50, bw2, "Boss Cowboy", 400);
    Cowboy b3 = Cowboy(70, bw3, "Boss Cowboy", 500);
    Cowboy b4 = Cowboy(100, bw4, "Boss Cowboy", 1000);
    boss.push_back(b1);
    boss.push_back(b2);
    boss.push_back(b3);
    boss.push_back(b4);
    bossCount = 0;
    underlingCount = 0;
    count = 0;
}

void Saloon::run() { //Function that runs the game
    cout << "Welcome to the Wild West. Would you like to play a new game, or load a saved game? Answer 1 for new game, and answer 2 for load game." << endl;
    int ans;
    cin>>ans; //Input determines if new game will be created or if a previous game will be loaded
    if(ans==1)
    {
        Player = new Hero();
        while(underlingCount<=underling.max_size() && Player -> getHealth() >= 0 && bossCount<=boss.max_size())
        { //While the count is less than the max count and the player is alive, question will keep running
            cout << "Would you like continue or save and exit the game? Enter 1 for continue, and 2 for saving." << endl;
            cin>>ans;
            if(ans==2) //If saved, statement breaks and program ends
                break;
            question();
        }
        if(underlingCount<=underling.max_size() && Player -> getHealth() >= 0 && ans != 2)
        {
            if(bossCount <= boss.max_size())
                cout << "Congrats!! You win!" << endl;
        }
    }
    else if(ans==2)
    {
        int hh; //Values to create the loaded game
        int ww;
        int mm;
        progress.open("Save.txt");
        progress >> hh >> ww >> mm>> bossCount >> underlingCount;
        Weapon nw = Weapon(ww, "Glock .40", 100);
        Player = new Hero(hh, nw, mm);
        progress.close();
        while(underlingCount<=underling.max_size() && Player -> getHealth() >= 0 && bossCount<=boss.max_size())
        {
            question();
        }
        if(underlingCount<=underling.max_size() && Player -> getHealth() >= 0)
        {
            if(bossCount == boss.max_size())
                cout << "Congrats!! You win!" << endl;
        }
    }
    else
    {
        cout << "Please enter a valid input." << endl;
        run();
    }
}

void Saloon::buyGuns() { //Starts the interaction between the player and the gun store
    Gunstore gg = Gunstore(Player); //Creates a gun store with a pointer user
    int ans;
    cout << "Welcome to the Gun Store. Would you like to purchase a weapon, or see our stock, or go back to the saloon. Enter 1 for buy, 2 for stock, and 3 to go back" << endl;
    cin>>ans;
    if(ans==1)
    {
        Player -> setWeapon(gg.buy()); //Sets the player's weapon, and
        Player -> setMoney(-gg.pay(Player -> getWeapon()));
    }
    else if(ans==2)
    {
        gg.getStock();
    }
    else if(ans==3)
    {}
    else
    {
        cout << "Please enter a valid input." << endl;
    }
}

void Saloon::question() { //Determines the interaction of the game with the user
    int ans;
    cout<< "Would you like to visit the Saloon or the Gun Store? Enter 1 for Saloon and 2 for the Gun Store."<< endl;
    cin>>ans; //Asks the user what choice to make, and act accordingly
    if(ans==1)
    {
        cout << "Would you like to get a drink, fight someone, or gamble. Enter 1 to get a drink, 2 to fight a cowboy, and 3 to gamble. Enter 4 to exit." << endl;
        cin>>ans;
        if(ans==1)
        {
            drink();
            checkStats();
        }
        else if(ans==2)
        {
            fight();
            checkStats();
        }
        else if(ans==3)
        {
            gamble();
            checkStats();
        }
        else if(ans==4)
        {}
        else
        {
            cout << "Please enter a valid input." << endl;
        }
    }
    else if(ans==2)
    {
        buyGuns();
        checkStats();
    }
    else
    {
        cout << "Please enter a valid input." << endl;
    }
}

void Saloon::checkStats() { //Checks the users stats and writes it to the fstream file
    progress.open("Save.txt");
    string stat; //Opens fstream file
    cout << "Would you like to view your stats? Enter y for yes, and n for no" << endl;
    cin>>stat;
    if(stat=="y") //Outputs the users stats and enters data into the fstream file
    {
        cout << "Your health is: " << Player -> getHealth() << "." << endl;
        cout << "Your weapon does " << Player -> getWeapon() << " damage." << endl;
        cout << "You have $" << Player -> getMoney() << "." << endl;
        progress << Player -> getHealth() << " ";
        progress << Player -> getWeapon() << " ";
        progress << Player -> getMoney() << " ";
        progress << bossCount << " ";
        progress << underlingCount << endl;
    }
    progress.close();
}
