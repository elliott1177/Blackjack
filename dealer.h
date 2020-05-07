#ifndef DEALER_H_
#define DEALER_H_
#include "player.h"

class Dealer : public Player {
 public:
  Dealer() {}
  // Override the Player print method to print only one card as your only
  // allowed to know one of the dealers cards.
  void Print() override;
};
#endif  // DEALER_H_
