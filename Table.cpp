#include "Table.h"


/**
 * @brief returns true when a player has won. The name of the player is 
returned by reference (in the argument). 
 * 
 * @param pName 
 * @return true 
 * @return false 
 */
bool Table::win(std::string& pName){
    bool win = false;
    if(deck->size() == 0){
      
       if(p1->getNumCoins() > p2->getNumCoins()){
           pName = p1->getName();
       }
       else if(p1 ->getNumCoins() < p2->getNumCoins()){
           pName = p2->getName();
       }
       else{ //  equality
           pName = "Equality";
       }

       win = true;
    }
    return win;
}

/**
 * @brief  prints the top card of the player's hand (with argument false) or all 
of the player's hand (with argument true).
 * 
 * @param in 
 */
void Table::printHand(bool in){
     Player* current = currentPlayer == 0 ? p1 : p2; // get the current player
     current -> printHand(std::cout, in);
}

/**
 * @brief return the p1 when p_id = 0 and p2 when the p_id is something else
 * 
 * @param id 
 * @return Player* 
 */
Player* Table::getPlayer(int id){
    currentPlayer = id;
    if (id==0) return p1;
    else return p2;
}


/**
 * @brief insertion operator to display the table information
 * 
 * @param output 
 * @param tb 
 * @return std::ostream 
 */
std::ostream& operator<<( std::ostream& output,  const Table&  tb){

    output << "> Player 1 : " << std::endl << std::endl << *(tb.p1) << std::endl;
    output << "> Player 2 : " << std::endl << std::endl << *(tb.p2) << std::endl;
    output << "> Discard Pile (Top) : "  << *tb.dp << std::endl << std::endl;
    output << "> Trade Area : "  << *tb.tradeAr << std::endl;
    output << "_______________________" << std::endl;
    return output;
};


/**
 * 
 * @brief write the game into the related files
 * 
 */
void Table::saveTable(){
    
    std::ofstream file;

    file.open("Saved-Deck.txt", std::ios::trunc);
    deck->saveDeck(file);

    file.close();

    file.open("Saved-DiscardPile.txt", std::ios::trunc);
    dp->saveDiscardPile(file);
    file.close();

    file.open("Saved-TradeArea.txt", std::ios::trunc);
    tradeAr->saveTradeArea(file);
    file.close();

    p1->savePlayer(1);
    p2->savePlayer(2);

}


/**
 * @brief permet de recuperer l'information dans le fichier correspondant à l'id du joueur correspondant
 * 
 * @param p_id 
 */
void Table::reloadPlayer(int p_id){
    std::ifstream file;
    char id[2];
    sprintf(id, "%d", p_id);
    std::string filename ="Saved-P"+std::string(id)+".txt";
    file.open(filename);
    if(file.is_open()){
        if(p_id == 1){
            p1 = new Player(file, cf);
        }else{ // p_id should be equal to 2
            p2 = new Player(file, cf);
        }
    }

    file.close();
    
}

/**
 * @brief permet de recuperer le deck sauvegardé dans un fichier
 * 
 * 
 */
void Table::reloadDeck(){
    std::ifstream deckFile("Saved-Deck.txt"); // add this in table ?
    if(deckFile.is_open()){
        deck = new Deck(deckFile,cf);
    }else{
        // file not found
        deck =  cf -> getDeck();
        std::cout << "Saved-Deck.txt not found. The deck has been generated from the CardFactory." << std::endl;
    }
}

/**
 * @brief reloads the discard pile from the saved file
 * 
 */
void Table::reloadDiscardPile(){
    std::ifstream dpFile("Saved-DiscardPile.txt"); // add this in table ?
    if(dpFile.is_open()){
        dp = new DiscardPile(dpFile,cf);
    }else{
        // file not found
        dp =  new DiscardPile;
        std::cout << "Saved-DiscardPile.txt not found. Using empty discard pile." << std::endl;
    }
}


/**
 * @brief reloads the trade area from the saved file
 * 
 */
void Table::reloadTradeArea(){
    std::ifstream trArFile("Saved-TradeArea.txt"); // add this in table ?
    if(trArFile.is_open()){
        tradeAr = new TradeArea(trArFile,cf);
    }else{
        // file not found
        tradeAr =  new TradeArea;
        std::cout << "Saved-TradeArea.txt not found. Using empty trade area." << std::endl;
    }
}



/**
 * @brief returns the deck initialized in the table object
 * 
 * @return Deck* 
 */
Deck* Table::getDeck(){
    if(deck == nullptr){
        deck =  cf -> getDeck();
    }
    return deck;
}


/**
 * @brief returns the discard pile of the table
 * 
 * @return DiscardPile* 
 */
DiscardPile* Table::getDiscardPile(){
    return dp;
}


/**
 * @brief returns the trade area of table
 * 
 * @return TradeArea* 
 */
TradeArea* Table::getTradeArea(){
    return tradeAr;
}