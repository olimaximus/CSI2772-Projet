#include "Deck.h"
using namespace std;

/**
 * @brief returns and removes the top card from the deck
 * 
 * @return Card* 
 */
Card* Deck::draw(){
    Card* card =  this->back(); // get the last added card
    this->pop_back(); // remove the last element from the deck
    return card;  
}

/**
 * @brief assignment operator for the class Deck
 * 
 * @param d 
 * @return Deck& 
 */
Deck& Deck::operator=(const Deck& d){
    for(int i = 0 ; i < d.size() && i < 104; i++){
        this->push_back(d[i]);
    }
    return *this;
}
/**
 * @brief insertion operator to display the deck object
 * 
 * @param output 
 * @param d 
 * @return ostream& 
 */
ostream& operator<<( ostream& output, const Deck& d ){

    for(int i = 0; i < d.size(); i++){
        output << d.at(i)->getName()[0] << endl;
    }

    return output;
}


/**
 * @brief write the deck inside a file
 * 
 * @param filename 
 */
void Deck::saveDeck(std::ofstream& filename){
    for(int i = 0;  i < this->size() ; i++){
        this->at(i)->saveCard(filename);
        filename << std::endl;
    }
    std::cout << "Deck saved." << std::endl;
}





