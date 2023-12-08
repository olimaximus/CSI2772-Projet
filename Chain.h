#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <typeinfo>
#include <vector>
#ifndef CHAIN_H
#define CHAIN_H
#include "Card.h"

using namespace std;

class CardFactory;

class Chain_Base {
protected:
  vector<Card *> chain;
  string chainType;

public:
  int getSize();
  string getChainType();
  void setChainType(string chainType);
  void saveChain(ofstream &filename);
  Chain_Base &operator+=(Card *card) {
    chain.push_back(card);
    return *this;
  };
  virtual ~Chain_Base(){};
  friend ostream &operator<<(ostream &output, const Chain_Base &c);
};

template <typename T = Card> class Chain : public virtual Chain_Base {
public:
  /**
   * @brief Constructeur de Chain
   *
   */
  Chain() {
    chainType = typeid(T).name();
    if (isdigit(chainType.at(0))) {
      chainType = chainType.substr(
          1, chainType.size()); // Enlever les chiffres non attendus
    }
  };
  /**
   * @brief Constructeur de Chain<T>
   *
   * @tparam T
   * @param input
   * @param cf
   */
  Chain(istream &input, const CardFactory *cf) {
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
        cout << "(Constructeur de chaine) Valeur impossible de carte: " << data
             << endl;
        exit(1);
      }
      if (card != nullptr)
        (*this) += card; // Ajouter la carte
    }

    cout << "Chaine initialisee avec " << count
         << " cartes" << endl;
  };
  /**
   * @brief Opérateur += pour ajouter une carte à une chaine
   *
   * @param card
   * @return Chain<T>&
   */
  Chain<T> &operator+=(Card *card) {

    if (getSize() == 0)
      chainType = typeid(card).name(); // Mettre à jour le type de chaine

    if (typeid(T) == typeid(card)) {
      chain.push_back(card);
      return *this;
    } else
      throw runtime_error("IllegalType");
  };
  /**
   * @brief  Retourne la valeur de vente d'une chaine, basé sur getCardsPerCoin
   *
   * @return int
   */
  int sell() {
    T elem; // Initializer une carte
    for (int i = 4; i > 0; i--) {
      if (chain.size() >= elem.getCardsPerCoin(i))
        return i;
    }
    return 0;
  };

  friend ostream &operator<<(ostream &output, const Chain<Card *> &d);
};

#endif