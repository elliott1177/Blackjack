/**
 * @file deck.h
 *
 * @Copyright 2020 Elliott Krohnke, All rights reserved.
 */
#ifndef BLACKJACK_DECK_H_
#define BLACKJACK_DECK_H_

#include <random>
#include <vector>
#include <iostream>

#include "card_struct.h"

class Deck {
  std::vector<Card> card_deck;
 public:
  Deck();
  Card Hit();
};
#endif  // BLACKJACK_DECK_H_
