#include "Game.h"
#include <iostream>

Game::Game(const std::string& name1, const std::string& name2) : table(name1, name2) {
    // Add any additional setup logic if needed
}

void Game::play() {
    std::string winner;
    while (!table.win(winner)) {
        // Implement the main game loop logic here
        // You might want to display the current state of the table, get user input, and update the game accordingly
        std::cout << table << std::endl;
        // Implement the game logic for each turn
    }

    // Display the winner
    std::cout << "Game Over! Winner: " << winner << std::endl;
}

int main() {
    // Input player names or load a paused game from a file
    std::string name1, name2;
    std::cout << "Enter Player 1 name: ";
    std::cin >> name1;
    std::cout << "Enter Player 2 name: ";
    std::cin >> name2;

    // Create and start the game
    Game game(name1, name2);
    game.play();

    return 0;
}
