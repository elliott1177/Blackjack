/**
 * @file dealer.h
 *
 * @Copyright 2020 Elliott Krohnke, All rights reserved.
 */
#ifndef BLACKJACK_DEALER_H_
#define BLACKJACK_DEALER_H_

#include "Blackjack/player.h"

class Dealer : public Player {
 public:
  Dealer() {}
  // Make sure print statement is in right order.
  void Deal(Card c_one, Card c_two) override;
  // Override the Player print method to print only one card as your only
  // allowed to know one of the dealers cards.
  void Print() override;
};
#endif  // BLACKJACK_DEALER_H_
