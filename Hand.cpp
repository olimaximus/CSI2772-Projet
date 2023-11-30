#include "Hand.h"

//Retourne et enlève la première carte de la main
Card *Hand::play() {
  Card *card = playerHand.front();
  playerHand.pop();
  return card;
}

//Retourne la première carte de la main sans l'enlever
Card *Hand::top() { return playerHand.front(); }

//Retourne le nombre de cartes dans la main
int Hand::numCards() { return playerHand.size(); }

/**
 * @brief Retourne la carte à l'index choisi
 *
 * @param pos
 * @return Card*
 */
Card *Hand::getCard(int pos) {
  Card *card = nullptr; // Carte à retourner
  if (pos > playerHand.size() - 1) {
    std::cout << "(getCard) Unable to use index " << pos
          << ". The current size of the hand is " << playerHand.size() << std::endl;
  } else {
    queue<Card *, list<Card *>> temp; // Main du joueur temporaire
    Card *tempCard = nullptr;        // Carte temporaire
    int locate_index = 0;
    while (!playerHand.empty()) {

      if (locate_index++ == pos) {
        card = playerHand.front(); // Garder la carte voulue
      }

      // Mettre toutes les cartes dans la main temporaire
      tempCard = playerHand.front();
      playerHand.pop();
      temp.push(tempCard);
    }

    // Remettre les cartes dans la main
    while (!temp.empty()) {

      tempCard = temp.front();
      temp.pop();
      playerHand.push(tempCard);
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
ostream &operator<<(ostream &output, Hand &hand) {

  for (int pos = 0; pos < hand.numCards(); pos++) {
    output << hand.getCard(pos) << endl;
  }
  return output;
};

//Écrire la main dans un fichier
void Hand::saveHand(ofstream &filename) {
  Card *card = nullptr;
  while (!playerHand.empty()) {    // Pour chaque carte de la main
    card = playerHand.front();     // Obtenir une carte
    card->saveCard(filename); // Sauvegarder la carte
    filename << endl;
    playerHand.pop();
  }

  cout << "Saved Hand successfully" << endl;
}

/**
 * @brief Retourne la liste des cartes dans une main
 *
 * @return queue <Card*, list<Card*>>
 */
queue<Card *, list<Card *>> *Hand::getListOfCards() { return &playerHand; }
