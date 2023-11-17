#include "Table.h"

Table::Table(const std::string& name1, const std::string& name2)
    : player1(name1), player2(name2), deck(CardFactory::getFactory()), tradeArea(CardFactory::getFactory()) {
    // Initialize other attributes as needed
}

bool Table::win(std::string& winner) const {
    // Implement the win condition logic
    // Return true if the game is won, and set the winner's name
    return false;
}

void Table::printHand(bool all) const {
    player1.printHand(std::cout, all);
    player2.printHand(std::cout, all);
}

std::ostream& operator<<(std::ostream& out, const Table& table) {
    out << table.player1 << std::endl;
    out << table.player2 << std::endl;

    // Print other attributes of the table as needed
    table.tradeArea.print(out);

    return out;
}
