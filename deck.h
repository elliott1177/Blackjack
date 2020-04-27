#ifndef DECK_H_
#define DECK_H_

#include "card_struct.h"

#include <random>
#include <vector>
#include <iostream>

class Deck {
  std::vector<Card> card_deck;
 public:
  Deck();
  Card Hit();
};
#endif  // DECK_H_
