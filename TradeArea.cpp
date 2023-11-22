#include "TradeArea.h"

/**
 * @brief returns true if the card can be legally added to the TradeArea, i.e., a 
card of the same bean is already in the TradeArea.
 * 
 * @param card 
 * @return true 
 * @return false 
 */
bool TradeArea::legal (Card* card){

    bool found = false;
    list<Card*>::iterator i;
    for( i = tradeAr.begin(); i != tradeAr.end(); i++){
        if( (*i)->getName() == card->getName()) found = true;
    }

    return found;
}


/**
 * @brief removes a card of the corresponding bean name from the trade area.
 * 
 * @param card 
 * @return Card* 
 */
Card* TradeArea::trade (string card){

    Card* cardFound;
    list<Card*>::iterator i;

    for(i = tradeAr.begin(); i != tradeAr.end(); i++){
        if( (*i)->getName() == card){
            cardFound = *i;
            tradeAr.erase(i); // delete the card found
            break;
        } 
    }
    
    return cardFound;
}

/**
 * @brief retourne the number of card inside the Trade Area
 * 
 * @return int 
 */
int TradeArea::numCards(){ return tradeAr.size(); }


/**
 * @brief insertion operator to display the trade area object
 * 
 * @param output 
 * @param tr_arr 
 * @return ostream 
 */
ostream& operator<<(ostream& output, const TradeArea& tr_arr){

    for(auto card : tr_arr.tradeAr){
        output << card->getName()[0] << " ";
    }

    return output;
}


/**
 * @brief write the TradeArea information inside a file
 * 
 * @param filename 
 */
void TradeArea::saveTradeArea(ofstream& filename){
    for(auto card: tradeAr){
        card->saveCard(filename);
        filename<<endl;
    }

    cout << "TradeArea saved." << endl;
}

/**
 * @brief return the trade area list of cards
 * 
 * @return list<Card*> 
 */
list<Card*> TradeArea::getListOfCards(){
    return tradeAr;
}