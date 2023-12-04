#include "Main.h"
#include <fstream>
#include <sstream>

int main() {

  string p1_name;
  string p2_name;
  string winner_name;

  // Initialiser les composantes
  const int MAX_NUM_PLAYER = 2;
  Player *p1 = nullptr;
  Player *p2 = nullptr;
  Player **pArr = new Player *[MAX_NUM_PLAYER];
  DiscardPile *dp = new DiscardPile;
  CardFactory *cf = CardFactory::getFactory();
  Deck *deck = nullptr;
  TradeArea *trAr = new TradeArea;
  Table *tb;

  char user_input[2];

  // Continuer une partie sauvegardée
  cout << "Voulez-vous continuer une partie sauvegardee? (o/n)" << endl;
  cin >> user_input;

  // Chercher les fichiers, sinon les initialiser
  if (user_input[0] == 'o') {
    tb = new Table(*p1, *p2, *dp, *trAr, *deck, *cf);

    // Obtenir le Deck
    tb->reloadDeck();
    deck = tb->getDeck();

    tb->reloadPlayer(1); // Obtenir le joueur 1
    tb->reloadPlayer(2); // Obtenir le joueur 2
    p1 = tb->getPlayer(1);
    p2 = tb->getPlayer(2);

    tb->reloadDiscardPile(); // Obtenir la DiscardPile
    dp = tb->getDiscardPile();

    tb->reloadTradeArea(); // Obtenir le TradeArea
    trAr = tb->getTradeArea();

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

    tb = new Table(*p1, *p2, *dp, *trAr, *deck, *cf);

    pArr[0] = p1;
    pArr[1] = p2;

    deck = tb->getDeck();      // Obtenir le Deck
    dp = tb->getDiscardPile(); // Obtenir la DiscardPile
    trAr = tb->getTradeArea(); // Obtenir le TradeArea

    cout << "Donner 5 cartes a chaque joueur " << endl;

    // Piger 5 cartes par joueur
    for (int player = 0; player < MAX_NUM_PLAYER; player++) {
      for (int card = 0; card < 5; card++) {
        pArr[player]->takeCard(deck->draw());
      }
    }
  }

  // Boucle du jeu
  while (deck->size() != 0) {
    cout << "Taille du paquet : " << deck->size() << endl;
    cout << endl << "Voulez-vous sauvegarder votre partie et arreter? (o/n)" << endl;
    cin >> user_input;
    if (user_input[0] == 'o') {
      // Sauvegarder le jeu
      tb->saveTable();
      cout << "Partie sauvegardee" << endl;
      break;
    } else { // Commencer à jouer
      for (int i = 0; i < MAX_NUM_PLAYER; i++) {

        // Afficher la table
        cout << endl << "Info de la table:" << endl << endl << *tb << endl;

        // Tour du joueur
        cout << endl;
        cout << "Tour du joueur " << i + 1 << endl;
        cout << endl;

        Player *p = tb->getPlayer(i); // Obtenir le joueur courant

        // Piger une carte
        cout << "Obtention de la premiere carte du paquet" << endl;
        p->takeCard(deck->draw());

        cout << endl << "Main du joueur " << i + 1 << endl;
        p->printHand(cout, true);
        cout << endl;

        // Ajouter les cartes restantes du TradeArea aux chaines du joueur,
        // sinon à la DiscardPile
        if (trAr->numCards() > 0) {
          for (Card *card : trAr->getListOfCards()) {
            bool cardAdded = false;
            for (Chain_Base *chain : *(p->getChains())) {
              if (card->getName() ==
                  chain->getChainType()) { // Ajouter à une chaine
                cout << "Carte ";
                card->print(cout);
                cout << " ajoutee de l'espace d'echange a la chaine "
                     << chain->getChainType() << " du joueur" << endl;
                *chain += trAr->trade(card->getName());
                cardAdded = true;
              }
            }

            if (!cardAdded) { // Ajouter à la DiscardPile
              cout << "Carte ";
              card->print(cout);
              cout << " ajoutee de l'espace d'echange a la pile de discarte" << endl;
              *dp += trAr->trade(card->getName());
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

        cin >> user_input;

        if (user_input[0] == 'o') {

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

        cin >> user_input;

        if (user_input[0] == 'o') {

          int idx;
          Card *card = nullptr;

          cout << endl << "Main du joueur " << i + 1 << endl;
          p->printHand(cout, true);
          cout << "Taille de la main: " << p->getNumCards() << endl;
          cout << "Entrez l'index de la carte que vous voulez retirer (0 a "
               << p->getNumCards() - 1 << "): ";
          cin >> idx;

          // Enlever la carte
          card = p->removeCard(idx);

          // Valider l'entrée jusqu'à ce que la carte soit enlevée
          while (card == nullptr) {
            cout << endl
                 << "La carte n'a pas pu etre retiree. Cet index est hors-limites: " << idx
                 << endl;
            cout << "Taille de la main: " << p->getNumCards() << endl;
            cout
                << "Entrez l'index de la carte que vous voulez retirer (0 a "
                << p->getNumCards() - 1 << "): ";
            cin >> idx;
            card = p->removeCard(idx);
          }

          // Ajouter la carte à la DiscardPile
          cout << "Carte ";
          card->print(cout);
          cout << " ajoutee a la pile de discarte" << endl;
          *dp += card;
        }

        // Piger 3 cartes vers le TradeArea
        cout << endl
             << "Piger trois cartes du paquet vers l'espace d'echange" << endl
             << endl;
        for (int drw = 0; drw < 3; drw++) {
          *trAr += (deck->draw());
        }

        // Ajouter des cartes de la Discard Pile tant qu'elles correspondent
        while (dp->size() > 0 && trAr->legal(dp->top())) {
          cout << "Carte ";
          dp->top()->print(cout);
          cout << " ajoutee de la pile de discarte vers l'espace d'echange" << endl;
          *trAr += (dp->pickUp());
        }

        cout << endl << *p << endl;

        cout << endl << "Main du joueur " << i + 1 << endl;
        p->printHand(cout, true);

        cout << endl << "Espace d'echange: " << *trAr << endl;

        // Pour chaque carte du TradeArea, demander au joueur s'il veut la
        // chainer
        for (Card *card : trAr->getListOfCards()) {
          cout << endl << "Voulez-vous chainer la carte ";
          card->print(cout);
          cout << "? (o/n) " << endl;
          cin >> user_input;

          if (user_input[0] == 'o') {
            p->playCard(trAr->trade(card->getName()), true);

            cout << endl << *p << endl;

            cout << endl << "Main du joueur " << i + 1 << endl;
            p->printHand(cout, true);
            cout << endl << "Espace d'echange: " << *trAr << endl;

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

        cout << endl << "Main du joueur " << i + 1 << endl;
        p->printHand(cout, true);
        cout << endl;

        cout << endl << "Pile de discarte: ";
        dp->print(cout);
        cout << endl;
      }
    }
  }

  // Le jeu fini lorsqu'il n'y a plus de cartes dans le paquet
  if (deck->size() == 0) {
    cout << endl << "Info de la table" << endl << endl << *tb << endl;
    cout << "Aucune carte restante dans le paquet" << endl;
    tb->win(winner_name);
    cout << endl << "Le gagnant est: " << winner_name << endl;
  }

  delete tb;
  delete[] pArr;

  return 0;
};
