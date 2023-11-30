#include "Player.h"
#include <iomanip>
#include <stdexcept>
#include <string>


//Obtenir le nom d'un joueur
string Player::getName() { return this->playerName; }

//Obtenir le nombre de cartes dans la main d'un joueur
int Player::getNumCards() { return playerHand->numCards(); }

/**
 * @brief Jouer une carte vers une chaine
 * @param input
 * @param specified_input
 *
 * @return Card*
 */
Card *Player::playCard(Card *input, bool specified_input) {
  Card *card = nullptr;
  if (playerHand->numCards() < 0 && !specified_input)
    cout << "(PlayCard) Player is out of cards : " << playerName << endl;
  else {

    if (!specified_input)
      card = playerHand->top();
    else
      card = input;

    Chain_Base *new_chain;
    bool ExistingChain = false;
    char user_input[2];

    // Vérifier si le joueur a déjà la chaine
    for (Chain_Base *chain : pChains) {
      if (chain->getChainType() == card->getName()) {
        ExistingChain = true;
        new_chain = chain;
        if (!specified_input)
          card = playerHand->play();

        if (card == nullptr)
          card = playerHand->play();

        *new_chain += card;
        break;
      }
    }

    // Si la chaine n'existe pas, on en crée une nouvelle
    if (!ExistingChain) {

      if (card->getName() == "Blue")
        new_chain = new Chain<Blue>;
      else if (card->getName() == "Chili")
        new_chain = new Chain<Chili>;
      else if (card->getName() == "Stink")
        new_chain = new Chain<Stink>;
      else if (card->getName() == "Green")
        new_chain = new Chain<Green>;
      else if (card->getName() == "soy")
        new_chain = new Chain<soy>;
      else if (card->getName() == "black")
        new_chain = new Chain<black>;
      else if (card->getName() == "Red")
        new_chain = new Chain<Red>;
      else if (card->getName() == "garden")
        new_chain = new Chain<garden>;
      else {
        cout << "(playCard) Impossible value of card : " << card->getName()
             << endl;
        new_chain = nullptr;
        exit(1);
      }

      // Si le joueur a 3 chaines
      if (pChains.size() == MAX_NUM_CHAINS) {
        cout << "Player " << playerName << " already has 3 chains." << endl;
        sellChain();
        startNewChain(new_chain, card, specified_input);

      }
      // Si le joueur a moins de chaines qu'il en a droit
      else if (pChains.size() < ALLOWED_CHAINS) {
        startNewChain(new_chain, card, specified_input);
      }
      // Si le joueur a le deux chaines et qu'il n'a pas acheté la 3e
      else {
        cout << "Player " << playerName << " already has 2 chains." << endl;
        if (pCoins >= 3) {
          cout << endl << "> Do you want to buy a third chain ? (y/n)" << endl;
          cin >> user_input;
          if (user_input[0] == 'y') {
            // S'il accepte d'acheter la troisième chaine
            buyThirdChain();
            startNewChain(new_chain, card, specified_input);
          } else {
            // S'il refuse d'acheter la chaine
            sellChain();
            startNewChain(new_chain, card, specified_input);
          }
        } else {
          // S'il n'a pas assez d'argent pour acheter une troisième chaine
          sellChain();
          startNewChain(new_chain, card, specified_input);
        }
      }
    }
  }
  return card;
}

/**
 * @brief Retourne le nombre maximal de chaines autorisées du joueur
 *
 * @return int
 */
int Player::getMaxNumChains() { return ALLOWED_CHAINS; }

//Retourne le nombre de chaine non nulle que le joueur possède
int Player::getNumChains() {
  int counter = 0;
  for (int i = 0; i < pChains.size(); i++) {
    if ((pChains.at(i))->getSize() > 0)
      counter++;
  }
  return counter;
}

/**
 * @brief  Augmente le nombre de chaine maximal du joueur s'il a au moins 3
 * pièces. (Notez que le document du projet indique à un endroit que la chaine
 * coûte 3 pièces, mais à un autre qu'elle coûte 2 pièces. J'ai choisi 3.)
 *
 */
void Player::buyThirdChain() {
  if (pCoins >= 3) {
    if (pChains.size() < MAX_NUM_CHAINS) {
      pCoins -= 3;
      ALLOWED_CHAINS = 3;

    } else {
      cout << "A new chain can't be bought: the player already has 3 chains. "
           << endl;
    }

  } else {
    throw runtime_error("NotEnoughCoins");
  }
}

/**
 * @brief Ajouter une carte à la main du joueur
 *
 * @param card
 */
void Player::takeCard(Card *card) { *playerHand += card; }

/**
 * @brief Enlever une carte à une position donnée de la main du joueur
 *
 * @param pos
 *
 * @return Card*
 */
Card *Player::removeCard(int pos) {
  Card *card = nullptr;
  if (pos > playerHand->numCards() - 1) {
    cout << "Please specify the proper index to remove from the playerHand. "
         << endl;
    cout << "Entered idx : " << pos << endl;
    cout << "Current size of hands : " << playerHand->numCards() << endl;
    cout << "Card not removed." << endl;
  } else {
    card = (*playerHand)[pos];
  }
  return card;
}

