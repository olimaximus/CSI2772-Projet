#include "Main.h"
#include <fstream>
#include <sstream>


int main(){
    cout << "Projet CSI2772 - Automne 2023" << endl;
    cout << " > Par Maxime Le Sage #300194479"<< endl;
    cout << " > Etienne Boutet #300262462 "<< endl;

    cout << endl;

    string p1_name;
    string p2_name;
    string winner_name;

    // initialize the components
    const int MAX_NUM_PLAYER = 2;
    Player* p1 = nullptr;
    Player* p2 = nullptr;
    // array of players
    Player** pArr =  new Player*[MAX_NUM_PLAYER];
    DiscardPile* dp = new DiscardPile;
    CardFactory* cf = CardFactory::getFactory();
    Deck* deck =  nullptr;
    TradeArea* trAr = new TradeArea;
    Table* tb = new Table(*p1,*p2,*dp, *trAr, *deck, *cf);

    char user_input[2];
    bool savedGame;

    // load game from saved file here
    cout << "Do you want to reload a game?(y/n)" << endl;
    cin >> user_input;

    // search for file; if not found continue
    if(user_input[0] == 'y'){
        
        // reload deck
        tb-> reloadDeck();
        deck = tb ->getDeck();

        tb -> reloadPlayer(1); // get the player 1
        tb -> reloadPlayer(2); // get the player 2

        p1 = tb -> getPlayer(1);
        p2 = tb -> getPlayer(2);

        tb -> reloadDiscardPile();   // reload the discard pile
        dp = tb -> getDiscardPile(); // get the discard pile

        tb -> reloadTradeArea();
        trAr = tb -> getTradeArea(); // get the trade area
        
    } else {
        cout << endl;
        cout << "Enter the name of the first player : ";
        cin  >> p1_name;
        cout << endl;
        cout << "Enter the name of the second player : ";
        cin  >> p2_name;
        cout << endl;

        p1 = new Player(p1_name);
        p2 = new Player(p2_name);

        pArr[0] = p1;
        pArr[1] = p2;

        tb = new Table(*p1,*p2,*dp, *trAr, *deck, *cf);

        deck = tb -> getDeck();        // get the deck
        dp   = tb -> getDiscardPile(); // get the discard pile
        trAr = tb -> getTradeArea();   // get the trade area

        cout << "Initializing  each player with 5 cards. " << endl;
        cout << "Current size of the deck : " << deck -> size() << endl;

        // initialize 5 cards to hand of each player
        for(int player = 0 ; player < MAX_NUM_PLAYER ; player++){
            for(int card = 0; card < 5; card++){
                pArr[player]->takeCard(deck->draw());
            }
        }
    }
  
    // proceed with the game loop
    while(deck->size() != 0){
       cout << "Number of card left in Deck : " << deck->size() << endl;
       cout << endl << ">>>>>>>>>>> Do you want to pause and save the game ? (y/n)" << endl;
       cin >> user_input;
       if(user_input[0] == 'y'){
           // proceed with the logic for pausing the game
           tb -> saveTable();
           cout << "Game saved. Bye." << endl;
           break;
       }
       else{ // proceed with the game
           for(int i = 0; i < MAX_NUM_PLAYER; i++){

               // display table
               cout << endl <<  ">>>> Table information: <<<<" << endl << endl << *tb << endl;

               // proceed with the logic
               cout << endl;
               cout << ">>>> Player " << i+1 << " turn. " << endl;
               cout << endl;

               Player* p = tb -> getPlayer(i);  // get the current player
             
               cout <<  "> Drawing top card from deck..." << endl;
               //  Player draws top card from Deck
               p->takeCard(deck->draw());

               cout << endl << "> Player " << i+1 << " Hand: " << endl;
               p->printHand(cout, true);
               cout << endl;

               // Add bean cards from the TradeArea to chains or discard them
               if(trAr->numCards() > 0) {
                   // Add bean cards from the TradeArea to chains or discard them
                   for( Card* card : trAr->getListOfCards() ){
                        bool cardAdded = false;
                        for( Chain_Base* chain : *(p->getChains()) ){
                            if(card->getName() == chain->getChainType()){
                                cout << "> Card : " ;
                                card->print(cout);
                                cout << " added to the player's " << chain->getChainType() << " chain " << endl;
                                *chain += trAr->trade(card->getName());
                                cardAdded = true;
                            }
                        }

                        // discard the card to the discard pile if the card was not added
                        if(!cardAdded){
                           cout << "> Card : " ;
                           card->print(cout);
                           cout << " added to the discard pile " << endl;
                           *dp+=trAr->trade(card->getName());
                        }
                   }
               }

               cout << endl << *p << endl << "> Playing topmost card from Hand (" << p->getHand()->top()->getName()[0] <<")" << endl;
               // Play topmost card from Hand.
               // If chain is ended, cards for chain are removed and player receives coin(s).
               p->playCard();

               cout << endl <<  *p << endl;

               cout << endl << "> Player " << i+1 << " Hand: " << endl;
               p->printHand(cout, true);
               cout << endl;

               cout << endl << "> Play top most card (" << p->getHand()->top()->getName()[0] <<")? (y/n) " << endl;


               cin >> user_input; 

               if(user_input[0] == 'y'){

                   cout <<  "> Playing topmost card from Hand (" << p->getHand()->top()->getName()[0] <<")" << endl;
                   // Play the now topmost card from Hand. 
                   // If chain is ended, cards for chain are removed and player receives coin(s).
                   p -> playCard();
                   
                   cout << endl <<  *p << endl;

                   cout << endl << "> Player " << i+1 << " Hand: " << endl;
                   p->printHand(cout, true);
                   cout << endl;

               }

               cout << endl << "> Discard card to Discard Pile? (y/n) " << endl;


               cin >> user_input; 

               if (user_input[0] == 'y') {

                   int idx; 
                   Card* card = nullptr;
                   // Show the player's full hand and player selects an arbitrary card
                   cout << endl << "> Player " << i+1 << " Hand: " << endl;
                   p->printHand(cout, true);
                   
                   // p->printHand(cout, false);
                   cout << "Current size of the hand : " << p->getNumCards() << endl;
                   cout << "Enter the index of the card you would like to remove (0 to " << p->getNumCards()-1 << ") : ";
                   cin  >> idx;

                   // Discard the arbitrary card from the player's hand and place it on the discard pile.
                   card = p->removeCard(idx);
                  
                   // enter the proper index
                   while(card == nullptr){
                      cout << endl << "Card not could be removed. Please check the entered index : " << idx << endl;
                      cout << "Current size of the hand : " << p->getNumCards() << endl;
                      cout << "Enter the index of the card you would like to remove (0 to " << p->getNumCards()-1 << ") : ";
                      cin  >> idx;
                      // Discard the arbitrary card from the player's hand and place it on the discard pile.
                      card = p->removeCard(idx);
                    }
                   
                   // add the card to the discard pile
                   cout << "> Card : " ;
                   card->print(cout);
                   cout << " added to the discard pile " << endl;
                   *dp+= card;
                }

               // Draw three cards from the deck and place cards in the trade area
               cout << endl << ">>>> Drawing three cards from the deck to the trade area. " << endl << endl;
               for(int drw = 0 ;  drw < 3; drw++){
                   *trAr += (deck -> draw());
               }

               // cout << "Dp size : " << dp->size() << endl;
               // while top card of discard pile matches an existing card in the trade area
               if(dp->size() > 0){
                   while( trAr->legal(dp-> top())){
                        // draw the top-most card from the discard pile and place it in the trade area
                        cout << "> Card : " ;
                        dp->top()->print(cout);
                        cout << " added from the discard pile to the trade area" << endl;
                        *trAr += (dp->pickUp());
                    }
               }

               cout << endl <<  *p << endl;

               cout << endl << "> Player " << i+1 << " Hand: " << endl;
               p->printHand(cout, true);

               cout << endl << "> Trade Area : " << *trAr << endl;

               for(Card* card : trAr->getListOfCards()){
                   cout << endl << "> Do you want to chain the card [";
                   card -> print(cout);
                   cout << "]? (y/n) " << endl;
                   cin >> user_input; 

                   if(user_input[0] == 'y'){
                      // chain the card.
                      p -> playCard(trAr -> trade(card->getName()),  true);

                      cout << endl <<  *p << endl;

                      cout << endl << "> Player " << i+1 << " Hand: " << endl;
                      p->printHand(cout, true);
                      cout << endl << "> Trade Area : " << *trAr << endl;

                    }else{
                      
                      cout << endl << "> card left in the trade area." << endl;
                                         
                    }

               }
               
               // Draw two cards from Deck and add the cards to the player's hand (at the back).
               for(int i = 0; i < 2; i++){
                   if(deck->size() > 0 )
                   cout << endl << "> Drawing card from the deck to the back of the player's hand";
                      p -> takeCard(deck->draw());
               }

               cout << endl << "> Player " << i+1 << " Hand: " << endl;
               p->printHand(cout, true);
               cout << endl;

               cout << endl << "> Discard Pile all cards : " ;
               dp->print(cout);
               cout << endl;
               
           }
       }
    } // end of while loop with deck

    if(deck->size() == 0){
       // display table
       cout << endl <<  ">>>> Table information: <<<<" << endl << endl << *tb << endl;
       cout << "> No card left in deck. Deck size = " << deck->size() << endl;
       tb->win(winner_name);
       cout << endl << "> The winner is : " << winner_name << endl;
    }
    
    return 0;
};

