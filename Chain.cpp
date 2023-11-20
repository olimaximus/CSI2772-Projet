#include "Chain.h"
#include <iomanip>

/**
 * @brief retourne le nombre de cartes dans le deck
 * 
 * @return int 
 */
int Chain_Base::getSize(){
    return chain.size();
}

/**
 * @brief Set the ChainType of the Chain_Base
 * 
 * @param chainType 
 */
void Chain_Base::setChainType(std::string chainType){
    chainType = chainType;
}

/**
 * @brief Get the Chain Type 
 * 
 * @return std::string 
 */
std::string Chain_Base::getChainType(){
    return chainType;
}

/**
 * @brief write chain inside a file
 * 
 * @tparam T 
 * @param filename 
 */
void Chain_Base::saveChain(std::ofstream& filename){
    // std::cout << "Chain Type (Chain)" <<  chainType << std::endl; // Debug purpose
    filename << std::endl << chainType << std::endl;
    for(int i = 0; i < chain.size() ; i++){
        chain.at(i)->saveCard(filename);
        filename << std::endl;
    }

    std::cout << "Chain saved." << std::endl;
}

/**
 * @brief insertion operator to display the chain information
 * 
 * @param output 
 * @param d 
 * @return std::ostream& 
 */
std::ostream& operator<<( std::ostream &output, const Chain<Card*> & d ){
    output << d.chainType << " ";
    for(int i = 0; i < d.chain.size(); i++){
        d.chain.at(i)->print(output);
        output << " ";
    }
    
    return output;
};




/**
 * @brief insertion operator display the chain_base information
 * 
 * @param output 
 * @param d 
 * @return std::ostream& 
 */
std::ostream& operator<<( std::ostream &output, const Chain_Base & d ){
    output << d.chainType  << " " << std::setw(4);
    for(int i = 0; i < d.chain.size(); i++){
        d.chain.at(i)->print(output);
        output << " ";
    }
    
    return output;
}