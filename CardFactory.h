
#include <algorithm>
#include <random>

#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include "Card.h"
#include "Deck.h"

class CardFactory{
    private:
        Deck* deck;
        CardFactory();
    public:
        static CardFactory* instance;
        static CardFactory* getFactory();
        Deck* getDeck();


};

#endif