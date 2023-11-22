#include "DiscardPile.h"

/**
 * @brief  returns and removes the top card from the discard pile.
 * 
 * @return Card* 
 */
Card* DiscardPile::pickUp(){
    Card* card;
    card =  this->back();
    this->pop_back();
    return card;
}

/**
 * @brief returns but does not remove the top card from the discard pile.
 * 
 * @return Card* 
 */
Card* DiscardPile::top(){
    return this->back();
}


/**
 * @brief permet d'inserer toutes les cartes du DiscardPile dans le ostream
 * 
 * @param os 
 */
void  DiscardPile::print(ostream& os){

    for(int i = 0; i < this->size(); i++){
        os << this->at(i)->getName()[0]<< " ";
    };
  
}


/**
 * @brief insertion operator to display the discard pile object (only the card on top of the discard pile)
 * 
 * @param output 
 * @param dp 
 * @return ostream& 
 */
ostream& operator<<( ostream &output, const DiscardPile& dp ){

    if(dp.size() > 0)
       (dp.back())->print(output);
    else 
       output << "";

    return output;
}

/**
 * @brief write the discard pile inside a file
 * 
 * @param filename 
 */
void DiscardPile::saveDiscardPile(ofstream& filename){
    for(int i = 0;  i < this->size() ; i++){
        this->at(i)->saveCard(filename);
        filename << endl;
    }
    cout << "Discard Pile saved." << endl;
}