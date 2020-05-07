/**
 * @file deck.cc
 *
 * @Copyright 2020 Elliott Krohnke, All rights reserved.
 */

#include <string>

#include "Blackjack/deck.h"

// Class constructor that fills the card_deck vector with 52 card_struct objects
// representing a Standard 52-Card Deck. It uses two loops to initialize the
// card deck to contain every card possible in 52 card deck. It iterates through
// every suit and rank and creates cards by naming them a string constructed by
// the "rank of suit" for example: "Ace of spades". The value is the rank plus
// 1. I will deal with the double value of Ace later in the player class.
Deck::Deck() {
  // Arrays of all the suits and ranks in a deck of cards.
  std::string suit[] = {"spades", "clubs", "diamonds", "hearts"};
  std::string rank[] = {"Ace", "Two", "Three", "Four", "Five", "Six",
  "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
  for (int su = 0; su < 4; su++) {
    for (int ra = 0; ra < 13 ; ra++) {
      if (ra > 9) {
        card_deck.push_back(Card((rank[ra] + " of " + suit[su]), 10));
      } else {
        card_deck.push_back(Card((rank[ra] + " of " + suit[su]), ra + 1));
    }
    }
  }
}

// Returns a random card from the deck. Uses a random number generator from the
// random library. It pick a random number based on how many cards are left in
// deck.
Card Deck::Hit() {
  int length = card_deck.size();
  // Random number generator initialized with a random device. Uses the Mersenne
  // twister to generate random numbers (mt19937). Distribution is the range.
  std::random_device rand_dev;
  std::mt19937 rng(rand_dev());
  std::uniform_int_distribution<std::mt19937::result_type> distribution
  (0, length);
  int card_number = distribution(rng);
  Card deal_card = card_deck[card_number];
  card_deck.erase(card_deck.begin() + card_number);
  return deal_card;
}
