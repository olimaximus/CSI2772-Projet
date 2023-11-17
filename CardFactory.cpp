#include "CardFactory.h"


CardFactory::CardFactory() {
    // Initialize all cards based on your hierarchy

    allCards.push_back(new Red());
    allCards.push_back(new Blue());
    allCards.push_back(new Chili());
    allCards.push_back(new Stink());
    allCards.push_back(new Green());
    allCards.push_back(new soy());
    allCards.push_back(new black());
    allCards.push_back(new garden());

    // Shuffle the cards
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(allCards.begin(), allCards.end(), g);
}

CardFactory* CardFactory::getFactory() {
    static CardFactory factory;
    return &factory;
}

Card* CardFactory::createCard() const {
    if (!allCards.empty()) {
        Card* createdCard = allCards.back();
        allCards.pop_back();
        return createdCard;
    } else {
        throw std::out_of_range("No more cards in the factory.");
    }
}

// Explicit instantiation for the types used in the project
//template class CardFactory;
// Add instantiations for other types if necessary
