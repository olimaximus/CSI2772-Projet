#ifndef HAND_H
#define HAND_H

#include "Card.h"

#include <cstdlib>
#include <list>
#include <queue>
#include <sstream>


using namespace std;

class CardFactory;

class Hand {
private:
  queue<Card *, list<Card *>> playerHand; // main du joueur
  // vider la liste de la main du joueur
  void clearHand() {
    while (!playerHand.empty()) {
      playerHand.pop();
    }
  }

public:
  /**
   * @brief Constructeur de Hand
   *
   */
  Hand(){};
  /**
   * @brief Constructeur de Hand à partir d'un istream
   *
   * @param input
   * @param cf
   */
  Hand(istream &input, const CardFactory *cf) {
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
        cout << "(Hand Constructor) Impossible value of card : " << data
             << endl;
        exit(1);
      }

      if (card != nullptr)
        playerHand.push(card);
    }

    cout << "Initialized Hand with " << count
         << " cards from file successfully." << endl;
  };
  /**
   * @brief Opérateur += pour ajouter une carte à la main du joueur
   *
   * @param card
   * @return Hand&
   */
  Hand &operator+=(Card *card) {
    playerHand.push(card);
    return *this;
  };
  Card *play();
  Card *top();
  Card *getCard(int pos);
  queue<Card *, list<Card *>> *getListOfCards();
  /**
   * @brief  Retourne et enlève la carte à l'index choisi
   *
   * @param pos
   * @return Card*
   */
  Card *operator[](int pos) {
    Card *card = nullptr;             // Carte à retourner
    queue<Card *, list<Card *>> temp; // Main du joueur temporaire
    Card *temp_card = nullptr;        // Carte temporaire
    int find_idx = 0;
    while (!playerHand.empty()) {
      if (find_idx++ == pos) {
        card = playerHand.front(); // Garder la carte voulue
        playerHand.pop();
      } else // Mettre toutes les autres cartes dans la main temporaire
      {
        temp_card = playerHand.front();
        playerHand.pop();
        temp.push(temp_card);
      }
    }

    // Remettre les autres cartes dans la main
    while (!temp.empty()) {

      temp_card = temp.front();
      temp.pop();
      playerHand.push(temp_card);
    }
    return card; // Retourner la carte voulue
  };
  int numCards();
  friend ostream &operator<<(ostream &, Hand &);
  void saveHand(ofstream &filename);
};

#endif