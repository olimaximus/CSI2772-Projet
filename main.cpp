#include "Main.h"
#include <fstream>
#include <sstream>


int main(){
    cout << "Projet CSI2772 - Automne 2023" << endl;
    cout << "Par Maxime Le Sage #300194479"<< endl;
    cout << "Etienne Boutet #300262462 "<< endl;

    cout << endl;

    string p1_name;
    string p2_name;
    string winner_name;

    // Initialiser les composantes
    const int MAX_NUM_PLAYER = 2;
    Player* p1 = nullptr;
    Player* p2 = nullptr;
    Player** pArr =  new Player*[MAX_NUM_PLAYER];
    DiscardPile* dp = new DiscardPile;
    CardFactory* cf = CardFactory::getFactory();
    Deck* deck =  nullptr;
    TradeArea* trAr = new TradeArea;
    Table* tb;

    char user_input[2];

    // Continuer une partie sauvegardée
    cout << "Do you want to load a saved game? (y/n)" << endl;
    cin >> user_input;

    // Chercher les fichiers, sinon les initialiser
    if(user_input[0] == 'y'){
        tb = new Table(*p1,*p2,*dp, *trAr, *deck, *cf);
        
        // Obtenir le Deck
        tb-> reloadDeck();
        deck = tb ->getDeck();

        tb -> reloadPlayer(1); // Obtenir le joueur 1
        tb -> reloadPlayer(2); // Obtenir le joueur 2
        p1 = tb -> getPlayer(1);
        p2 = tb -> getPlayer(2);

        tb -> reloadDiscardPile(); // Obtenir la DiscardPile
        dp = tb -> getDiscardPile();

        tb -> reloadTradeArea(); // Obtenir le TradeArea
        trAr = tb -> getTradeArea();
        
    } else { // Initialiser une nouvelle partie
        cout << endl;
        cout << "Enter the first player's name (without spaces) : ";
        cin  >> p1_name;
        cout << endl;
        cout << "Enter the second player's name (without spaces) : ";
        cin  >> p2_name;
        cout << endl;

        // Créer les joueurs
        p1 = new Player(p1_name);
        p2 = new Player(p2_name);

        tb = new Table(*p1,*p2,*dp, *trAr, *deck, *cf);

        pArr[0] = p1;
        pArr[1] = p2;

        deck = tb -> getDeck();        // Obtenir le Deck
        dp   = tb -> getDiscardPile(); // Obtenir la DiscardPile
        trAr = tb -> getTradeArea();   // Obtenir le TradeArea

        cout << "Drawing 5 cards for each player. " << endl;

        // Piger 5 cartes par joueur
        for(int player = 0 ; player < MAX_NUM_PLAYER ; player++){
            for(int card = 0; card < 5; card++){
                pArr[player]->takeCard(deck->draw());
            }
        }
    }
  
    // Boucle du jeu
    while(deck->size() != 0){
       cout << "Current size of Deck : " << deck->size() << endl;
       cout << endl << "Do you want to pause and save the game? (y/n)" << endl;
       cin >> user_input;
       if(user_input[0] == 'y'){
           // Sauvegarder le jeu
           tb -> saveTable();
           cout << "Game saved. Bye." << endl;
           break;
       }
       else{ // Commencer à jouer
           for(int i = 0; i < MAX_NUM_PLAYER; i++){

               // Afficher la table
               cout << endl <<  "Table info:" << endl << endl << *tb << endl;

               // Tour du joueur
               cout << endl;
               cout << "Player " << i+1 << " turn." << endl;
               cout << endl;

               Player* p = tb -> getPlayer(i);  // Obtenir le joueur courant
             
               // Piger une carte
               cout <<  "Drawing top card from the deck" << endl;
               p->takeCard(deck->draw());

               cout << endl << "Player " << i+1 << "'s hand: " << endl;
               p->printHand(cout, true);
               cout << endl;

               // Ajouter les cartes restantes du TradeArea aux chaines du joueur, sinon à la DiscardPile
               if(trAr->numCards() > 0) {
                   for( Card* card : trAr->getListOfCards() ){
                        bool cardAdded = false;
                        for( Chain_Base* chain : *(p->getChains()) ){
                            if(card->getName() == chain->getChainType()){ // Ajouter à une chaine
                                cout << "Card : " ;
                                card->print(cout);
                                cout << " added from trade area to the player's " << chain->getChainType() << " chain " << endl;
                                *chain += trAr->trade(card->getName());
                                cardAdded = true;
                            }
                        }

                        if(!cardAdded){ // Ajouter à la DiscardPile
                           cout << "Card " ;
                           card->print(cout);
                           cout << " added from trade area to discard pile " << endl;
                           *dp+=trAr->trade(card->getName());
                        }
                   }
               }

               // Jouer la première carte de la main
               cout << endl << *p << endl << "Playing first card from hand: " << p->getHand()->top()->getName()[0] << endl;
               p->playCard();

               cout << endl <<  *p << endl;

               cout << endl << "Player " << i+1 << "'s hand: " << endl;
               p->printHand(cout, true);
               cout << endl;

               // Jouer la première carte optionnellement
               cout << endl << "Do you want to play the first card from your hand (" << p->getHand()->top()->getName()[0] <<")? (y/n) " << endl;

               cin >> user_input; 

               if(user_input[0] == 'y'){

                   cout << endl << *p << endl << "Playing first card from hand: " << p->getHand()->top()->getName()[0] << endl;
                   p -> playCard();
                   
                   cout << endl <<  *p << endl;

                   cout << endl << "Player " << i+1 << "'s hand: " << endl;
                   p->printHand(cout, true);
                   cout << endl;

               }

               // Discarter une carte optionnellement
               cout << endl << "Do you want to leave a card in the Discard Pile? (y/n) " << endl;

               cin >> user_input; 

               if (user_input[0] == 'y') {

                   int idx; 
                   Card* card = nullptr;

                   cout << endl << "Player " << i+1 << "'s hand: " << endl;
                   p->printHand(cout, true);
                   cout << "Size of hand : " << p->getNumCards() << endl;
                   cout << "Enter the index of the card you would like to remove (0 to " << p->getNumCards()-1 << ") : ";
                   cin  >> idx;

                   // Enlever la carte
                   card = p->removeCard(idx);
                  
                   // Valider l'entrée jusqu'à ce que la carte soit enlevée
                   while(card == nullptr){
                      cout << endl << "Card couldn't be removed. Index out of range:  " << idx << endl;
                      cout << "Size of hand : " << p->getNumCards() << endl;
                      cout << "Enter the index of the card you would like to remove (0 to " << p->getNumCards()-1 << ") : ";
                      cin  >> idx;
                      card = p->removeCard(idx);
                    }
                   
                   // Ajouter la carte à la DiscardPile
                   cout << "Card " ;
                   card->print(cout);
                   cout << " added to the discard pile " << endl;
                   *dp+= card;
                }

               // Piger 3 cartes vers le TradeArea
               cout << endl << "Drawing three cards from the deck to the trade area." << endl << endl;
               for(int drw = 0 ;  drw < 3; drw++){
                   *trAr += (deck -> draw());
               }

               // Ajouter des cartes de la Discard Pile tant qu'elles correspondent
               if(dp->size() > 0){
                   while( trAr->legal(dp-> top())){
                        cout << "Card " ;
                        dp->top()->print(cout);
                        cout << " added from the discard pile to the trade area" << endl;
                        *trAr += (dp->pickUp());
                    }
               }

               cout << endl <<  *p << endl;

               cout << endl << "Player " << i+1 << "'s hand: " << endl;
               p->printHand(cout, true);

               cout << endl << "Trade Area : " << *trAr << endl;

               // Pour chaque carte du TradeArea, demander au joueur s'il veut la chainer
               for(Card* card : trAr->getListOfCards()){
                   cout << endl << "Do you want to chain the card ";
                   card -> print(cout);
                   cout << "? (y/n) " << endl;
                   cin >> user_input; 

                   if(user_input[0] == 'y'){
                      p -> playCard(trAr -> trade(card->getName()),  true);

                      cout << endl <<  *p << endl;

                      cout << endl << "Player " << i+1 << "'s hand: " << endl;
                      p->printHand(cout, true);
                      cout << endl << "Trade Area : " << *trAr << endl;

                    }else{
                      
                      cout << endl << "Card left in the trade area." << endl;
                                         
                    }

               }
               
               // Piger 2 cartes et les mettre à la fin de la main
               for(int i = 0; i < 2; i++){
                   if(deck->size() > 0 )
                   cout << endl << "Drawing card from the deck to the back of the player's hand";
                      p -> takeCard(deck->draw());
               }

               cout << endl << "Player " << i+1 << "'s hand: " << endl;
               p->printHand(cout, true);
               cout << endl;

               cout << endl << "Discard Pile : " ;
               dp->print(cout);
               cout << endl;
               
           }
       }
    }

    // Le jeu fini lorsqu'il n'y a plus de cartes dans le paquet
    if(deck->size() == 0){
       cout << endl <<  "Table info:" << endl << endl << *tb << endl;
       cout << "No cards left in the deck" << endl;
       tb->win(winner_name);
       cout << endl << "The winner is : " << winner_name << endl;
    }

    delete tb;
    delete[] pArr;
    
    return 0;
};

