#ifndef TABLE_H
#define TABLE_H

#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"
#include  "CardFactory.h"

using namespace std;

class Table{
    Player* p1;
    Player* p2;
    int currentPlayer; // id du joueur courant
    DiscardPile* dp;
    TradeArea* tradeAr;
    Deck* deck;
    CardFactory* cf;
    
    public:
        /**
         * @brief Constructeur de Table
         * 
         * @param p_one 
         * @param p_two 
         * @param d_pile 
         * @param tr_arr 
         * @param dck 
         * @param cfactory 
         */
        Table(Player& p_one, Player& p_two, DiscardPile& d_pile, TradeArea& tr_arr, Deck& dck, CardFactory& cfactory){
            p1 = &p_one;
            p2 = &p_two;
            dp = &d_pile;
            tradeAr = &tr_arr;
            deck = &dck;
            cf = &cfactory;
        }

        /**
         * @brief Destructeur de table
         * 
         */
        ~Table(){
            delete p1;
            delete p2;
            delete dp;
            delete tradeAr;
            delete deck;
            delete cf;
        }
        bool win(string&);
        void printHand(bool);
        friend ostream& operator<<(ostream&,  const Table&);
        void saveTable();
        void reloadPlayer(int);
        void reloadDeck();
        void reloadDiscardPile();
        void reloadTradeArea();
        Deck* getDeck();
        Player* getPlayer(int);
        DiscardPile* getDiscardPile();
        TradeArea* getTradeArea();

};

#endif