//Retourne le nombre de pièces d'un joueur
int Player::getNumCoins() { return pCoins; }

/**
 * @brief Opérateur d'insertion pour afficher un joueur
 *
 * @param output
 * @param player
 * @return ostream
 */
ostream &operator<<(ostream &output, const Player &player) {
  output << player.playerName << setw(5) << player.pCoins << " coins " << endl;
  for (auto chain : player.pChains) {
    output << *chain;
    output << endl;
  }

  return output;
}

/**
 * @brief Écrire le joueur dans un fichier
 *
 * @param p_id
 */
void Player::savePlayer(int p_id) {

  ofstream file;
  char id[2];

  sprintf(id, "%d", p_id);
  string filename = "Saved-P" + string(id) + ".txt";

  file.open(filename, ios::trunc);

  // La première ligne est le nom du joueur
  file << playerName << endl;

  // La deuxième ligne est le nombre de pièces
  file << pCoins << endl;

  // Sauvegarder la main
  playerHand->saveHand(file);

  // Sauvegarder les chaines
  file << endl << "-chains" << endl;

  for (int i = 0; i < pChains.size(); i++) {
    file << endl << "---" << endl;
    pChains.at(i)->saveChain(file);
  }

  file << endl << "-end-chains" << endl;

  file.close();

  cout << "Saved Player-" + string(id) << " successfully " << endl;
}

//Retourne la main du joueur
Hand *Player::getHand() { return playerHand; }

//Retourne les chaines du joueur
vector<Chain_Base *> *Player::getChains() { return &pChains; }

//Vendre une chaine
void Player::sellChain() {
  int idx = -1;
  bool firstTimeInLoop = true;

  // Valider l'entrée
  while (idx < 0 || idx >= pChains.size()) {
    if (!firstTimeInLoop)
      cout << "Index " << idx << " is out of range." << endl;

    cout << "What chain do you want to sell?" << endl;

    for (int i = 0; i < pChains.size(); i++) {
      cout << "[" << i << "] " << pChains.at(i)->getChainType() << " ("
           << pChains.at(i)->getSize() << " Cards)" << endl;
    }

    cout << "Enter the corresponding index : ";
    cin >> idx;
    cout << endl;
    firstTimeInLoop = false;
  }

  string chainType = pChains.at(idx)->getChainType();

  cout << "Selling Chain of type : " << chainType << endl;

  // Obtenir le bon nombre de pièces

  if (chainType == "Blue") {
    Chain<Blue> *chain = dynamic_cast<Chain<Blue> *>(pChains.at(idx));
    cout << "Obtaining " << chain->sell() << " coins" << endl;
    pCoins += chain->sell();
  } else if (chainType == "Chili") {
    Chain<Chili> *chain = dynamic_cast<Chain<Chili> *>(pChains.at(idx));
    cout << "Obtaining " << chain->sell() << " coins" << endl;
    pCoins += chain->sell();
  } else if (chainType == "Stink") {
    Chain<Stink> *chain = dynamic_cast<Chain<Stink> *>(pChains.at(idx));
    cout << "Obtaining " << chain->sell() << " coins" << endl;
    pCoins += chain->sell();
  } else if (chainType == "Green") {
    Chain<Green> *chain = dynamic_cast<Chain<Green> *>(pChains.at(idx));
    cout << "Obtaining " << chain->sell() << " coins" << endl;
    pCoins += chain->sell();
  } else if (chainType == "soy") {
    Chain<soy> *chain = dynamic_cast<Chain<soy> *>(pChains.at(idx));
    cout << "Obtaining " << chain->sell() << " coins" << endl;
    pCoins += chain->sell();
  } else if (chainType == "black") {
    Chain<black> *chain = dynamic_cast<Chain<black> *>(pChains.at(idx));
    cout << "Obtaining " << chain->sell() << " coins" << endl;
    pCoins += chain->sell();
  } else if (chainType == "Red") {
    Chain<Red> *chain = dynamic_cast<Chain<Red> *>(pChains.at(idx));
    cout << "Obtaining " << chain->sell() << " coins" << endl;
    pCoins += chain->sell();
  } else if (chainType == "garden") {
    Chain<garden> *chain = dynamic_cast<Chain<garden> *>(pChains.at(idx));
    cout << "Obtaining " << chain->sell() << " coins" << endl;
    pCoins += chain->sell();
  } else {
    cout << "(playCard) Impossible value of card : " << chainType << endl;
    exit(1);
  }

  pChains.erase(pChains.begin() + idx); // Enlever la chaine correspondante
}

//Commencer une nouvelle chaine
void Player::startNewChain(Chain_Base *new_chain, Card *card,
                           bool specifiedInput) {
  *new_chain += card;
  pChains.push_back(new_chain);

  if ((*new_chain).getSize() == 0) { // Mettre à jour le type de chaine
    (*new_chain).setChainType(card->getName());
  }

  if (!specifiedInput)
    playerHand->play(); // Enlever la carte de la main, si c'est le cas
}