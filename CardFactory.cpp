#include "CardFactory.h"

CardFactory* CardFactory::instance = 0; // Initialiser l'instance à 0

/**
 * @brief Créér une instance de CardFactory avec un singleton
 * 
 * @return CardFactory* 
 */
CardFactory* CardFactory::getFactory(){
      if(!instance)
            instance = new CardFactory;
     return instance;
}

/**
 * @brief Retourne le deck du jeu
 * 
 * @return Deck* 
 */
Deck* CardFactory::getDeck(){
    int seed = static_cast<int>(chrono::system_clock::now().time_since_epoch().count()); // Initialiser la seed
    shuffle(deck->begin(), deck->end(), default_random_engine(seed)); // Mélanger les cartes
    return deck;
}


/**
 * @brief Constructeur de CardFactory
 * 
 */
CardFactory::CardFactory(){
    // Initializer le deck
    deck =  new Deck();
    // Ajouter 20 cartes Blue
    for(int i = 0; i <  20;  i++){
            Blue* carte = new Blue;
            deck ->push_back(carte);      
    }
    // Ajouter 18 cartes Chili
    for(int i = 0; i < 18; i++){
            Chili* carte = new Chili;
            deck -> push_back(carte);
    }
    // Ajouter 16 cartes Stink
    for(int i = 0; i < 16; i++){
            Stink* carte = new Stink;
            deck -> push_back(carte);
    }
    // Ajouter 14 cartes Green
    for(int i = 0; i < 14; i++){
            Green* carte = new Green;
            deck -> push_back(carte);
    }
    // Ajouter 12 cartes soy
    for(int i = 0; i < 12; i++){
            soy* carte = new soy;
            deck -> push_back(carte);
    }
    // Ajouter 10 cartes black
    for(int i = 0; i < 10;  i++){
            black* carte = new black;
            deck -> push_back(carte);
    }
    // Ajouter 8 cartes Red
    for(int i = 0; i < 8; i++){
            Red* carte = new Red;
            deck -> push_back(carte);
    }
    // Ajouter 6 cartes garden
    for(int i = 0; i < 6; i++){
            garden* carte = new garden;
            deck -> push_back(carte);
    }
}


