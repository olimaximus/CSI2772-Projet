#include "Main.h"
#include <fstream>
#include <sstream>

int main() {

  string p1_name;
  string p2_name;

  // Initialiser les composantes
  const int MAX_NUM_PLAYER = 2;
  Player *p1 = nullptr;
  Player *p2 = nullptr;
  Player **pArr = new Player *[MAX_NUM_PLAYER];

  CardFactory *cf = CardFactory::getFactory();
  Deck *deck = nullptr;
  DiscardPile *discardPile = new DiscardPile;
  TradeArea *tradeArea = new TradeArea;

  Table *table;

  char input[2];

  // Continuer une partie sauvegardée
  cout << "Voulez-vous continuer une partie sauvegardee? (o/n)" << endl;
  cin >> input;

  // Chercher les fichiers, sinon les initialiser
  if (input[0] == 'o') {
    table = new Table(*p1, *p2, *discardPile, *tradeArea, *deck, *cf);

    // Obtenir les joueurs
    table->reloadPlayer(1);
    table->reloadPlayer(2);
    p1 = table->getPlayer(1);
    p2 = table->getPlayer(2);

    // Obtenir le Deck
    table->reloadDeck();
    deck = table->getDeck();

    // Obtenir la DiscardPile
    table->reloadDiscardPile();
    discardPile = table->getDiscardPile();

    // Obtenir le TradeArea
    table->reloadTradeArea();
    tradeArea = table->getTradeArea();

  } else { // Initialiser une nouvelle partie
    cout << endl;
    cout << "Entrez le nom du premier joueur (sans espaces) : ";
    cin >> p1_name;

    cout << endl;
    cout << "Entrez le nom du deuxieme joueur (sans espaces) : ";
    cin >> p2_name;

    cout << endl;

    // Créer les joueurs
    p1 = new Player(p1_name);
    p2 = new Player(p2_name);

    table = new Table(*p1, *p2, *discardPile, *tradeArea, *deck, *cf);

    pArr[0] = p1;
    pArr[1] = p2;

    //Obtenir les éléments restants
    deck = table->getDeck();
    discardPile = table->getDiscardPile();
    tradeArea = table->getTradeArea();

    // Piger 5 cartes par joueur
    cout << "Donner 5 cartes a chaque joueur " << endl;
    for (int joueur = 0; joueur < MAX_NUM_PLAYER; joueur++) {
      for (int carte = 0; carte <= 4; carte++) {
        pArr[joueur]->takeCard(deck->draw());
      }
    }
  }

  // Boucle du jeu
  while (deck->size() != 0) {
    cout << "Taille du paquet : " << deck->size() << endl;
    cout << endl << "Voulez-vous sauvegarder votre partie et arreter? (o/n)" << endl;
    cin >> input;
    if (input[0] == 'o') {
      // Sauvegarder le jeu
      table->saveTable();
      cout << "Partie sauvegardee" << endl;
      break;
    } else { // Commencer à jouer
      for (int i = 0; i < MAX_NUM_PLAYER; i++) {

        // Afficher la table
        cout << endl << "Info de la table:" << endl << endl << *table << endl;

        // Tour du joueur
        cout << endl;
        cout << "Tour du joueur " << i + 1 << endl;
        cout << endl;
        Player *p = table->getPlayer(i);

        // Piger une carte
        cout << "Obtention de la premiere carte du paquet" << endl;
        p->takeCard(deck->draw());

        cout << endl << "Main du joueur " << i + 1 << endl;
        p->printHand(cout, true);
        cout << endl;

        // Ajouter les cartes restantes du TradeArea aux chaines du joueur,
        // sinon à la DiscardPile
        if (tradeArea->numCards() > 0) {
          for (Card *card : tradeArea->getListOfCards()) {
            bool cardAdded = false;
            for (Chain_Base *chain : *(p->getChains())) {
              if (card->getName() ==
                  chain->getChainType()) { // Ajouter à une chaine
                cout << "Carte ";
                card->print(cout);
                cout << " ajoutee de l'espace d'echange a la chaine "
                     << chain->getChainType() << " du joueur" << endl;
                *chain += tradeArea->trade(card->getName());
                
                cardAdded = true;
              }
            }

            if (!cardAdded) { // Ajouter à la DiscardPile
              cout << "Carte ";
              card->print(cout);
              cout << " ajoutee de l'espace d'echange a la pile de discarte" << endl;

              *discardPile += tradeArea->trade(card->getName());
            }
          }
        }

        // Jouer la première carte de la main
        cout << endl
             << *p << endl
             << "Jouer la premiere carte de la main: "
             << p->getHand()->top()->getName()[0] << endl;
        p->playCard();

        cout << endl << *p << endl;

        cout << endl << "Main du joueur " << i + 1 << endl;
        p->printHand(cout, true);
        cout << endl;

        // Jouer la première carte optionnellement
        cout << endl
             << "Voulez-vous jouer la premiere carte de votre main ("
             << p->getHand()->top()->getName()[0] << ")? (o/n) " << endl;

        cin >> input;

        if (input[0] == 'o') {

          cout << endl
               << *p << endl
               << "Jouer la premiere carte de la main: "
               << p->getHand()->top()->getName()[0] << endl;
          p->playCard();

          cout << endl << *p << endl;

          cout << endl << "Main du joueur " << i + 1 << endl;
          p->printHand(cout, true);
          cout << endl;
        }

        // Discarter une carte optionnellement
        cout << endl
             << "Voulez-vous placer une carte dans la pile de discarte? (o/n) "
             << endl;

        cin >> input;

        if (input[0] == 'o') {

          Card *card = nullptr;
          int index;

          cout << endl << "Main du joueur " << i + 1 << endl;
          p->printHand(cout, true);
          cout << "Taille de la main: " << p->getNumCards() << endl;
          cout << "Entrez l'index de la carte que vous voulez retirer (0 a "
               << p->getNumCards() - 1 << "): ";
          cin >> index;

          // Enlever la carte
          card = p->removeCard(index);

          // Valider l'entrée jusqu'à ce que la carte soit enlevée
          while (card == nullptr) {
            cout << endl
                 << "La carte n'a pas pu etre retiree. Cet index est hors-limites: " << index
                 << endl;
            cout << "Taille de la main: " << p->getNumCards() << endl;
            cout
                << "Entrez l'index de la carte que vous voulez retirer (0 a "
                << p->getNumCards() - 1 << "): ";
            cin >> index;
            card = p->removeCard(index);
          }

          // Ajouter la carte à la DiscardPile
          cout << "Carte ";
          card->print(cout);
          cout << " ajoutee a la pile de discarte" << endl;

          *discardPile += card;
        }

        // Piger 3 cartes vers le TradeArea
        cout << endl
             << "Piger trois cartes du paquet vers l'espace d'echange" << endl
             << endl;
        for (int i = 0; i < 3; i++) {
          *tradeArea += (deck->draw());
        }

        // Ajouter des cartes de la Discard Pile tant qu'elles correspondent
        while (discardPile->size() > 0 && tradeArea->legal(discardPile->top())) {
          cout << "Carte ";
          discardPile->top()->print(cout);
          cout << " ajoutee de la pile de discarte vers l'espace d'echange" << endl;

          *tradeArea += (discardPile->pickUp());
        }

        cout << endl << *p << endl;

        cout << endl << "Main du joueur " << i + 1 << endl;
        p->printHand(cout, true);

        cout << endl << "Espace d'echange: " << *tradeArea << endl;

        // Pour chaque carte du TradeArea, demander au joueur s'il veut la
        // chainer
        for (Card *card : tradeArea->getListOfCards()) {
          cout << endl << "Voulez-vous chainer la carte ";
          card->print(cout);
          cout << "? (o/n) " << endl;
          cin >> input;

          if (input[0] == 'o') {
            p->playCard(tradeArea->trade(card->getName()), true);
            cout << endl << *p << endl;

            cout << endl << "Main du joueur " << i + 1 << endl;
            p->printHand(cout, true);

            cout << endl << "Espace d'echange: " << *tradeArea << endl;
          } else {
            cout << endl << "Carte laissee dans l'espace d'echange" << endl;
          }
        }

        // Piger 2 cartes et les mettre à la fin de la main
        for (int i = 0; i < 2; i++) {
          if (deck->size() > 0)
            cout << endl
                 << "Pige d'une carte du paquet vers la fin de la main du joueur";
          p->takeCard(deck->draw());
        }

        // Afficher l'info à la fin du tour
        cout << endl << "Main du joueur " << i + 1 << endl;
        p->printHand(cout, true);

        cout << endl << endl << "Pile de discarte: ";
        discardPile->print(cout);
        cout << endl;
      }
    }
  }

  // Le jeu fini lorsqu'il n'y a plus de cartes dans le paquet
  if (deck->size() == 0) {
    cout << endl << "Info de la table" << endl << endl << *table << endl;
    cout << "Aucune carte restante dans le paquet" << endl;

    string gagnant;
    table->win(gagnant);
    cout << endl << "Le gagnant est: " << gagnant << endl;
  }

  // Libérer la mémoire
  delete table;
  delete[] pArr;

  return 0;
};
