#ifndef HAND_H
#define HAND_H

#include "Card.h"

#include <queue>
#include <list>
#include <sstream>
#include <cstdlib>

class CardFactory;

class Hand{
    private:
        std::queue <Card*, std::list<Card*>> pHand; // player hand
        // empty the queue pHand
        void clearHand(){
            while(!pHand.empty()){
                pHand.pop();
            }
        }
    public:
        /**
         * @brief Construct a new Hand object
         * 
         */
        Hand(){};
        /**
         * @brief Construct a new Hand object from an istream
         * 
         * @param input 
         * @param cf 
         */
        Hand(std::istream& input, const CardFactory* cf){
            std::string line;
            Card* card = nullptr;
            int count = 0;
            while (std::getline(input, line))
            {
                std::istringstream iss(line);
                std::string data;
                if (!(iss >> data)) { 
                    // std::cout<< "Empty" <<std::endl;
                    continue;
                } // error
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
                    std::cout << "(Hand Constructor) Check the card name in the file. Value received : " << data << std::endl;
                    exit(1);
                }
                //
                if(card != nullptr) pHand.push(card);

            }

            std::cout << "Hand with " << count << " cards initialized from file properly." <<std::endl;

        };
        /**
         * @brief add the card inside the hand of the player
         * 
         * @param card 
         * @return Hand& 
         */
        Hand& operator+=(Card* card){
            pHand.push(card);
            return *this;
        };
        Card* play();
        Card* top();
        Card* getCard(int pos);
        std::queue <Card*, std::list<Card*>>* getListOfCards();
        /**
         * @brief  returns and removes the Card at a given index
         * 
         * @param pos 
         * @return Card* 
         */
        Card* operator[](int pos){
            Card* card = nullptr; // removed card to return
            std::queue <Card*, std::list<Card*>> temp; // temp player hand
            Card* temp_card = nullptr;  // temp card
            int find_idx = 0;
            while(!pHand.empty()){
                if(find_idx++ == pos){
                    // do not add the element in the temporary queue
                    card = pHand.front();
                    pHand.pop();
                }
                else
                {
                    temp_card = pHand.front(); // get the card
                    pHand.pop();     // add it in the temporary queue
                    temp.push(temp_card); // add the card in the queue
                }
            }

            // get the initial elements without the removed card inside pHand
            while(!temp.empty()){
              
                temp_card = temp.front(); // get the card
                temp.pop();     // add it in the temporary queue
                pHand.push(temp_card); // add the card in the queue
                
            }
            return card;  
        };
        int numCards();
        friend std::ostream& operator<<( std::ostream&,  Hand& );
        void saveHand(std::ofstream& filename);

};

#endif 