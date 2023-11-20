#include "Card.h"
using namespace std;

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
Blue::Blue(std::string name){
    this->name = name;
}
/**
 * @brief retourne le nombre de cartes qui correspond au nombre de piece
 * 
 * @param coins 
 * @return int 
 */
int Blue::getCardsPerCoin(int coins){
    int numCards = -1; // default to -1 : invalid
    switch (coins)
    {
    case 1:
        numCards = 4;
        break;
    case 2:
        numCards = 6;
        break;
    case 3:
        numCards = 8;
        break;
    case 4:
        numCards = 10;
        break;
    default:
        cout << "(Blue) - Check the value of coins passed getCardsPerCoin. Value received : " << coins << endl;
        break;
    }

    return  numCards;
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
void Blue::print(std::ostream& out){
    out << this->getName()[0];
}

/**
 * @brief Construct a new Chili:: Chili object
 * 
 * @param name 
 */
Chili::Chili(std::string name){
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
    int numCards = -1; // default to -1 : invalid
    switch (coins)
    {
    case 1:
        numCards = 3;
        break;
    case 2:
        numCards = 6;
        break;
    case 3:
        numCards = 8;
        break;
    case 4:
        numCards = 9;
        break;
    default:
        cout << "(Chili) - Check the value of coins passed getCardsPerCoin. Value received : " << coins << endl;
        break;
    }

    return  numCards;
}

/**
 * @brief display the first letter of the card name
 * 
 * @param out 
 */
void Chili::print(std::ostream& out){
    out << this->getName()[0];
}

/**
 * @brief Construct a new Stink:: Stink object
 * 
 * @param name 
 */
Stink::Stink(std::string name){
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
    int numCards = -1; // default to -1 : invalid
    switch (coins)
    {
    case 1:
        numCards = 3;
        break;
    case 2:
        numCards = 5;
        break;
    case 3:
        numCards = 7;
        break;
    case 4:
        numCards = 8;
        break;
    default:
        cout << "(Stink) - Check the value of coins passed getCardsPerCoin. Value received : " << coins << endl;
        break;
    }

    return  numCards;
}


/**
 * @brief display the first letter of the card name
 * 
 * @param out 
 */
void Stink::print(std::ostream& out){
    out << this->getName()[0];
}

// Green
/**
 * @brief Construct a new Green:: Green object
 * 
 * @param name 
 */
Green::Green(std::string name){
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
    int numCards = -1; // default to -1 : invalid
    switch (coins)
    {
    case 1:
        numCards = 3;
        break;
    case 2:
        numCards = 5;
        break;
    case 3:
        numCards = 6;
        break;
    case 4:
        numCards = 7;
        break;
    default:
        cout << "(Green) - Check the value of coins passed getCardsPerCoin. Value received : " << coins << endl;
        break;
    }

    return  numCards;
}

/**
 * @brief display the first letter of the card name
 * 
 * @param out 
 */
void Green::print(std::ostream& out){
    out << this->getName()[0];
}

// soy
/**
 * @brief Construct a new soy::soy object
 * 
 * @param name 
 */
soy::soy(std::string name){
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
    int numCards = -1; // default to -1 : invalid
    switch (coins)
    {
    case 1:
        numCards = 2;
        break;
    case 2:
        numCards = 4;
        break;
    case 3:
        numCards = 6;
        break;
    case 4:
        numCards = 7;
        break;
    default:
        cout << "(soy) - Check the value of coins passed getCardsPerCoin. Value received : " << coins << endl;
        break;
    }

    return  numCards;
}

/**
 * @brief display the first letter of the card name
 * 
 * @param out 
 */
void soy::print(std::ostream& out){
    out << this->getName()[0];
}

// black
/**
 * @brief Construct a new black::black object
 * 
 * @param name 
 */
black::black(std::string name){
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
    int numCards = -1; // default to -1 : invalid 
    switch (coins)
    {
    case 1:
        numCards = 2;
        break;
    case 2:
        numCards = 4;
        break;
    case 3:
        numCards = 5;
        break;
    case 4:
        numCards = 6;
        break;
    default:
        cout << "(black) - Check the value of coins passed getCardsPerCoin. Value received : " << coins << endl;
        break;
    }

    return  numCards;
}

/**
 * @brief display the first letter of the card name
 * 
 * @param out 
 */
void black::print(std::ostream& out){
    out << this->getName()[0];
}

// Red
/**
 * @brief Construct a new Red:: Red object
 * 
 * @param name 
 */
Red::Red(std::string name){
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
    int numCards = -1; // default to -1 : invalid
    switch (coins)
    {
    case 1:
        numCards = 2;
        break;
    case 2:
        numCards = 3;
        break;
    case 3:
        numCards = 4;
        break;
    case 4:
        numCards = 5;
        break;
    default:
        cout << "(Red) - Check the value of coins passed getCardsPerCoin. Value received : " << coins << endl;
        break;
    }

    return  numCards;
}


/**
 * @brief display the first letter of the card name
 * 
 * @param out 
 */
void Red::print(std::ostream& out){
    out << this->getName()[0];
}

/**
 * @brief Construct a new garden::garden object
 * 
 * @param name 
 */
garden::garden(std::string name){
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
    int numCards = -1; // default to -1 : invalid
    switch (coins)
    {
    case 1:
        numCards = 0;
        break;
    case 2:
        numCards = 2;
        break;
    case 3:
        numCards = 3;
        break;
    case 4:
        numCards = 0;
        break;
    default:
        cout << "(garden) - Check the value of coins passed getCardsPerCoin. Value received : " << coins << endl;
        break;
    }

    return  numCards;
}

/**
 * @brief display the first letter of the card name
 * 
 * @param out 
 */
void garden::print(std::ostream& out){
   out << this->getName()[0] ;
}

/**
 * @brief insertion operator to display the card object
 * 
 * @param out 
 * @param card 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& out, Card& card) 
{ 
    card.print(out);
    return out; 
} 


/**
 * @brief write the card inside a file
 * 
 * @param filename 
 */
void Card::saveCard(std::ofstream& filename){
    filename << *this;
}