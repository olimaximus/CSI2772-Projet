#include "Card.h"

// Card

// Destructeur de Card.
Card::~Card() {}

// Constructeur de Blue.
Blue::Blue(string name) { this->name = name; }

/**
 * @brief retourne le nombre de cartes qui correspond au nombre de pieces en
 * entrée
 *
 * @param coins
 * @return int
 */
int Blue::getCardsPerCoin(int coins) {
  if (coins < 1 || coins > 4) {
    cout << "(Blue) - Impossible value of coins passed to getCardsPerCoin : "
         << coins << endl;
    return -1;
  }

  const int cardsPerCoin[4] = {4, 6, 8, 10};
  return cardsPerCoin[coins - 1];
}

//Retourne le nom de la carte
string Blue::getName() { return this->name; }

//Imprimer la première lettre de la carte
void Blue::print(ostream &out) { out << this->getName()[0]; }

//Constructeur de Chili
Chili::Chili(string name) { this->name = name; }

//Retourne le nom de la carte
string Chili::getName() { return this->name; }

/**
 * @brief retourne le nombre de cartes qui correspond au nombre de pieces en
 * entrée
 *
 * @param coins
 * @return int
 */
int Chili::getCardsPerCoin(int coins) {
  if (coins < 1 || coins > 4) {
    cout << "(Chili) - Impossible value of coins passed to getCardsPerCoin : "
         << coins << endl;
    return -1;
  }

  const int cardsPerCoin[4] = {3, 6, 8, 9};
  return cardsPerCoin[coins - 1];
}

//Imprimer la première lettre de la carte
void Chili::print(ostream &out) { out << this->getName()[0]; }

//Constructeur de Stink
Stink::Stink(string name) { this->name = name; }

//Retourne le nom de la carte
string Stink::getName() { return this->name; }

/**
 * @brief retourne le nombre de cartes qui correspond au nombre de pieces en
 * entrée
 *
 * @param coins
 * @return int
 */
int Stink::getCardsPerCoin(int coins) {
  if (coins < 1 || coins > 4) {
    cout << "(Stink) - Impossible value of coins passed to getCardsPerCoin : "
         << coins << endl;
    return -1;
  }

  const int cardsPerCoin[4] = {3, 5, 7, 8};
  return cardsPerCoin[coins - 1];
}

//imprimer la première lettre de la carte
void Stink::print(ostream &out) { out << this->getName()[0]; }

//Constructeur de Green
Green::Green(string name) { this->name = name; }

//retourne le nom de la carte
string Green::getName() { return this->name; }

/**
 * @brief retourne le nombre de cartes qui correspond au nombre de pieces en
 * entrée
 *
 * @param coins
 * @return int
 */
int Green::getCardsPerCoin(int coins) {
  if (coins < 1 || coins > 4) {
    cout << "(Green) - Impossible value of coins passed to getCardsPerCoin : "
         << coins << endl;
    return -1;
  }

  const int cardsPerCoin[4] = {3, 5, 6, 7};
  return cardsPerCoin[coins - 1];
}

//imprimer la première lettre de la carte
void Green::print(ostream &out) { out << this->getName()[0]; }

// soy

//Constructeur de soy
soy::soy(string name) { this->name = name; }

//retourne le nom de la carte
string soy::getName() { return this->name; }

/**
 * @brief retourne le nombre de cartes qui correspond au nombre de pieces en
 * entrée
 *
 * @param coins
 * @return int
 */
int soy::getCardsPerCoin(int coins) {
  if (coins < 1 || coins > 4) {
    cout << "(soy) - Impossible value of coins passed to getCardsPerCoin : "
         << coins << endl;
    return -1;
  }

  const int cardsPerCoin[4] = {2, 4, 6, 7};
  return cardsPerCoin[coins - 1];
}

//imprimer la première lettre de la carte
void soy::print(ostream &out) { out << this->getName()[0]; }

// black

//Constructeur de black
black::black(string name) { this->name = name; }

//retourne le nom de la carte
string black::getName() { return this->name; }

/**
 * @brief retourne le nombre de cartes qui correspond au nombre de pieces en
 * entrée
 *
 * @param coins
 * @return int
 */
int black::getCardsPerCoin(int coins) {
  if (coins < 1 || coins > 4) {
    cout << "(black) - Impossible value of coins passed to getCardsPerCoin : "
         << coins << endl;
    return -1;
  }

  const int cardsPerCoin[4] = {2, 4, 5, 6};
  return cardsPerCoin[coins - 1];
}

//imprimer la première lettre de la carte
void black::print(ostream &out) { out << this->getName()[0]; }

// Red

//Constructeur de Red
Red::Red(string name) { this->name = name; }

//Constructeur de Red
string Red::getName() { return this->name; }

/**
 * @brief retourne le nombre de cartes qui correspond au nombre de pieces en
 * entrée
 *
 * @param coins
 * @return int
 */
int Red::getCardsPerCoin(int coins) {
  if (coins < 1 || coins > 4) {
    cout << "(Red) - Impossible value of coins passed to getCardsPerCoin : "
         << coins << endl;
    return -1;
  }

  const int cardsPerCoin[4] = {2, 3, 4, 5};
  return cardsPerCoin[coins - 1];
}

//imprimer la première lettre de la carte
void Red::print(ostream &out) { out << this->getName()[0]; }

//Constructeur de garden
garden::garden(string name) { this->name = name; }

//retourne le nom de la carte
string garden::getName() { return this->name; }

/**
 * @brief retourne le nombre de cartes qui correspond au nombre de pieces en
 * entrée
 *
 * @param coins
 * @return int
 */
int garden::getCardsPerCoin(int coins) {
  if (coins < 1 || coins > 4) {
    cout << "(garden) - Impossible value of coins passed to getCardsPerCoin : "
         << coins << endl;
    return -1;
  }

  const int cardsPerCoin[4] = {INT_MAX, 2, 3, INT_MAX};
  return cardsPerCoin[coins - 1];
}

//Afficher la première lettre de la carte
void garden::print(ostream &out) { out << this->getName()[0]; }

/**
 * @brief Opérateur d'insertion pour afficher une carte
 *
 * @param out
 * @param card
 * @return ostream&
 */
ostream &operator<<(ostream &out, Card &card) {
  card.print(out);
  return out;
}

/**
 * @brief Écrire la carte dans un fichier
 *
 * @param filename
 */
void Card::saveCard(ofstream &filename) { filename << *this; }