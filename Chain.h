
#ifndef CHAIN_H
#define CHAIN_H

#include <vector>
#include <typeinfo>
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include "Card.h"

using namespace std;

class CardFactory;

class Chain_Base{
    protected:
        vector<Card*>  chain;
        string chainType;
    public:
        int getSize();
        string getChainType();
        void setChainType(string chainType);
        void saveChain(ofstream& filename);
        Chain_Base& operator+=(Card* card){
            chain.push_back(card);
            return *this;
        };
        virtual ~Chain_Base() {};
        friend ostream& operator<<( ostream &output, const Chain_Base & d );
};


template <typename T = Card> 
class Chain : public virtual Chain_Base{
    public:
        /**
         * @brief Construct a new Chain object
         * 
         */
        Chain(){ 
            chainType = typeid(T).name();
            if(isdigit(chainType.at(0)) ){
                chainType =  chainType.substr(1,chainType.size()); // remove the first unexpected digit in the type name
            }
        };
        /**
         * @brief Construct a new Chain< T>:: Chain object
         * 
         * @tparam T 
         * @param input 
         * @param cf 
         */
        Chain(istream& input, const CardFactory* cf){
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
                        cout << "(Chain Constructor) Check the card name in the file. Value received : " << data << endl;
                        exit(1);
                    }
                    //
                    if(card != nullptr) (*this)+=card;

                }

                cout << "Chain with " << count << " cards initialized from file properly." << endl;
        };
        /**
         * @brief add the card to the chain using the operator+=
         * 
         * @param card 
         * @return Chain<T>& 
         */
        Chain<T>& operator+=(Card* card){

            if(getSize() == 0)
               chainType = typeid(card).name();// update the chain type

            if(typeid(T) == typeid(card) ){
                chain.push_back(card);
                return *this;
            } 
            else throw runtime_error("IllegalType");
        };
        /**
         * @brief  counts the number cards in the current chain and returns the number coins 
        according to the function Card::getCardsPerCoin
         * 
         * @return int 
        */
        int sell(){
            T elem; // initialize a card item to access the method getCardsPerCoin
            for (int i = 4; i > 0; i--) {
                if (chain.size() >= elem.getCardsPerCoin(i)) return i;
            }
            return 0;
        };


        friend ostream& operator<<( ostream &output, const Chain<Card*> & d );
        
};

#endif