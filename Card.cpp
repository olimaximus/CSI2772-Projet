#include "Card.h"

// Card

/**
 * @brief Destructeur de Card
 * 
 */
Card::~Card() {}

/**
 * @brief Constructeur de Blue
 * 
 * @param name 
 */
Blue::Blue(string name){
    this->name = name;
}
/**
 * @brief retourne le nombre de cartes qui correspond au nombre de pieces en entrée
 * 
 * @param coins 
 * @return int 
 */
int Blue::getCardsPerCoin(int coins){
    if (coins < 1 || coins > 4) {
        cout << "(Blue) - Impossible value of coins passed to getCardsPerCoin : " << coins << endl;
        return -1;
    }

    const int cardsPerCoin[4] = {4,6,8,10};
    return cardsPerCoin[coins-1];
}

/**
 * @brief retourne le nom de la carte
 * 
 * @return string 
 */
string Blue::getName(){
    return this->name;
}

/**
 * @brief imprimer la première lettre de la carte
 * 
 * @param out 
 */
void Blue::print(ostream& out){
    out << this->getName()[0];
}

/**
 * @brief Constructeur de Chili
 * 
 * @param name 
 */
Chili::Chili(string name){
    this->name = name;
}


/**
 * @brief retourne le nom de la carte
 * 
 * @return string 
 */
string Chili::getName(){
    return this->name;
}

/**
 * @brief retourne le nombre de cartes qui correspond au nombre de pieces en entrée
 * 
 * @param coins 
 * @return int 
 */
int Chili::getCardsPerCoin(int coins){
    if (coins < 1 || coins > 4) {
        cout << "(Chili) - Impossible value of coins passed to getCardsPerCoin : " << coins << endl;
        return -1;
    }

    const int cardsPerCoin[4] = {3,6,8,9};
    return cardsPerCoin[coins-1];
}

/**
 * @brief imprimer la première lettre de la carte
 * 
 * @param out 
 */
void Chili::print(ostream& out){
    out << this->getName()[0];
}

/**
 * @brief Constructeur de Stink
 * 
 * @param name 
 */
Stink::Stink(string name){
    this->name = name;
}


/**
 * @brief retourne le nom de la carte
 * 
 * @return string 
 */
string Stink::getName(){
    return this->name;
}


/**
 * @brief retourne le nombre de cartes qui correspond au nombre de pieces en entrée
 * 
 * @param coins 
 * @return int 
 */
int Stink::getCardsPerCoin(int coins){
    if (coins < 1 || coins > 4) {
        cout << "(Stink) - Impossible value of coins passed to getCardsPerCoin : " << coins << endl;
        return -1;
    }

    const int cardsPerCoin[4] = {3,5,7,8};
    return cardsPerCoin[coins-1];
}


/**
 * @brief imprimer la première lettre de la carte
 * 
 * @param out 
 */
void Stink::print(ostream& out){
    out << this->getName()[0];
}

// Green
/**
 * @brief Constructeur de Green
 * 
 * @param name 
 */
Green::Green(string name){
    this->name = name;
}


/**
 * @brief retourne le nom de la carte
 * 
 * @return string 
 */
string Green::getName(){
    return this->name;
}

/**
 * @brief retourne le nombre de cartes qui correspond au nombre de pieces en entrée
 * 
 * @param coins 
 * @return int 
 */
int Green::getCardsPerCoin(int coins){
    if (coins < 1 || coins > 4) {
        cout << "(Green) - Impossible value of coins passed to getCardsPerCoin : " << coins << endl;
        return -1;
    }

    const int cardsPerCoin[4] = {3,5,6,7};
    return cardsPerCoin[coins-1];
}

/**
 * @brief imprimer la première lettre de la carte
 * 
 * @param out 
 */
void Green::print(ostream& out){
    out << this->getName()[0];
}

// soy
/**
 * @brief Constructeur de soy
 * 
 * @param name 
 */
