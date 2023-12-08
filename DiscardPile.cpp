#include "DiscardPile.h"

/**
 * @brief Retourne et enlève la première carte de la DiscardPile
 *
 * @return Card*
 */
Card *DiscardPile::pickUp() {
  Card *card = this->back(); // Copier la carte
  this->pop_back();          // Enlever la carte du paquet
  return card;               // Retourner la carte
}

/**
 * @brief Retourne la première carte de la DiscardPile sans l'enlever
 *
 * @return Card*
 */
Card *DiscardPile::top() { return this->back(); }

/**
 * @brief Insérer les cartes de la DiscardPile dans un ostream
 *
 * @param os
 */
void DiscardPile::print(ostream &os) {

  for (int i = 0; i < this->size(); i++) {
    os << this->at(i)->getName()[0] << " "; // Imprimer chaque carte
  };
}

/**
 * @brief Opérateur d'insertion pour afficher la première carte de la
 * DiscardPile
 *
 * @param output
 * @param discardPile
 * @return ostream&
 */
ostream &operator<<(ostream &output, const DiscardPile &discardPile) {

  if (discardPile.size() > 0)
    (discardPile.back())->print(output);
  else
    output << "";

  return output;
}

/**
 * @brief Écrire la DiscardPile dans un fichier
 *
 * @param file
 */
void DiscardPile::saveDiscardPile(ofstream &file) {

  // Passer à travers chaque carte pour les sauvegarder
  for (int i = 0; i < this->size(); i++) {
    this->at(i)->saveCard(file);
    file << endl;
  }

  cout << "Pile de discarte sauvegardee" << endl;
}