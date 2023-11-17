#include "Deck.h"
#include <iostream>

using namespace std;
#include <algorithm>
#include <random>

Deck::Deck() {
    // Assuming CardFactory is used to generate all the cards needed for the game
    CardFactory* cardFactory = CardFactory::getFactory();

    // Generate all 104 cards and shuffle them
    for (int i = 0; i < 104; ++i) {
        cards.push_back(cardFactory->createCard());
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

Card* Deck::draw() {
    if (!cards.empty()) {
        Card* drawnCard = cards.back();
        cards.pop_back();
        return drawnCard;
    } else {
        return nullptr; // Deck is empty
    }
}

std::ostream& operator<<(std::ostream& out, const Deck& deck) {
    for (const auto& card : deck.cards) {
        out << card->getName() << " ";
    }
    return out;
}

// Explicit instantiation for the types used in the project
//template class Deck;
// Add instantiations for other types if necessary

