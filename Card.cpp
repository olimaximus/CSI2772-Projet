#include "Card.h"
#include <iostream>

using namespace std;

ostream& operator<<(std::ostream& o, const Card* carte) {
    carte->print(o);
    return o;
}

int getCardsPerCoin(int nombreCoins, const int(&cardsPerCoin)[4]) {
    if (nombreCoins < 1 || nombreCoins > 4) {
        throw invalid_argument("Le nombre de pièces doit être un int entre 1 et 4");
    }
    return cardsPerCoin[nombreCoins-1];
}

const string Blue::name = "Blue";
const int Blue::cardsPerCoin[4] = { 4,6,8,10 };
string Blue::getName() const { return name; }
void Blue::print(std::ostream& os) const { os << name[0]; }
int Blue::getCardsPerCoin(int nombreCoins) const {
    return ::getCardsPerCoin(nombreCoins, cardsPerCoin);
}

const string Chili::name = "Chili";
const int Chili::cardsPerCoin[4] = { 3,6,8,9 };
string Chili::getName() const { return name; }
void Chili::print(std::ostream& os) const { os << name[0]; }
int Chili::getCardsPerCoin(int nombreCoins) const {
    return ::getCardsPerCoin(nombreCoins, cardsPerCoin);
}

const string Stink::name = "Stink";
const int Stink::cardsPerCoin[4] = { 3,5,7,8 };
string Stink::getName() const { return name; }
void Stink::print(std::ostream& os) const { os << name[0]; }
int Stink::getCardsPerCoin(int nombreCoins) const {
    return ::getCardsPerCoin(nombreCoins, cardsPerCoin);
}

const string Green::name = "Green";
const int Green::cardsPerCoin[4] = { 3,5,6,7 };
string Green::getName() const { return name; }
void Green::print(std::ostream& os) const { os << name[0]; }
int Green::getCardsPerCoin(int nombreCoins) const {
    return ::getCardsPerCoin(nombreCoins, cardsPerCoin);
}

const string soy::name = "soy";
const int soy::cardsPerCoin[4] = { 2,4,6,7 };
string soy::getName() const { return name; }
void soy::print(std::ostream& os) const { os << name[0]; }
int soy::getCardsPerCoin(int nombreCoins) const {
    return ::getCardsPerCoin(nombreCoins, cardsPerCoin);
}

const string black::name = "black";
const int black::cardsPerCoin[4] = { 2,4,5,6 };
string black::getName() const { return name; }
void black::print(std::ostream& os) const { os << name[0]; }
int black::getCardsPerCoin(int nombreCoins) const {
    return ::getCardsPerCoin(nombreCoins, cardsPerCoin);
}

const string Red::name = "Red";
const int Red::cardsPerCoin[4] = { 2,3,4,5 };
string Red::getName() const { return name; }
void Red::print(std::ostream& os) const { os << name[0]; }
int Red::getCardsPerCoin(int nombreCoins) const {
    return ::getCardsPerCoin(nombreCoins, cardsPerCoin);
}

const string garden::name = "garden";
const int garden::cardsPerCoin[4] = { INT_MAX,2,3,INT_MAX };
string garden::getName() const { return name; }
void garden::print(std::ostream& os) const { os << name[0]; }
int garden::getCardsPerCoin(int nombreCoins) const {
    return ::getCardsPerCoin(nombreCoins, cardsPerCoin);
}