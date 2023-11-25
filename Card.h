#include <iostream>
#include <fstream>
#include <climits>

#ifndef CARD_H
#define CARD_H

using namespace std;

class Card{
    public:
    virtual int getCardsPerCoin(int coins)=0;
    virtual string getName()=0;
    virtual void print(ostream& out)=0;
    virtual ~Card();
    void saveCard(ofstream& filename);
    /**
     * @brief Opérateur d'insertion pour afficher la première lettre d'une Carte
     * 
     * @param output 
     * @return ostream& 
     */
    ostream& operator<<(ostream& output){
        output << getName()[0] << endl;
        return output;
    };
};

class Blue : public virtual Card {
    string name;
    public:
        Blue(string name = "Blue");
        int getCardsPerCoin(int coins);
        string getName();
        void print(ostream& out);
};
class Chili : public virtual Card {
    string name;
    public:
        Chili(string name = "Chili");
        int getCardsPerCoin(int coins);
        string getName();
        void print(ostream& out);
};
class Stink : public virtual Card {
    string name;
    public:
        Stink(string name = "Stink");
        int getCardsPerCoin(int coins);
        string getName();
        void print(ostream& out);
};
class Green : public virtual Card {
    string name;
    public:
        Green(string name = "Green");
        int getCardsPerCoin(int coins);
        string getName();
        void print(ostream& out);
};
class soy : public virtual Card {
    string name;
    public:
        soy(string name="soy");
        int getCardsPerCoin(int coins);
        string getName();
        void print(ostream& out);
};
class black : public virtual Card {
    string name;
    public:
        black(string name= "black");
        int getCardsPerCoin(int coins);
        string getName();
        void print(ostream& out);
};

class Red : public virtual Card {
    string name;
    public:
        Red(string = "Red");
        int getCardsPerCoin(int coins);
        string getName();
        void print(ostream& out);
};


class garden : public virtual Card {
    string name;
    public:
        garden(string = "garden");
        int getCardsPerCoin(int coins);
        string getName();
        void print(ostream& out);
};

#endif