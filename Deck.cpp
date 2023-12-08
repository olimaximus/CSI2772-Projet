#include "Deck.h"

/**
 * @brief Opérateur = de Deck
 *
 * @param deck
 * @return Deck&
 */
Deck &Deck::operator=(const Deck &deck) {

  // Passer à travers chaque carte et les mettre à la fin du paquet
  for (int i = 0; i < deck.size() && i < 104; i++) {
    this->push_back(deck[i]);
  }

  return *this;
}
/**
 * @brief Opérateur d'insertion pour afficher le paquet
 *
 * @param output
 * @param deck
 * @return ostream&
 */
ostream &operator<<(ostream &output, const Deck &deck) {

  // Passer à travers chaque carte pour les imprimer
  for (int i = 0; i < deck.size(); i++) {
    output << deck.at(i)->getName()[0] << endl;
  }

  return output;
}

/**
 * @brief Écrire le paquet dans un fichier
 *
 * @param file
 */
void Deck::saveDeck(ofstream &file) {

  // Passer à travers chaque carte pour les sauvegarder
  for (int i = 0; i < this->size(); i++) {
    this->at(i)->saveCard(file);
    file << endl;
  }

  cout << "Paquet sauvegarde" << endl;
}

/**
 * @brief Retourne et enlève la première carte du paquet
 *
 * @return Card*
 */
Card *Deck::draw() {
  Card *c = this->back();    // Copier la carte
  this->pop_back();          // Enlever la carte du paquet
  
  return c;                  // Retourner la carte
}
