/**
 * @file player.cc
 *
 * @Copyright 2020 Elliott Krohnke, All rights reserved.
 */
#include "Blackjack/dealer.h"

// Overriden so only one card is printed out.
void Dealer::Deal(Card c_one, Card c_two) {
  Clear();
  Hit(c_one);
  Print();
  Hit(c_two);
}

// overrides the Parent class print functions because dealer aren't supposed to
// show all their cards.
void Dealer::Print() {
  if (hand.size() <= 1) {
    std::cout<< "Dealer's face-up card: "<< hand[0].name << std::endl <<
    "Value of that card is: " << hand[0].value;
    // If card is an ace print out 11 alongside 1.
    if (hand[0].value == 1) {
      std::cout<< " or "<< 11;
    }
    std::cout<< std::endl;
    return;
  }
  std::cout<< "Dealer's cards are: ";
  Player::PrintCards();
  std::cout<< "Dealer's ";
  Player::PrintScore();
}
