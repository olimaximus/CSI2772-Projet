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
    cout << "(PlayCard) Le joueur n'a plus de cartes: " << playerName << endl;
  else {

    if (!specified_input)
      card = playerHand->top();
    else
      card = input;

    Chain_Base *new_chain;
    bool ExistingChain = false;
    char user_input[2];

    // Vérifier si le joueur a déjà la chaine
    for (Chain_Base *chain : playerChains) {
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
        cout << "(playCard) Valeur impossible de carte: " << card->getName()
             << endl;
        new_chain = nullptr;
        exit(1);
      }

      // Si le joueur a 3 chaines
      if (playerChains.size() == MAX_NUM_CHAINS) {
        cout << "Le joueur " << playerName << " a deja 3 chaines" << endl;
        sellChain();
        startNewChain(new_chain, card, specified_input);

      }
      // Si le joueur a moins de chaines qu'il en a droit
      else if (playerChains.size() < ALLOWED_CHAINS) {
        startNewChain(new_chain, card, specified_input);
      }
      // Si le joueur a le deux chaines et qu'il n'a pas acheté la 3e
      else {
        cout << "Le joueur " << playerName << " a deja 2 chaines" << endl;
        if (playerCoins >= 3) {
          cout << endl << "Voulez-vous acheter une troisieme chaine? (o/n)" << endl;
          cin >> user_input;
          if (user_input[0] == 'o') {
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
  for (int i = 0; i < playerChains.size(); i++) {
    if ((playerChains.at(i))->getSize() > 0)
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
  if (playerCoins >= 3) {
    if (playerChains.size() < MAX_NUM_CHAINS) {
      playerCoins -= 3;
      ALLOWED_CHAINS = 3;

    } else {
      cout << "Impossible d'acheter une chaine: le joueur a deja 3 chaines"
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
    cout << "Veuillez entrer l'index de la carte a enlever "
         << endl;
    cout << "Index entre: " << pos << endl;
    cout << "Taille de la main: " << playerHand->numCards() << endl;
    cout << "La carte n'a pas pu etre enlevee." << endl;
  } else {
    card = (*playerHand)[pos];
  }
  return card;
}

//Retourne le nombre de pièces d'un joueur
int Player::getNumCoins() { return playerCoins; }

/**
 * @brief Opérateur d'insertion pour afficher un joueur
 *
 * @param output
 * @param player
 * @return ostream
 */
ostream &operator<<(ostream &output, const Player &player) {
  output << player.playerName << setw(6) << player.playerCoins << " pieces" << endl;
  
  for (auto chain : player.playerChains) {
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
  string filename = "Player" + string(id) + ".txt";

  file.open(filename, ios::trunc);

  // La première ligne est le nom du joueur
  file << playerName << endl;

  // La deuxième ligne est le nombre de pièces
  file << playerCoins << endl;

  // Sauvegarder la main
  playerHand->saveHand(file);

  // Sauvegarder les chaines
  file << endl << "-chains" << endl;

  for (int i = 0; i < playerChains.size(); i++) {
    file << endl << "---" << endl;
    playerChains.at(i)->saveChain(file);
  }

  file << endl << "-end-chains" << endl;

  file.close();

  cout << "Joueur-" + string(id) << " sauvegarde" << endl;
}

//Retourne la main du joueur
Hand *Player::getHand() { return playerHand; }

//Retourne les chaines du joueur
vector<Chain_Base *> *Player::getChains() { return &playerChains; }

//Vendre une chaine
void Player::sellChain() {
  int idx = -1;
  bool firstTimeInLoop = true;

  // Valider l'entrée
  while (idx < 0 || idx >= playerChains.size()) {
    if (!firstTimeInLoop)
      cout << "L'index " << idx << " est hors-limites" << endl;

    cout << "Quelle chaine voulez-vous vendre?" << endl;

    for (int i = 0; i < playerChains.size(); i++) {
      cout << "[" << i << "] " << playerChains.at(i)->getChainType() << " ("
           << playerChains.at(i)->getSize() << " cartes)" << endl;
    }

    cout << "Entrez l'index correspondant: ";
    cin >> idx;
    cout << endl;
    firstTimeInLoop = false;
  }

  string chainType = playerChains.at(idx)->getChainType();

  cout << "Vendre la chaine de type: " << chainType << endl;

  // Obtenir le bon nombre de pièces

  if (chainType == "Blue") {
    Chain<Blue> *chain = dynamic_cast<Chain<Blue> *>(playerChains.at(idx));
    cout << "Obtention de " << chain->sell() << " pieces" << endl;
    playerCoins += chain->sell();
  } else if (chainType == "Chili") {
    Chain<Chili> *chain = dynamic_cast<Chain<Chili> *>(playerChains.at(idx));
    cout << "Obtention de " << chain->sell() << " pieces" << endl;
    playerCoins += chain->sell();
  } else if (chainType == "Stink") {
    Chain<Stink> *chain = dynamic_cast<Chain<Stink> *>(playerChains.at(idx));
    cout << "Obtention de " << chain->sell() << " pieces" << endl;
    playerCoins += chain->sell();
  } else if (chainType == "Green") {
    Chain<Green> *chain = dynamic_cast<Chain<Green> *>(playerChains.at(idx));
    cout << "Obtention de " << chain->sell() << " pieces" << endl;
    playerCoins += chain->sell();
  } else if (chainType == "soy") {
    Chain<soy> *chain = dynamic_cast<Chain<soy> *>(playerChains.at(idx));
    cout << "Obtention de " << chain->sell() << " pieces" << endl;
    playerCoins += chain->sell();
  } else if (chainType == "black") {
    Chain<black> *chain = dynamic_cast<Chain<black> *>(playerChains.at(idx));
    cout << "Obtention de " << chain->sell() << " pieces" << endl;
    playerCoins += chain->sell();
  } else if (chainType == "Red") {
    Chain<Red> *chain = dynamic_cast<Chain<Red> *>(playerChains.at(idx));
    cout << "Obtention de " << chain->sell() << " pieces" << endl;
    playerCoins += chain->sell();
  } else if (chainType == "garden") {
    Chain<garden> *chain = dynamic_cast<Chain<garden> *>(playerChains.at(idx));
    cout << "Obtention de " << chain->sell() << " pieces" << endl;
    playerCoins += chain->sell();
  } else {
    cout << "(playCard) Valeur impossible de carte: " << chainType << endl;
    exit(1);
  }

  playerChains.erase(playerChains.begin() + idx); // Enlever la chaine correspondante
}

//Commencer une nouvelle chaine
void Player::startNewChain(Chain_Base *new_chain, Card *card,
                           bool specifiedInput) {
  *new_chain += card;
  playerChains.push_back(new_chain);

  if ((*new_chain).getSize() == 0) { // Mettre à jour le type de chaine
    (*new_chain).setChainType(card->getName());
  }

  if (!specifiedInput)
    playerHand->play(); // Enlever la carte de la main, si c'est le cas
}