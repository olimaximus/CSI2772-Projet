#pragma once

#include <iostream>
#include <vector>
#include "Chain.h"
#include "Hand.h"

class Player {
private:
    std::string name;
    int coins;
    int maxNumChains;
    std::vector<Chain> chains;
    Hand hand;

public:
    Player(const std::string& playerName);
    std::string getName() const;
    int getNumCoins() const;
    int getMaxNumChains() const;
    int getNumChains() const;
    Chain& operator[](int i);
    void operator+=(int numCoins);
    void buyThirdChain();
    void printHand(std::ostream& out, bool all) const;
    friend std::ostream& operator<<(std::ostream& out, const Player& player);
};
