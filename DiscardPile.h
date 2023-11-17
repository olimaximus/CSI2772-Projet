#include <string>
using namespace std;

#pragma once

#include <iostream>
#include <vector>
#include "Card.h" // Assuming you have a Card class

class DiscardPile {
private:
    std::vector<Card*> cards;

public:
    DiscardPile& operator+=(Card* card);
    Card* pickUp();
    Card* top() const;
    void print(std::ostream& out) const;
};
