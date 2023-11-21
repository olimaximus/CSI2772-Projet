#include "Card.h"

// Card

/**
 * @brief Destroy the Card:: Card object
 * 
 */
Card::~Card() {}

/**
 * @brief Construct a new Blue:: Blue object
 * 
 * @param name 
 */
Blue::Blue(string name){
    this->name = name;
}
/**
 * @brief retourne le nombre de cartes qui correspond au nombre de piece
 * 
 * @param coins 
 * @return int 
 */
int Blue::getCardsPerCoin(int coins){
    if (coins < 1 || coins > 4) {
        cout << "(Blue) - Check the value of coins passed getCardsPerCoin. Value received : " << coins << endl;
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
 * @brief display the first letter of the card name
 * 
 * @param out 
 */
void Blue::print(ostream& out){
    out << this->getName()[0];
}

/**
 * @brief Construct a new Chili:: Chili object
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
 * @brief retourne le nombre de cartes qui correspond au nombre de piece
 * 
 * @param coins 
 * @return int 
 */
int Chili::getCardsPerCoin(int coins){
    if (coins < 1 || coins > 4) {
        cout << "(Chili) - Check the value of coins passed getCardsPerCoin. Value received : " << coins << endl;
        return -1;
    }

    const int cardsPerCoin[4] = {3,6,8,9};
    return cardsPerCoin[coins-1];
}

/**
 * @brief display the first letter of the card name
 * 
 * @param out 
 */
void Chili::print(ostream& out){
    out << this->getName()[0];
}

/**
 * @brief Construct a new Stink:: Stink object
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
 * @brief retourne le nombre de cartes qui correspond au nombre de piece
 * 
 * @param coins 
 * @return int 
 */
int Stink::getCardsPerCoin(int coins){
    if (coins < 1 || coins > 4) {
        cout << "(Stink) - Check the value of coins passed getCardsPerCoin. Value received : " << coins << endl;
        return -1;
    }

    const int cardsPerCoin[4] = {3,5,7,8};
    return cardsPerCoin[coins-1];
}


/**
 * @brief display the first letter of the card name
 * 
 * @param out 
 */
void Stink::print(ostream& out){
    out << this->getName()[0];
}

// Green
/**
 * @brief Construct a new Green:: Green object
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
 * @brief retourne le nombre de cartes qui correspond au nombre de piece
 * 
 * @param coins 
 * @return int 
 */
int Green::getCardsPerCoin(int coins){
    if (coins < 1 || coins > 4) {
        cout << "(Green) - Check the value of coins passed getCardsPerCoin. Value received : " << coins << endl;
        return -1;
    }

    const int cardsPerCoin[4] = {3,5,6,7};
    return cardsPerCoin[coins-1];
}

/**
 * @brief display the first letter of the card name
 * 
 * @param out 
 */
void Green::print(ostream& out){
    out << this->getName()[0];
}

// soy
/**
 * @brief Construct a new soy::soy object
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
 * @brief retourne le nombre de cartes qui correspond au nombre de piece
 * 
 * @param coins 
 * @return int 
 */
int soy::getCardsPerCoin(int coins){
    if (coins < 1 || coins > 4) {
        cout << "(soy) - Check the value of coins passed getCardsPerCoin. Value received : " << coins << endl;
        return -1;
    }

    const int cardsPerCoin[4] = {2,4,6,7};
    return cardsPerCoin[coins-1];
}

/**
 * @brief display the first letter of the card name
 * 
 * @param out 
 */
void soy::print(ostream& out){
    out << this->getName()[0];
}

// black
/**
 * @brief Construct a new black::black object
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
 * @brief retourne le nombre de cartes qui correspond au nombre de piece
 * 
 * @param coins 
 * @return int 
 */
int black::getCardsPerCoin(int coins){
    if (coins < 1 || coins > 4) {
        cout << "(black) - Check the value of coins passed getCardsPerCoin. Value received : " << coins << endl;
        return -1;
    }

    const int cardsPerCoin[4] = {2,4,5,6};
    return cardsPerCoin[coins-1];
}

/**
 * @brief display the first letter of the card name
 * 
 * @param out 
 */
void black::print(ostream& out){
    out << this->getName()[0];
}

// Red
/**
 * @brief Construct a new Red:: Red object
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
 * @brief retourne le nombre de cartes qui correspond au nombre de piece
 * 
 * @param coins 
 * @return int 
 */
int Red::getCardsPerCoin(int coins){
    if (coins < 1 || coins > 4) {
        cout << "(Red) - Check the value of coins passed getCardsPerCoin. Value received : " << coins << endl;
        return -1;
    }

    const int cardsPerCoin[4] = {2,3,4,5};
    return cardsPerCoin[coins-1];
}


/**
 * @brief display the first letter of the card name
 * 
 * @param out 
 */
void Red::print(ostream& out){
    out << this->getName()[0];
}

/**
 * @brief Construct a new garden::garden object
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
 * @brief retourne le nombre de cartes qui correspond au nombre de piece
 * 
 * @param coins 
 * @return int 
 */
int garden::getCardsPerCoin(int coins){
    if (coins < 1 || coins > 4) {
        cout << "(garden) - Check the value of coins passed getCardsPerCoin. Value received : " << coins << endl;
        return -1;
    }

    const int cardsPerCoin[4] = {INT_MAX,2,3,INT_MAX};
    return cardsPerCoin[coins-1];
}

/**
 * @brief display the first letter of the card name
 * 
 * @param out 
 */
void garden::print(ostream& out){
   out << this->getName()[0] ;
}

/**
 * @brief insertion operator to display the card object
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
 * @brief write the card inside a file
 * 
 * @param filename 
 */
void Card::saveCard(ofstream& filename){
    filename << *this;
}