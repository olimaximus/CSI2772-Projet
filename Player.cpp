#include "Player.h"
#include <string>
#include <iomanip>
#include <stdexcept>

/**
 * @brief Get the Name object
 * 
 * @return std::string 
 */
std::string Player::getName(){
    return this->pName;
}

/**
 * @brief get the number of cards insidde the hand of the player
 * 
 * @return int 
 */
int Player::getNumCards(){
    return pHand->numCards();
}

/**
 * @brief creates the chain when the card is played and returns that card
 * 
 * @return Card* 
 */
Card* Player::playCard(Card* input, bool specified_input){
    Card* card = nullptr;
    if (pHand->numCards() < 0)
        std::cout << "(PlayCard) Not enough card in hand for player : " << pName << std::endl;
    else{

        if(!specified_input)
            card = pHand->top();
        else
            card = input;

        Chain_Base* new_chain;
        bool ExistingChain = false;
        char user_input[2];

        // check if the chain do not already in the hand of the player
        for(Chain_Base* chain: pChains){ 
            if(chain->getChainType() == card -> getName()){
                ExistingChain = true;
                new_chain = chain;
                if(!specified_input)
                   card = pHand -> play();
                
                if(card == nullptr)  // to avoid unexpected behavior, take a card from the hand
                   card = pHand -> play();

                *new_chain += card;
                break;
            }
        }

      
        // if the chain was not found, create a new one
        if(!ExistingChain){

            if(card->getName() == "Blue") new_chain = new Chain<Blue>;
            else if(card->getName() == "Chili") new_chain = new Chain<Chili>;
            else if(card->getName() == "Stink") new_chain = new Chain<Stink>;
            else if(card->getName() == "Green") new_chain = new Chain<Green>;
            else if(card->getName() == "soy")   new_chain = new Chain<soy>;
            else if(card->getName() == "black") new_chain = new Chain<black>;
            else if(card->getName() == "Red")   new_chain = new Chain<Red>;
            else if(card->getName() == "garden")new_chain = new Chain<garden>;
            else {
                std::cout << "(playCard) Check the card name. Value received : " << card->getName() << std::endl;
                new_chain = nullptr; 
                exit(1);
            }
            
            // 
            if(pChains.size() == MAX_NUM_CHAINS){
               // MAX_NUM_CHAINS
              std::cout << "Player " <<pName << " has reached the maximum  value of chain ("<<MAX_NUM_CHAINS<<")." << std::endl;
              sellChain();
              // starting a new chain 
              startNewChain(new_chain, card);

            }
            else if(pChains.size() < ALLOWED_CHAINS){
                startNewChain(new_chain, card);
            }else{
                std::cout << ">>> Player " <<pName << " has reached the maximum allowed value of chain ("<<ALLOWED_CHAINS<<")." << std::endl;
                if (pCoins >= 3) {
                    std::cout << std::endl << "> Do you want to buy a third chain ? (y/n)" << std::endl;
                    std::cin >> user_input;
                    if(user_input[0] == 'y'){
                        // buy a third chain
                        buyThirdChain();
                        // add the card inside the newly bought chain
                        for(Chain_Base* chain : pChains){
                            if(chain->getChainType() == card -> getName()){
                                new_chain = chain;
                                card = pHand -> play();
                                *new_chain += card;
                                break;
                            }
                        }
                    }
                    else{
                        sellChain();
                        startNewChain(new_chain, card);

                    } // end of else
                } else {
                    sellChain();
                    startNewChain(new_chain, card);
                }
            } // end of else
        } // end of if
    }
    return card; 
}

/**
 * @brief retourne le nombre maximal de chaine autorisé dans le jeu pour le joueur correspondant
 * 
 * @return int 
 */
int Player::getMaxNumChains(){
    return MAX_NUM_CHAINS;
}


/**
 * @brief retourne le nombre de chaine non nul que le joueur possède 
 * 
 * @return int 
 */
