#ifndef DEALER_H_
#define DEALER_H_
#include "player.h"

class Dealer : public Player {
 public:
  Dealer() {}
  // Make sure print statement is in right order.
  void Deal(Card c_one, Card c_two) override;
  // Override the Player print method to print only one card as your only
  // allowed to know one of the dealers cards.
  void Print() override;
};
#endif  // DEALER_H_
