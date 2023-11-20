#include "Hand.h"

/**
 * @brief returns and removes the top card from the player's hand.
 * 
 * @return Card* 
 */
Card* Hand::play(){
    Card* card = pHand.front();
    pHand.pop(); // remove the first element
    return card;
}

/**
 * @brief retourne la carte qui se trouve au sommet de la pile de la main (Hand)
 * 
 * @return Card* 
 */
Card* Hand::top(){
    return pHand.front();
}

/**
 * @brief retourne le nombre de cartes contenues dans la main (Hand)
 * 
 * @return int 
 */
int Hand::numCards(){
    return pHand.size();
}

/**
 * @brief retourne la carte à l'index spécifié par le paramètre pos
 * 
 * @param pos 
 * @return Card* 
 */
Card* Hand::getCard(int pos){
    Card* card = nullptr; // removed card to return
    if(pos > pHand.size()-1){
        std::cout << "(getCard) The index "  << pos << " can not be used. Current size of the hand = " << pHand.size() << std::endl;
    }else{
        std::queue <Card*, std::list<Card*>> temp; // temp player hand
        Card* temp_card = nullptr;  // temp card
        int find_idx = 0;
        while(!pHand.empty()){

            if(find_idx++ == pos){
                // get the element
                card = pHand.front();
            }
            temp_card = pHand.front(); // get the card
            pHand.pop();     // add it in the temporary queue
            temp.push(temp_card); // add the card in the queue
            
        }

        // get the initial elements without the removed card inside pHand
        while(!temp.empty()){
            
            temp_card = temp.front(); // get the card
            temp.pop();     // add it in the temporary queue
            pHand.push(temp_card); // add the card in the queue
            
        }
    }

   
    return card;  
}

/**
 * @brief insertion operator to display the content of the Hand object
 * 
 * @param output 
 * @param hand 
 * @return std::ostream& 
 */
std::ostream& operator<<( std::ostream& output, Hand& hand){

    for( int pos = 0; pos < hand.numCards() ; pos++ ){
        output << hand.getCard(pos) << std::endl;
    }
    return output;
};


/**
 * 
 * @brief write the card inside a file
 * 
 */
void Hand::saveHand(std::ofstream& filename){

    Card* card = nullptr; // removed card to return
    std::queue <Card*, std::list<Card*>> temp; // temp player hand
    Card* temp_card = nullptr;  // temp card
    int find_idx = 0;
    while(!pHand.empty()){
        temp_card = pHand.front(); // get the card
        temp_card -> saveCard(filename);
        filename << std::endl;
        pHand.pop();     // add it in the temporary queue
        temp.push(temp_card); // add the card in the queue
    }

    // get the initial elements without the removed card inside pHand
    while(!temp.empty()){
        
        temp_card = temp.front(); // get the card
        temp.pop();     // add it in the temporary queue
        pHand.push(temp_card); // add the card in the queue
        
    }

    std::cout << "Hand saved." << std::endl;
}

/**
 * @brief Get the List Of Cards inside the hand
 * 
 * @return std::queue <Card*, std::list<Card*>> 
 */
std::queue <Card*, std::list<Card*>> * Hand::getListOfCards(){
    return &pHand;
}
