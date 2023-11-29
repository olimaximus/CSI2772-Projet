#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>


#ifndef DISCARD_PILE_H
#define DISCARD_PILE_H

#include "Card.h"

using namespace std;

class CardFactory;

class DiscardPile : public vector<Card *> {
public:
  /**
   * @brief Constructeur de DiscardPile
   *
   */
  DiscardPile() : vector<Card *>(){};

  /**
   * @brief Constructeur de DiscardPile à partir d'un istream
   *
   * @param input
   * @param cf
   */
  DiscardPile(istream &input, const CardFactory *cf) : vector<Card *>() {
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
        cout << "(DiscardPile Constructor) Impossible value of card : " << data
             << endl;
        exit(1);
      }
      if (card != nullptr)
        this->push_back(card);
    }

    cout << "Initialized DiscardPile with " << count
         << " cards from file successfully." << endl;
  };

  /**
   * @brief Opérateur += pour ajouter une carte à la DiscardPile
   *
   * @param c
   * @return DiscardPile&
   */
  DiscardPile &operator+=(Card *c) {
    this->push_back(c);
    return *this;
  };
  Card *pickUp();
  Card *top();
  void print(ostream &);
  friend ostream &operator<<(ostream &output, const DiscardPile &dp);
  void saveDiscardPile(ofstream &filename);
};

#endif