int Player::getNumChains(){
    int counter = 0; 
    for(int i = 0; i < pChains.size(); i++){
        if( (pChains.at(i))->getSize() > 0) counter++;
    }
    return counter;
}


/**
 * @brief  adds an empty third chain to the player for three coins. The 
functions reduces the coin count for the player by two. If the player does not have enough coins 
then an exception NotEnoughCoins is thrown
 * 
 */
void Player::buyThirdChain(){
    Card* card = nullptr;
    if( pCoins >= 3 ){
        if(pChains.size() < MAX_NUM_CHAINS){
            pCoins -= 3;
            card = pHand->top();
            Chain_Base* new_chain;
            if(card->getName() == "Blue") new_chain = new Chain<Blue>;
            else if(card->getName() == "Chili") new_chain = new Chain<Chili>;
            else if(card->getName() == "Stink") new_chain = new Chain<Stink>;
            else if(card->getName() == "Green") new_chain = new Chain<Green>;
            else if(card->getName() == "soy")   new_chain = new Chain<soy>;
            else if(card->getName() == "black") new_chain = new Chain<black>;
            else if(card->getName() == "Red")   new_chain = new Chain<Red>;
            else if(card->getName() == "garden")new_chain = new Chain<garden>;
            else {
                std::cout << "(playCard) Check the card name. Value received : " << card->getName() << std::endl;
                new_chain = nullptr; 
                exit(1);
                
            }
            *new_chain += card;
            pChains.push_back(new_chain);
        }else{
            std::cout << "A new chain can not be bought. The maximum number ["<< pChains.size() << "] of chains have been reached. " << std::endl;
        }
        
    }else{
        throw std::runtime_error("NotEnoughCoins");
    }
}


/**
 * @brief permet d'ajouter une carte à la main du joueur
 * 
 * @param card 
 */
void Player::takeCard(Card* card){
    *pHand += card;  // add the card in the player hand
}


/**
 * @brief remove the top card from the hand of the player  at the specified position and return the corresponding card
 * 
 * @return Card* 
 */
Card* Player::removeCard(int pos){
    Card* card = nullptr;
    if(pos >  pHand->numCards()-1){
        std::cout << "Please specify the proper index to remove from the pHand. " << std::endl;
        std::cout << "Entered idx : " << pos << std::endl;
        std::cout << "Current size of hands : " << pHand->numCards() << std::endl;
        std::cout << "Card not removed." << std::endl;
    }else{
        card = (*pHand)[pos];

    }
    return card;
}

/**
 * @brief returns the number of coins that the player has
 * 
 * @return int 
 */
int Player::getNumCoins(){
    return pCoins;
}


/**
 * @brief insertion operator to display the player object
 * 
 * @param output 
 * @param player 
 * @return std::ostream 
 */
std::ostream& operator<<(std::ostream& output, const Player& player){
    output << player.pName << std::setw(5) << player.pCoins << " coins "<< std::endl;
    for(auto chain : player.pChains){
        output << *chain;
        output << std::endl;
    }

    return output;
}


/**
 * @brief write the player information inside a text file
 * 
 * @param p_id is the player id during the game
 */
void Player::savePlayer(int p_id){
    
    std::ofstream file;
    char id[2];
    
    sprintf(id, "%d", p_id);
    std::string filename ="Saved-P"+std::string(id)+".txt";

    file.open(filename, std::ios::trunc);

    // the first line should be the player name
    file << pName << std::endl;

    // the second line should be the coins of the player
    file << pCoins << std::endl;

  
    // save the hand
    pHand->saveHand(file);


    file << std::endl << "-chains" << std::endl;

    for(int i = 0 ; i < pChains.size() ; i++){
        file << std::endl << "---" << std::endl;
        pChains.at(i)->saveChain(file);
    }
    
    file << std::endl << "-end-chains" << std::endl;

    file.close();

    std::cout << "Player-"+std::string(id) << " saved. " << std::endl;
}


