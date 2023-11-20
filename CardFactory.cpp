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
    int seed = static_cast<int>(chrono::system_clock::now().time_since_epoch().count());
    shuffle(deck->begin(), deck->end(), default_random_engine(seed)); // shuffle 
    return deck;
}


/**
 * @brief Construct a new Card Factory:: Card Factory object
 * 
 */
CardFactory::CardFactory(){
    // Initializer le deck
    deck =  new Deck();
    // Ajouter 20 cartes Blue
    for(int i = 0; i <  20;  i++){
            Blue* b = new Blue;
            deck ->push_back(b);
    
            
    }
    // Ajouter 18 cartes Chili
    for(int i = 0; i < 18; i++){
            Chili* c = new Chili;
            deck -> push_back(c);
    }
    // Ajouter 16 cartes Stink
    for(int i = 0; i < 16; i++){
            Stink* s = new Stink;
            deck -> push_back(s);
    }
    // Ajouter 14 cartes Green
    for(int i = 0; i < 14; i++){
            Green* g = new Green;
            deck -> push_back(g);
    }
    // Ajouter 12 cartes soy
    for(int i = 0; i < 12; i++){
            soy* s = new soy;
            deck -> push_back(s);
    }
    // Ajouter 10 cartes black
    for(int i = 0; i < 10;  i++){
            black* b = new black;
            deck -> push_back(b);
    }
    // Ajouter 8 cartes Red
    for(int i = 0; i < 8; i++){
            Red* r = new Red;
            deck -> push_back(r);
    }
    // Ajouter 6 cartes garden
    for(int i = 0; i < 6; i++){
            garden* g = new garden;
            deck -> push_back(g);
    }
}


