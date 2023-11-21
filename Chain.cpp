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
void Chain_Base::setChainType(string chainType){
    chainType = chainType;
}

/**
 * @brief Get the Chain Type 
 * 
 * @return string 
 */
string Chain_Base::getChainType(){
    return chainType;
}

/**
 * @brief write chain inside a file
 * 
 * @tparam T 
 * @param filename 
 */
void Chain_Base::saveChain(ofstream& filename){
    filename << endl << chainType << endl;
    for(int i = 0; i < chain.size() ; i++){
        chain.at(i)->saveCard(filename);
        filename << endl;
    }

    cout << "Chain saved." << endl;
}

/**
 * @brief insertion operator to display the chain information
 * 
 * @param output 
 * @param d 
 * @return ostream& 
 */
ostream& operator<<( ostream &output, const Chain<Card*> & d ){
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
 * @return ostream& 
 */
ostream& operator<<( ostream &output, const Chain_Base & d ){
    output << d.chainType  << " " << setw(4);
    for(int i = 0; i < d.chain.size(); i++){
        d.chain.at(i)->print(output);
        output << " ";
    }
    
    return output;
}