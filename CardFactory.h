#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Card.h" // Assuming you have a Card class
#include <algorithm>
#include <random>



class CardFactory {
private:
    std::vector<Card*> allCards;
    
    CardFactory();

public:
    static CardFactory* getFactory();
    Card* createCard() const;
};
