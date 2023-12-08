#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#ifndef DECK_H
#define DECK_H
#include "Card.h"

using namespace std;

class CardFactory;

class Deck : public vector<Card *> {
public:
  /**
   * @brief Constructeur de Deck
   *
   */
  Deck() : vector<Card *>(){};
  /**
   * @brief Constructeur de Deck à partir d'un istream
   *
   * @param input
   * @param cf
   */
  Deck(istream &input, const CardFactory *cf) : vector<Card *>() {
    string line;
    Card *card = nullptr;
    int count = 0;
    while (getline(input, line)) // Passer à travers chaque ligne
    {
      istringstream iss(line);
      string data;
      if (!(iss >> data)) {
        continue;
      }

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
        cout << "(Constructeur du paquet) Valeur impossible de carte: " << data
             << endl;
        exit(1);
      }
      if (card != nullptr)
        this->push_back(card);
    }

    cout << "Paquet initialise avec " << count
         << " cartes" << endl;
  };
  /**
   * @brief Constructeur de recopie de Deck
   *
   * @param d
   */
  Deck(const Deck &d) {
    // Effacer le paquet courant
    this->clear();
    for (int i = 0; i < 104;
         i++) { // Recopier chaque carte dans le paquet courant
      this->push_back(d.at(i));
    }
    cout << "Paquet copie" << endl;
  }

  /**
   * @brief Destructeur de Deck
   *
   */
  ~Deck() {
    for (int i = 0; i < this->size(); i++) {
      delete this->at(i);
    }
  };

  Card *draw();
  Deck &operator=(const Deck &);
  friend ostream &operator<<(ostream &output, const Deck &d);
  void saveDeck(ofstream &filename);
};

#endif