soy::soy(string name){
    this->name = name;
}


/**
 * @brief retourne le nom de la carte
 * 
 * @return string 
 */
string soy::getName(){
    return this->name;
}

/**
 * @brief retourne le nombre de cartes qui correspond au nombre de pieces en entrée
 * 
 * @param coins 
 * @return int 
 */
int soy::getCardsPerCoin(int coins){
    if (coins < 1 || coins > 4) {
        cout << "(soy) - Impossible value of coins passed to getCardsPerCoin : " << coins << endl;
        return -1;
    }

    const int cardsPerCoin[4] = {2,4,6,7};
    return cardsPerCoin[coins-1];
}

/**
 * @brief imprimer la première lettre de la carte
 * 
 * @param out 
 */
void soy::print(ostream& out){
    out << this->getName()[0];
}

// black
/**
 * @brief Constructeur de black
 * 
 * @param name 
 */
black::black(string name){
    this->name = name;
}


/**
 * @brief retourne le nom de la carte
 * 
 * @return string 
 */
string black::getName(){
    return this->name;
}

/**
 * @brief retourne le nombre de cartes qui correspond au nombre de pieces en entrée
 * 
 * @param coins 
 * @return int 
 */
int black::getCardsPerCoin(int coins){
    if (coins < 1 || coins > 4) {
        cout << "(black) - Impossible value of coins passed to getCardsPerCoin : " << coins << endl;
        return -1;
    }

    const int cardsPerCoin[4] = {2,4,5,6};
    return cardsPerCoin[coins-1];
}

/**
 * @brief imprimer la première lettre de la carte
 * 
 * @param out 
 */
void black::print(ostream& out){
    out << this->getName()[0];
}

// Red
/**
 * @brief Constructeur de Red
 * 
 * @param name 
 */
Red::Red(string name){
    this->name = name;
}


/**
 * @brief retourne le nom de la carte
 * 
 * @return string 
 */
string Red::getName(){
    return this->name;
}

/**
 * @brief retourne le nombre de cartes qui correspond au nombre de pieces en entrée
 * 
 * @param coins 
 * @return int 
 */
int Red::getCardsPerCoin(int coins){
    if (coins < 1 || coins > 4) {
        cout << "(Red) - Impossible value of coins passed to getCardsPerCoin : " << coins << endl;
        return -1;
    }

    const int cardsPerCoin[4] = {2,3,4,5};
    return cardsPerCoin[coins-1];
}


/**
 * @brief imprimer la première lettre de la carte
 * 
 * @param out 
 */
void Red::print(ostream& out){
    out << this->getName()[0];
}

/**
 * @brief Constructeur de garden
 * 
 * @param name 
 */
garden::garden(string name){
    this->name = name;
}



/**
 * @brief retourne le nom de la carte
 * 
 * @return string 
 */
string garden::getName(){
    return this->name;
}

/**
 * @brief retourne le nombre de cartes qui correspond au nombre de pieces en entrée
 * 
 * @param coins 
 * @return int 
 */
int garden::getCardsPerCoin(int coins){
    if (coins < 1 || coins > 4) {
        cout << "(garden) - Impossible value of coins passed to getCardsPerCoin : " << coins << endl;
        return -1;
    }

    const int cardsPerCoin[4] = {INT_MAX,2,3,INT_MAX};
    return cardsPerCoin[coins-1];
}

/**
 * @brief Afficher la première lettre de la carte
 * 
 * @param out 
 */
void garden::print(ostream& out){
   out << this->getName()[0] ;
}

/**
 * @brief Opérateur d'insertion pour afficher une carte
 * 
 * @param out 
 * @param card 
 * @return ostream& 
 */
ostream& operator<<(ostream& out, Card& card) 
{ 
    card.print(out);
    return out; 
} 


/**
 * @brief Écrire la carte dans un fichier
 * 
 * @param filename 
 */
void Card::saveCard(ofstream& filename){
    filename << *this;
}