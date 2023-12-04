#include "Deck.h"

/**
 * @brief Retourne et enlève la première carte du paquet
 *
 * @return Card*
 */
Card *Deck::draw() {
  Card *card = this->back(); // Copier la carte
  this->pop_back();          // Enlever la carte du paquet
  return card;               // Retourner la carte
}

/**
 * @brief Opérateur = de Deck
 *
 * @param d
 * @return Deck&
 */
Deck &Deck::operator=(const Deck &d) {
  for (int i = 0; i < d.size() && i < 104; i++) {
    this->push_back(d[i]);
  }
  return *this;
}
/**
 * @brief Opérateur d'insertion pour afficher le paquet
 *
 * @param output
 * @param d
 * @return ostream&
 */
ostream &operator<<(ostream &output, const Deck &d) {

  for (int i = 0; i < d.size(); i++) {
    output << d.at(i)->getName()[0] << endl; // Imprimer chaque carte
  }

  return output;
}

/**
 * @brief Écrire le paquet dans un fichier
 *
 * @param filename
 */
void Deck::saveDeck(ofstream &filename) {
  for (int i = 0; i < this->size(); i++) {
    this->at(i)->saveCard(filename);
    filename << endl;
  }
  cout << "Paquet sauvegarde" << endl;
}
