#include <string>
using namespace std;

#pragma once

#include <iostream>
#include <vector>
#include "Card.h" // Assuming you have a Card class

class Deck {
private:
    std::vector<Card*> cards;

public:
    Deck();
    Card* draw();
    
    friend std::ostream& operator<<(std::ostream& out, const Deck& deck);
};