#include "deck.h"
#include "card_struct.h"
#include "player.h"

#include <iostream>

class Deck;

int main(int argc, char**argv) {
  Deck game_deck;
  std::cout<< "Welcome to the casino!" << std::endl;
  std::cout<< "Your cards are being dealt now" << std::endl;
  Player player1;
  Player dealer;
  // This integer will keep track of the game being played.
  int playing = 1;
  while (playing) {
    dealer.Clear();
    player1.Clear();
    // Starting hands.
    std::cout << "Dealers Cards: " << std::endl;
    dealer.Hit(game_deck.Hit());
    dealer.Hit(game_deck.Hit());
    std::cout << "Your cards: " << std::endl;
    player1.Hit(game_deck.Hit());
    player1.Hit(game_deck.Hit());
    int hit = 1;
    while(hit){
      std::cout<< "Type 1 for hit or 0 for hold" << std::endl;
      std::cin>> hit;
      if (hit == 0) {
        break;
      }
      int result = player1.Hit(game_deck.Hit());
      // break the loop if player busted.
      if (result == 1){
        hit = 0;
      }
    }
    std::cout << "Dealer takes more cards"<< std::endl;
    dealer.Hit(game_deck.Hit());
    dealer.Hit(game_deck.Hit());
    if (player1.Score() > dealer.Score()) {
      std::cout << "You win" << std::endl;
    }
    else{
      std::cout << "You lose" << std::endl;
    }
    std::cout<< "Type 1 to play another game"<< std::endl;
    std::cin >> playing;
  }
}
