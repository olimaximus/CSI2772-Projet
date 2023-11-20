#include "CardFactory.h"

CardFactory* CardFactory::instance = 0; // initialize the instance to 0

/**
 * @brief creer une instance du card factory en suivant le pattern singleton
 * 
 * @return CardFactory* 
 */
CardFactory* CardFactory::getFactory(){
      if(!instance)
            instance = new CardFactory;
     return instance;
}

/**
 * @brief retourne le deck du jeu
 * 
 * @return Deck* 
 */
Deck* CardFactory::getDeck(){
    unsigned seed = 0;
    std::shuffle(deck->begin(), deck->end(), std::default_random_engine(seed)); // shuffle 
    return deck;
}


/**
 * @brief Construct a new Card Factory:: Card Factory object
 * 
 */
CardFactory::CardFactory(){
    // initialize the deck
    deck =  new Deck();
    // add 20 Blue Cards
    for(int i = 0; i <  20;  i++){
            Blue* b = new Blue;
            deck ->push_back(b);
    
            
    }
    // add 18 Chili Cards
    for(int i = 0; i < 18; i++){
            Chili* c = new Chili;
            deck -> push_back(c);
    }
    // add 16 Stink Cards
    for(int i = 0; i < 16; i++){
            Stink* s = new Stink;
            deck -> push_back(s);
    }
    // add 14 Green Cards
    for(int i = 0; i < 14; i++){
            Green* g = new Green;
            deck -> push_back(g);
    }
    // add 12 soy Cards
    for(int i = 0; i < 12; i++){
            soy* s = new soy;
            deck -> push_back(s);
    }
    // add 10 black Cards
    for(int i = 0; i < 10;  i++){
            black* b = new black;
            deck -> push_back(b);
    }
    // add 8 Red  Cards
    for(int i = 0; i < 8; i++){
            Red* r = new Red;
            deck -> push_back(r);
    }
    // add 6 garden Cards
    for(int i = 0; i < 6; i++){
            garden* g = new garden;
            deck -> push_back(g);
    }
}


