#pragma once

#include <iostream>
#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"

class Table {
private:
    Player player1;
    Player player2;
    Deck deck;
    DiscardPile discardPile;
    TradeArea tradeArea;

public:
    Table(const std::string& name1, const std::string& name2);
    bool win(std::string& winner) const;
    void printHand(bool all) const;
    friend std::ostream& operator<<(std::ostream& out, const Table& table);
    // Add other member functions as needed
};
