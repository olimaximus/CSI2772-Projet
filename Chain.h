
#ifndef CHAIN_H
#define CHAIN_H

#include <vector>
#include <typeinfo>
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include "Card.h"

class CardFactory;

class Chain_Base{
    protected:
        std::vector<Card*>  chain;
        std::string chainType;
    public:
        // int sell(){return 0;} ; // unimplemented
        int getSize();
        std::string getChainType();
        void setChainType(std::string chainType);
        void saveChain(std::ofstream& filename);
        Chain_Base& operator+=(Card* card){

            // std::cout << "(Chain_Base.h) chainType : " << chainType << std::endl; // debug purpose
            chain.push_back(card);
            return *this;
        };
        virtual ~Chain_Base() {};
        friend std::ostream& operator<<( std::ostream &output, const Chain_Base & d );
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
            if(std::isdigit(chainType.at(0)) ){
                // std::cout<< "The collected digit is : " << chainType.at(0) << std::endl; // debug purpose
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
        Chain(std::istream& input, const CardFactory* cf){
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
                        std::cout << "(Chain Constructor) Check the card name in the file. Value received : " << data << std::endl;
                        exit(1);
                    }
                    //
                    if(card != nullptr) (*this)+=card;

                }

                std::cout << "Chain with " << count << " cards initialized from file properly." <<std::endl;
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

            // std::cout << "(Chain.h) chainType : " << chainType << std::endl; // debug purpose
            if(typeid(T) == typeid(card) ){
                chain.push_back(card);
                return *this;
            } 
            else throw std::runtime_error("IllegalType");
        };
        /**
         * @brief  counts the number cards in the current chain and returns the number coins 
        according to the function Card::getCardsPerCoin
         * 
         * @return int 
        */
        int sell(){
            T elem; // initialize a card item to access the method getCardsPerCoin
            int value = 0;
            int max_coins = 4;
            if(chain.size() > 0){
                // check the coin value;
                for(int coin = 1;  coin <= max_coins; coin++ ){
                    if(chain.size() == elem.getCardsPerCoin(coin)){
                        value  = coin;
                        break;
                    }else if (chain.size() < elem.getCardsPerCoin(coin)){
                        value = coin-1;  // get the lower value for the coin
                        break;
                    }
                }
            }
            if(value == -1) value = 0; // put it back to zero
            return value;
        };


        friend std::ostream& operator<<( std::ostream &output, const Chain<Card*> & d );
        
};

#endif