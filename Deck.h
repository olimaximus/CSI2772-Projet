
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>

#ifndef DECK_H
#define DECK_H

#include "Card.h"

using namespace std;

class CardFactory;

class Deck: public vector<Card*>{
     public :
        /**
         * @brief Construct a new Deck object
         * 
         */
        Deck(): vector<Card*>(){};
        /**
         * @brief Construct a new Deck object from an istream
         * 
         * @param input 
         * @param cf 
         */
        Deck(istream& input, const CardFactory* cf): vector<Card*>(){
            string line;
            Card* card = nullptr;
            int count = 0;
            while (getline(input, line))
            {
                istringstream iss(line);
                string data;
                if (!(iss >> data)) { 
                    continue;
                } 

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
                    cout << "(Deck Constructor) Check the card name in the file. Value received : " << data << endl;
                    exit(1);
                }
                //
                if(card != nullptr) this->push_back(card);

            }

            cout << "Deck with " << count << " cards initialized from file properly." << endl;

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
            cout << "Deck of size("<<d.size()<<") copied."<< endl;
        }
           
        /**
         * @brief Destroy the Deck object
         * 
         */
        ~Deck(){
            for(int i = 0; i < this->size(); i++){
                delete this->at(i);
            }
            cout << "Deck of size("<<this->size()<<") destroyed."<< endl;
        };

        Card* draw();
        Deck& operator=(const Deck&);
        friend ostream& operator<<( ostream &output, const Deck& d );
        void saveDeck(ofstream& filename);
};

#endif