/**
 * @brief return the hand of the player
 * 
 * @return Hand* 
 */
Hand* Player::getHand(){
    return pHand;
}


/**
 * @brief get the chain
 * 
 */
std::vector<Chain_Base*>* Player::getChains(){
    return &pChains;
}

void Player::sellChain() {
    int idx = -1;
    bool firstTimeInLoop = true;

    while (idx < 0 || idx >= pChains.size()) {
        if (!firstTimeInLoop) std::cout << "Index " << idx << " is out of range." << std::endl;

        std::cout << "> What chain do you want to sell?" << std::endl;

        for (int i=0; i < pChains.size(); i++) {
            std::cout << "[" << i << "] "<< pChains.at(i)->getChainType() << " (" << pChains.at(i)->getSize() << " Cards)" << std::endl;
        }

        std::cout << "> Enter the corresponding index : ";
        std::cin >> idx;
        std::cout << std::endl;
        firstTimeInLoop = false;
    }

    std::string chainType = pChains.at(idx)->getChainType();

    std::cout << "> Selling Chain of type : " << chainType << std::endl;

              if(chainType == "Blue"){
                  Chain<Blue>* chain = dynamic_cast<Chain<Blue>*> (pChains.at(idx));
                  std::cout << "> Acquiring " << chain->sell() << " coins" << std::endl;
                  pCoins += chain->sell();
              }
              else if(chainType == "Chili"){
                  Chain<Chili>* chain = dynamic_cast<Chain<Chili>*> (pChains.at(idx));
                  std::cout << "> Acquiring " << chain->sell() << " coins" << std::endl;
                  pCoins += chain->sell();
              } 
              else if(chainType == "Stink"){
                  Chain<Stink>* chain = dynamic_cast<Chain<Stink>*> (pChains.at(idx));
                  std::cout << "> Acquiring " << chain->sell() << " coins" << std::endl;
                  pCoins += chain->sell();
              } 
              else if(chainType == "Green"){
                  Chain<Green>* chain = dynamic_cast<Chain<Green>*> (pChains.at(idx));
                  std::cout << "> Acquiring " << chain->sell() << " coins" << std::endl;
                  pCoins += chain->sell();
              } 
              else if(chainType == "soy"){
                  Chain<soy>* chain  = dynamic_cast<Chain<soy>*> (pChains.at(idx));
                  std::cout << "> Acquiring " << chain->sell() << " coins" << std::endl;
                  pCoins += chain->sell();
              }   
              else if(chainType == "black"){
                  Chain<black>* chain = dynamic_cast<Chain<black>*> (pChains.at(idx));
                  std::cout << "> Acquiring " << chain->sell() << " coins" << std::endl;
                  pCoins += chain->sell();
              } 
              else if(chainType == "Red"){
                  Chain<Red>* chain  = dynamic_cast<Chain<Red>*> (pChains.at(idx));
                  std::cout << "> Acquiring " << chain->sell() << " coins" << std::endl;
                  pCoins += chain->sell();
              }  
              else if(chainType == "garden"){
                  Chain<garden>* chain = dynamic_cast<Chain<garden>*> (pChains.at(idx));
                  std::cout << "> Acquiring " << chain->sell() << " coins" << std::endl;
                  pCoins += chain->sell();
              }
              else {
                std::cout << "(playCard) Check the chain type. Value received : " << chainType << std::endl;
                exit(1);
              }
             
              pChains.erase(pChains.begin() + idx); // remove the selected chain
}

void Player::startNewChain(Chain_Base* new_chain, Card* card) {
    *new_chain += card;
    pChains.push_back(new_chain);

    if( (*new_chain).getSize() == 0 ){ // update the chain type if the chain type of Chain_Base if the chain is empty
        (*new_chain).setChainType(card->getName());
    }

    card = pHand->play();
}