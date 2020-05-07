/**
 * @file main.cpp
 *
 * @Copyright 2020 Elliott Krohnke, All rights reserved.
 */
#include <iostream>

#include "deck.h"
#include "card_struct.h"
#include "dealer.h"
#include "player.h"

class Deck;

int main(int argc, char**argv) {
  std::cout<< "Welcome to the casino!" << std::endl;
  std::cout<< "Your cards are being dealt now" << std::endl;
  std::vector<Player *> PlayerVector;
  // Changed the players into a vector. Since pointers are being used we can
  // make use of run time binding and allow the overriden dealer methods to be
  // called.
  Player * player1 = new Player();
  Player * dealer = new Dealer();
  PlayerVector.push_back(dealer);
  PlayerVector.push_back(player1);
  // This integer will keep track of the game being played.
  int playing = 1;
  while (playing) {
    Deck game_deck;
    // This loop is called at the start of every round and clears, deals and
    // prints out the starting hands of the game before entering the while loop
    // that controls how many hits the player wants.
    for (std::vector<Player *>::iterator it = PlayerVector.begin();
      it != PlayerVector.end(); ++it) {
      // I could merge clear and the double hit and print into a deal method.
      (*it)->Deal(game_deck.Hit(), game_deck.Hit());
    }
    // This int is 1 if the player busts.
    int result = 0;
    int hit = 1;
    // This loop allows the player to choose how many hits they want.
    while (hit) {
      std::cout<< "Type 1 for hit or 0 for hold" << std::endl;
      std::cin>> hit;
      std::cout<< std::endl << std::endl;
      if (hit == 0) {
        break;
      }
      result = PlayerVector[1]->Hit(game_deck.Hit());
      PlayerVector[1]->Print();
      // break the loop if player busted.
      if (result == 1) {
        hit = 0;
      }
    }
    // outputs lines to make game easier to read.
    std::cout << std::endl << std::endl;
    // Keep track of the dealers score.
    int score = PlayerVector[0]->Score();
    // Dealer takes more cards if player did not bust and their score is < 17.
    if (result != 1 && score < 17) {
      std::cout << "Dealer takes more cards"<< std::endl;
      // While the dealer's score is less than 17 and not busted, draws cards.
      while (score < 17 && score != -1) {
        PlayerVector[0]->Hit(game_deck.Hit());
        PlayerVector[0]->Print();
        score = PlayerVector[0]->Score();
      }
    } else {  // If not taking cards print out score.
        PlayerVector[0]->Print();
    }
    if (PlayerVector[1]->Score() > PlayerVector[0]->Score()) {
      std::cout << "You win" << std::endl;
    } else {
      std::cout << "You lose" << std::endl;
    }
    std::cout<< "Type 1 to play another game" << std::endl;
    std::cin >> playing;
    std::cout<< std::endl << std::endl << std::endl << std::endl;
  }
}
