#include "Hand.h"
#include <iostream>

using namespace std;

#include "Hand.h"

Hand& Hand::operator+=(Card* card) {
    cards.push(card);
    return *this;
}

Card* Hand::play() {
    if (!cards.empty()) {
        Card* playedCard = cards.front();
        cards.pop();
        return playedCard;
    } else {
        return nullptr; // Hand is empty
    }
}

Card* Hand::top() const {
    return (!cards.empty()) ? cards.front() : nullptr;
}

Card* Hand::operator[](int index) {
    // Assuming index is a valid position in the queue
    Card* card = nullptr;

    if (index >= 0 && index < static_cast<int>(cards.size())) {
        // Temporarily store cards until the desired one is reached
        std::queue<Card*> tempQueue = cards;
        for (int i = 0; i <= index; ++i) {
            card = tempQueue.front();
            tempQueue.pop();
        }
    }

    return card;
}

void Hand::print(std::ostream& out, bool all) const {
    std::queue<Card*> tempQueue = cards;

    while (!tempQueue.empty()) {
        out << (all ? tempQueue.front()->getName() : "X") << " ";
        tempQueue.pop();
    }
}

// Explicit instantiation for the types used in the project
template class Hand;
// Add instantiations for other types if necessary
