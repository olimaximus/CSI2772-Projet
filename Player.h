#ifndef PLAYER_H
#define PLAYER_H

#include "Chain.h"
#include "Hand.h"
#include <cstdlib>
#include <vector>


using namespace std;

class Player {
  string playerName;
  Hand *playerHand;
  vector<Chain_Base *> pChains;
  int pCoins;
  const int MAX_NUM_CHAINS;
  int ALLOWED_CHAINS;

public:
  /**
   * @brief Constructeur de Player
   *
   * @param name
   */
  Player(string &name) : MAX_NUM_CHAINS(3), ALLOWED_CHAINS(2) {
    playerName = name;
    pCoins = 0;
    playerHand = new Hand();
  };
  /**
   * @brief Constructeur de Player à partir d'un istream
   *
   * @param input
   * @param cf
   */
  Player(istream &input, const CardFactory *cf)
      : MAX_NUM_CHAINS(3), ALLOWED_CHAINS(2) {
    string line;
    string chainType;
    Card *card = nullptr;
    playerHand = new Hand();
    int chain_idx = -1; // Nombre de chaine ayant été initialisées
    int count = 0;      // Nombre de cartes ayant été reçues
    bool nameInitialized = false;
    bool coinsInitialized = false;
    bool handInitialized = false;
    bool chainsInitialized = false;
    bool chainTypeInitialized = false;

    while (getline(input, line)) // Passer à travers chaque ligne
    {
      istringstream iss(line);
      string data;
      if (!(iss >> data)) {
        continue;
      }
      // Initialiser le nom
      if (!nameInitialized) {
        playerName = data;
        nameInitialized = true;
        continue;
      }

      // Initialiser le nombre de pièces
      if (!coinsInitialized) {
        const char *str_data = &data[0];
        sscanf(str_data, "%d", &pCoins);
        coinsInitialized = true;
        continue;
      }

      // Initialiser la main
      if (!handInitialized) {
        if (data == "-chains") { // Fin de la main
          handInitialized = true;
          continue;
        } else {
          count++;
          if (data == "B")
            card = new Blue;
          else if (data == "C")
            card = new Chili;
          else if (data == "S")
            card = new Stink;
          else if (data == "G")
            card = new Green;
          else if (data == "s")
            card = new soy;
          else if (data == "b")
            card = new black;
          else if (data == "R")
            card = new Red;
          else if (data == "g")
            card = new garden;
          else {
            cout << "(Player Constructor) Impossible value of card : " << data
                 << endl;
            exit(1);
          }
          if (card != nullptr)
            *playerHand += card;
        }
      }

      // Initialiser les chaines
      if (!chainsInitialized &&
          handInitialized) { // Attendre que la main soit initialisée

        if (data == "-end-chains") { // Fin des chaines
          chainsInitialized = true;
          continue;
        } else {
          if (data == "---") { // Début d'une nouvelle chaine
            chainTypeInitialized = false;
            continue;
          } else {
            if (!chainTypeInitialized) {
              chainType = data; // La première ligne est le type de la chaine
              chainTypeInitialized = true;

              Chain_Base *new_chain;
              if (chainType == "Blue")
                new_chain = new Chain<Blue>;
              else if (chainType == "Chili")
                new_chain = new Chain<Chili>;
              else if (chainType == "Stink")
                new_chain = new Chain<Stink>;
              else if (chainType == "Green")
                new_chain = new Chain<Green>;
              else if (chainType == "soy")
                new_chain = new Chain<soy>;
              else if (chainType == "black")
                new_chain = new Chain<black>;
              else if (chainType == "Red")
                new_chain = new Chain<Red>;
              else if (chainType == "garden")
                new_chain = new Chain<garden>;
              else {
                cout << "(Player Constructor) Impossible value of chain type : "
                     << chainType << endl;
                new_chain = nullptr;
                exit(1);
              }
              // Ajouter la chaine initialisée
              if (new_chain != nullptr) {
                pChains.push_back(new_chain);
                chain_idx++;
              }

            } else {
              card = nullptr;
              // Obtenir une carte
              if (data == "B")
                card = new Blue;
              else if (data == "C")
                card = new Chili;
              else if (data == "S")
                card = new Stink;
              else if (data == "G")
                card = new Green;
              else if (data == "s")
                card = new soy;
              else if (data == "b")
                card = new black;
              else if (data == "R")
                card = new Red;
              else if (data == "g")
                card = new garden;
              else {
                cout << "(Player Constructor) Impossible value of card : "
                     << data << endl;
                exit(1);
              }
              if (chain_idx != -1 && card != nullptr) {
                *(pChains.at(chain_idx)) += card;
              } else {
                cout << "(Player Constructor) No chains have been added. "
                        "chain_idx : "
                     << chain_idx << endl;
              }
            }
          }
        }
      }
    }

    cout << "Initialised Player from file successfully" << endl;
  };

  /**
   * @brief Destructeur de Player
   *
   */
  ~Player() { delete playerHand; };

  /**
   * @brief Opérateur += pour ajouter des pièces à un joueur
   *
   * @param coins
   * @return Player&
   */
  Player &operator+=(int coins) {
    pCoins += coins;
    return *this;
  };

  /**
   * @brief Opérateur [] pour renvoyer la chaine du joueur voulue
   *
   * @param i
   * @return Chain_Base&
   */
  Chain_Base &operator[](int i) { return *(pChains.at(i)); };

  void takeCard(Card *);
  Card *playCard(Card *input = nullptr, bool specified_input = false);
  Card *removeCard(int = 0);
  string getName();
  int getNumCoins();
  int getMaxNumChains();
  int getNumChains();
  int getNumCards();
  Hand *getHand();
  vector<Chain_Base *> *getChains();
  void buyThirdChain();
  void sellChain();
  void startNewChain(Chain_Base *new_chain, Card *card, bool specified_input);

  /**
   * @brief  Si b=false: affiche la première carte de la main du joueur,
   * si b=true: affiche la main du joueur
   *
   * @param output
   * @param b
   */
  void printHand(ostream &output, bool b) {
    if (!b) {
      output << playerHand->top()->getName()[0] << endl;
    } else {
      for (int i = 0; i < playerHand->numCards(); i++) {
        output << playerHand->getCard(i)->getName()[0] << " ";
      }
      output << endl;
    }
  };

  friend ostream &operator<<(ostream &, const Player &);
  void savePlayer(int p_id);
  void checkEndedChains();
};

#endif