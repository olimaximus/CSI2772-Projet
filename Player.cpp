#include "Player.h"

Player::Player(const std::string& playerName) : name(playerName), coins(0), maxNumChains(2) {
    // Initialize other attributes as needed
}

std::string Player::getName() const {
    return name;
}

int Player::getNumCoins() const {
    return coins;
}

int Player::getMaxNumChains() const {
    return maxNumChains;
}

int Player::getNumChains() const {
    return chains.size();
}

Chain& Player::operator[](int i) {
    return chains[i];
}

void Player::operator+=(int numCoins) {
    coins += numCoins;
}

void Player::buyThirdChain() {
    if (coins >= 2 && chains.size() < 3) {
        chains.emplace_back(); // Add an empty chain
        coins -= 2;
    } else {
        // Handle not enough coins or maximum chains reached
    }
}

void Player::printHand(std::ostream& out, bool all) const {
    hand.print(out, all);
}

std::ostream& operator<<(std::ostream& out, const Player& player) {
    out << player.name << " " << player.coins << " coins" << std::endl;

    for (const auto& chain : player.chains) {
        out << chain << std::endl;
    }

    player.hand.print(out, false); // Only print the top card of the hand

    return out;
}
