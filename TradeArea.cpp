#include "TradeArea.h"

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
  for (i = tradeAr.begin(); i != tradeAr.end(); i++) {
    if ((*i)->getName() == card->getName())
      found = true;
  }

  return found;
}

/**
 * @brief Enlève une carte du nom correspondant du TradeArea
 *
 * @param card
 * @return Card*
 */
Card *TradeArea::trade(string card) {

  Card *cardFound;
  list<Card *>::iterator i;

  for (i = tradeAr.begin(); i != tradeAr.end(); i++) {
    if ((*i)->getName() == card) {
      cardFound = *i;
      tradeAr.erase(i); // Supprimer la carte
      break;
    }
  }

  return cardFound;
}

//Retourne le nombre de cartes dans le TradeArea
int TradeArea::numCards() { return tradeAr.size(); }

/**
 * @brief Opérateur d'insertion pour afficher le TradeArea
 *
 * @param output
 * @param tr_arr
 * @return ostream
 */
ostream &operator<<(ostream &output, const TradeArea &tr_arr) {

  for (auto card : tr_arr.tradeAr) {
    output << card->getName()[0] << " ";
  }

  return output;
}

/**
 * @brief Écrire le TradeArea dans un fichier
 *
 * @param filename
 */
void TradeArea::saveTradeArea(ofstream &filename) {
  for (auto card : tradeAr) {
    card->saveCard(filename);
    filename << endl;
  }

  cout << "Saved Trade Area successfully" << endl;
}

/**
 * @brief Retourne la liste des cartes dans le TradeArea
 *
 * @return list<Card*>
 */
list<Card *> TradeArea::getListOfCards() { return tradeAr; }