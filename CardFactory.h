
#include <algorithm>
#include <random>
#include <chrono>

#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include "Card.h"
#include "Deck.h"
using namespace std;

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