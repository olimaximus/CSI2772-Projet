#ifndef TRADEAREA_H
#define TRADEAREA_H

#include "Card.h"
#include <cstdlib>
#include <list>
#include <sstream>


using namespace std;

class CardFactory;

class TradeArea {
  list<Card *> tradeAr;
  const int MAX_CARDS;

public:
  /**
   * @brief Constructeur de TradeArea
   *
   */
  TradeArea() : MAX_CARDS(3){};
  /**
   * @brief Constructeur de TradeArea à partir d'un istream
   *
   * @param input
   * @param cf
   */
  TradeArea(istream &input, const CardFactory *cf) : MAX_CARDS(3) {
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
        cout << "(TradeArea Constructor) Impossible value of card : " << data
             << endl;
        exit(1);
      }
      if (card != nullptr)
        tradeAr.push_back(card);
    }

    cout << "Initialized TradeArea with " << count
         << " cards from file successfully." << endl;
  };
  /**
   * @brief Opérateur += pour ajouter une carte au TradeArea
   *
   * @param card
   * @return TradeArea&
   */
  TradeArea &operator+=(Card *card) {
    if (this->legal(card)) {
      tradeAr.push_back(card);
    } else {
      if (tradeAr.size() < 3) {
        tradeAr.push_back(card);
      } else {
        cout << "The card [" << card->getName()
             << "] couldn't be added to the TradeArea." << endl;
      }
    }
    return *this;
  };
  bool legal(Card *);
  Card *trade(string);
  int numCards();
  friend ostream &operator<<(ostream &, const TradeArea &);
  void saveTradeArea(ofstream &filename);
  list<Card *> getListOfCards();
};

#endif