#include <string>
using namespace std;

#pragma once

#include <iostream>
#include <queue>
#include "Card.h" 

class Hand {
private:
    std::queue<Card*> cards;

public:
    Hand& operator+=(Card* card);
    Card* play();
    Card* top() const;
    Card* operator[](int index);
    void print(std::ostream& out, bool all) const;
};
