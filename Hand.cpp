#include "Hand.h"

/**
 * @brief Retourne et enlève la première carte de la main
 * 
 * @return Card* 
 */
Card* Hand::play(){
    Card* card = pHand.front();
    pHand.pop();
    return card;
}

/**
 * @brief Retourne la première carte de la main sans l'enlever
 * 
 * @return Card* 
 */
Card* Hand::top(){
    return pHand.front();
}

/**
 * @brief Retourne le nombre de cartes dans la main
 * 
 * @return int 
 */
int Hand::numCards(){
    return pHand.size();
}

/**
 * @brief Retourne la carte à l'index choisi
 * 
 * @param pos 
 * @return Card* 
 */
Card* Hand::getCard(int pos){
    Card* card = nullptr; // Carte à retourner
    if(pos > pHand.size()-1){
        cout << "(getCard) The index "  << pos << " is out of range for a hand of size: " << pHand.size() << endl;
    }else{
        queue <Card*, list<Card*>> temp; // Main du joueur temporaire
        Card* temp_card = nullptr;  // Carte temporaire
        int find_idx = 0;
        while(!pHand.empty()){

            if(find_idx++ == pos){
                card = pHand.front(); // Garder la carte voulue
            }

            // Mettre toutes les cartes dans la main temporaire
            temp_card = pHand.front();
            pHand.pop();
            temp.push(temp_card);
            
        }

        // Remettre les cartes dans la main
        while(!temp.empty()){
            
            temp_card = temp.front();
            temp.pop();
            pHand.push(temp_card);
            
        }
    }

   
    return card;  
}

/**
 * @brief Opérateur d'insertion pour afficher les cartes d'une main
 * 
 * @param output 
 * @param hand 
 * @return ostream& 
 */
ostream& operator<<( ostream& output, Hand& hand){

    for( int pos = 0; pos < hand.numCards() ; pos++ ){
        output << hand.getCard(pos) << endl;
    }
    return output;
};


/**
 * 
 * @brief Écrire la main dans un fichier
 * 
 */
void Hand::saveHand(ofstream& filename){
    Card* card = nullptr;
    while(!pHand.empty()){ // Pour chaque carte de la main
        card = pHand.front(); // Obtenir une carte
        card -> saveCard(filename); // Sauvegarder la carte
        filename << endl;
        pHand.pop();
    }

    cout << "Saved Hand successfully" << endl;
}

/**
 * @brief Retourne la liste des cartes dans une main
 * 
 * @return queue <Card*, list<Card*>> 
 */
queue <Card*, list<Card*>> * Hand::getListOfCards(){
    return &pHand;
}
