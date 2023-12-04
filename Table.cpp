#include "Table.h"

/**
 * @brief Retourne true si le joueur a gagné et transmets le nom du gagnant par
 * référence
 *
 * @param playerName
 * @return bool
 */
bool Table::win(string &playerName) {
  bool win = false;
  if (deck->size() == 0) {

    if (p1->getNumCoins() > p2->getNumCoins()) {
      playerName = p1->getName();
    } else if (p1->getNumCoins() < p2->getNumCoins()) {
      playerName = p2->getName();
    } else { //  Égalité
      playerName = "Partie nulle";
    }

    win = true;
  }
  return win;
}

/**
 * @brief  Si b=false: affiche la première carte de la main du joueur,
 * si b=true: affiche la main du joueur
 *
 * @param b
 */
void Table::printHand(bool b) {
  Player *current = getPlayer(currentPlayer);
  current->printHand(cout, b);
}

/**
 * @brief Retourne p1 si id==0, sinon retourne p2
 *
 * @param id
 * @return Player*
 */
Player *Table::getPlayer(int id) { return id == 0 ? p1 : p2; }

/**
 * @brief Opérateur d'insertion pour afficher la Table
 *
 * @param output
 * @param tb
 * @return ostream
 */
ostream &operator<<(ostream &output, const Table &tb) {

  output << "Joueur 1:" << endl << endl << *(tb.p1) << endl;
  output << "Joueur 2:" << endl << endl << *(tb.p2) << endl;
  output << "Dessus de la pile de discarte: " << *tb.dp << endl << endl;
  output << "Espace d'echange: " << *tb.tradeAr << endl << endl;
  return output;
};

/**
 *
 * @brief Écrire les éléments du jeu dans des fichiers
 *
 */
void Table::saveTable() {

  ofstream file;

  file.open("Deck.txt", ios::trunc);
  deck->saveDeck(file);
  file.close();

  file.open("DiscardPile.txt", ios::trunc);
  dp->saveDiscardPile(file);
  file.close();

  file.open("TradeArea.txt", ios::trunc);
  tradeAr->saveTradeArea(file);
  file.close();

  p1->savePlayer(1);
  p2->savePlayer(2);
}

/**
 * @brief Lire les informations du joueur demandé dans son fichier de sauvegarde
 *
 * @param p_id
 */
void Table::reloadPlayer(int p_id) {
  ifstream file;
  char id[2];
  sprintf(id, "%d", p_id);
  string filename = "Player" + string(id) + ".txt";
  file.open(filename);
  if (file.is_open()) {
    if (p_id == 1) {
      p1 = new Player(file, cf);
    } else {
      p2 = new Player(file, cf);
    }
  }

  file.close();
}

/**
 * @brief Lire les informations du Deck dans le fichier de sauvegarde
 *
 *
 */
void Table::reloadDeck() {
  ifstream file("Deck.txt");
  if (file.is_open()) {
    deck = new Deck(file, cf);
    file.close();
  } else { // Fichier manquant
    deck = cf->getDeck();
    cout << "Deck.txt manquant: Paquet genere a partir de CardFactory." << endl;
  }
}

//Lire les informations de la DiscardPile dans le fichier de sauvegarde
void Table::reloadDiscardPile() {
  ifstream file("DiscardPile.txt");
  if (file.is_open()) {
    dp = new DiscardPile(file, cf);
    file.close();
  } else { // Fichier manquant
    dp = new DiscardPile;
    cout << "DiscardPile.txt manquant: Pile de discarte vide cree." << endl;
  }
}

//Lire les informations du TradeArea dans le fichier de sauvegarde
void Table::reloadTradeArea() {
  ifstream file("TradeArea.txt");
  if (file.is_open()) {
    tradeAr = new TradeArea(file, cf);
    file.close();
  } else {
    // file not found
    tradeAr = new TradeArea;
    cout << "TradeArea.txt manquant: Espace d'echange vide cree." << endl;
  }
}

//Retourne le Deck de la Table en singleton
Deck *Table::getDeck() {
  if (deck == nullptr) {
    deck = cf->getDeck();
  }
  return deck;
}

//Retourne la DiscardPile de la Table
DiscardPile *Table::getDiscardPile() { return dp; }

/**
 * @brief Retourne le TradeArea de la Table
 *
 * @return TradeArea*
 */
TradeArea *Table::getTradeArea() { return tradeAr; }