#include "DiscardPile.h"
#include <iostream>

using namespace std;

#include "DiscardPile.h"

DiscardPile& DiscardPile::operator+=(Card* card) {
    cards.push_back(card);
    return *this;
}

Card* DiscardPile::pickUp() {
    if (!cards.empty()) {
        Card* pickedCard = cards.back();
        cards.pop_back();
        return pickedCard;
    } else {
        return nullptr; // DiscardPile is empty
    }
}

Card* DiscardPile::top() const {
    return (!cards.empty()) ? cards.back() : nullptr;
}

void DiscardPile::print(std::ostream& out) const {
    for (const auto& card : cards) {
        out << card->getName() << " ";
    }
}

// Explicit instantiation for the types used in the project
template class DiscardPile;
// Add instantiations for other types if necessary
