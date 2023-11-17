#include "Chain.h"
#include <iostream>

using namespace std;

template <typename T>
Chain<T>& Chain<T>::operator+=(T* card) {
    if (cards.empty() || dynamic_cast<T*>(cards.front())) {
        cards.push_back(card);
    } else {
        throw IllegalType();  // Exception si le type de carte ne correspond pas
    }
    return *this;
}

template <typename T>
int Chain<T>::sell() {
    int chainSize = cards.size();
    int coinsEarned = 0;

    if (chainSize >= 3) {
        coinsEarned = cards.front()->getCardsPerCoin(chainSize);
        // Supprimer les cartes de la chaîne
        cards.clear();
    }

    return coinsEarned;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Chain<T>& chain) {
    for (const auto& card : chain.cards) {
        out << card->getName() << " ";
    }
    return out;
}

// Explicit instantiation for the types used in the project
//template class Chain<Red>;
// Add instantiations for other types if necessary