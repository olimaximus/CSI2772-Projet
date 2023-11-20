#include <iostream>
#include <fstream>

#ifndef CARD_H
#define CARD_H

class Card{
    public:
    virtual int getCardsPerCoin(int coins)=0;
    virtual std::string getName()=0;
    virtual void print(std::ostream& out)=0;
    virtual ~Card();
    void saveCard(std::ofstream& filename);
    /**
     * @brief insertion operator to display the first character of the card name
     * 
     * @param output 
     * @return std::ostream& 
     */
    std::ostream& operator<<(std::ostream& output){
        output << getName()[0] << std::endl;
        return output;
    };
};

class Blue : public virtual Card {
    std::string name;
    public:
        Blue(std::string name = "Blue");
        int getCardsPerCoin(int coins);
        std::string getName();
        void print(std::ostream& out);
};
class Chili : public virtual Card {
    std::string name;
    public:
        Chili(std::string name = "Chili");
        int getCardsPerCoin(int coins);
        std::string getName();
        void print(std::ostream& out);
};
class Stink : public virtual Card {
    std::string name;
    public:
        Stink(std::string name = "Stink");
        int getCardsPerCoin(int coins);
        std::string getName();
        void print(std::ostream& out);
};
class Green : public virtual Card {
    std::string name;
    public:
        Green(std::string name = "Green");
        int getCardsPerCoin(int coins);
        std::string getName();
        void print(std::ostream& out);
};
class soy : public virtual Card {
    std::string name;
    public:
        soy(std::string name="soy");
        int getCardsPerCoin(int coins);
        std::string getName();
        void print(std::ostream& out);
};
class black : public virtual Card {
    std::string name;
    public:
        black(std::string name= "black");
        int getCardsPerCoin(int coins);
        std::string getName();
        void print(std::ostream& out);
};

class Red : public virtual Card {
    std::string name;
    public:
        Red(std::string = "Red");
        int getCardsPerCoin(int coins);
        std::string getName();
        void print(std::ostream& out);
};


class garden : public virtual Card {
    std::string name;
    public:
        garden(std::string = "garden");
        int getCardsPerCoin(int coins);
        std::string getName();
        void print(std::ostream& out);
};

#endif