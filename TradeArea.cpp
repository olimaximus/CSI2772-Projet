#include "TradeArea.h"

/**
 * @brief Enlève une carte du nom correspondant du TradeArea
 *
 * @param card
 * @return Card*
 */
Card *TradeArea::trade(string card) {
  Card *cardFound;
  list<Card *>::iterator i;

  // Chercher la carte dans le TradeArea
  for (i = tradeArea.begin(); i != tradeArea.end(); i++) {
    if ((*i)->getName() == card) {
      cardFound = *i;
      tradeArea.erase(i); // Supprimer la carte
      break;
    }
  }

  return cardFound;
}

/**
 * @brief Retourne si une carte peut être ajouté au TradeArea légalement
 *
 * @param card
 * @return true
 * @return false
 */
bool TradeArea::legal(Card *card) {
  bool found = false;
  list<Card *>::iterator i;

  // Chercher la carte dans le TradeArea
  for (i = tradeArea.begin(); i != tradeArea.end(); i++) {
    if ((*i)->getName() == card->getName())
      found = true;
  }

  return found;
}



//Retourne le nombre de cartes dans le TradeArea
int TradeArea::numCards() { return tradeArea.size(); }

/**
 * @brief Opérateur d'insertion pour afficher le TradeArea
 *
 * @param output
 * @param tr_arr
 * @return ostream
 */
ostream &operator<<(ostream &output, const TradeArea &tr_arr) {

  for (auto card : tr_arr.tradeArea) {
    output << card->getName()[0] << " ";
  }

  return output;
}

/**
 * @brief Écrire le TradeArea dans un fichier
 *
 * @param file
 */
void TradeArea::saveTradeArea(ofstream &file) {

  for (auto card : tradeArea) {
    card->saveCard(file);
    file << endl;
  }

  cout << "Espace d'echange sauvegarde" << endl;
}

/**
 * @brief Retourne la liste des cartes dans le TradeArea
 *
 * @return list<Card*>
 */
list<Card *> TradeArea::getListOfCards() { return tradeArea; }