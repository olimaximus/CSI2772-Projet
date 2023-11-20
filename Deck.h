
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>

#ifndef DECK_H
#define DECK_H

// #include "CardFactory.h"
#include "Card.h"

class CardFactory;

class Deck: public std::vector<Card*>{
     public :
        /**
         * @brief Construct a new Deck object
         * 
         */
        Deck(): std::vector<Card*>(){};
        /**
         * @brief Construct a new Deck object from an istream
         * 
         * @param input 
         * @param cf 
         */
        Deck(std::istream& input, const CardFactory* cf): std::vector<Card*>(){
            std::string line;
            Card* card = nullptr;
            int count = 0;
            while (std::getline(input, line))
            {
                std::istringstream iss(line);
                std::string data;
                if (!(iss >> data)) { 
                    continue;
                } 
                // std::cout << data << std::endl; //debug purpose
                count++;
                if(data == "B")       card = new Blue;
                else if(data == "C")  card = new Chili;
                else if(data == "S")  card = new Stink;
                else if(data == "G")  card = new Green;
                else if(data == "s")  card = new soy;
                else if(data == "b")  card = new black;
                else if(data == "R")  card = new Red;
                else if(data == "g")  card = new garden;
                else {
                    std::cout << "(Deck Constructor) Check the card name in the file. Value received : " << data << std::endl;
                    exit(1);
                }
                //
                if(card != nullptr) this->push_back(card);

            }

            std::cout << "Deck with " << count << " cards initialized from file properly." <<std::endl;

        };
        /**
         * @brief Construct a new Deck object; copy constructor
         * 
         * @param d 
         */
        Deck(const Deck& d){
            // clear the item from the current deck
            this->clear(); 
            // get the items from d inside this current deck
            for(int i = 0; i < 104; i++){
                this->push_back(d.at(i));
            }
            std::cout << "Deck of size("<<d.size()<<") copied."<<std::endl;
        }
           
        /**
         * @brief Destroy the Deck object
         * 
         */
        ~Deck(){
            for(int i = 0; i < this->size(); i++){
                // std::cout << "deleting i = " << i << "; name = " << this->at(i)->getName() << std::endl; // DEBUG PURPOSE
                delete this->at(i);
            }
            std::cout << "Deck of size("<<this->size()<<") destroyed."<<std::endl;
        };

        Card* draw();
        Deck& operator=(const Deck&);
        friend std::ostream& operator<<( std::ostream &output, const Deck& d );
        void saveDeck(std::ofstream& filename);
};

#endif