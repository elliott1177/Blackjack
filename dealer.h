#ifndef PLAYER_H_
#define PLAYER_H_
#include "player.h"

class Dealer : public Player {
 public:
  // Override the Player print method to print only one card as your only
  // allowed to know one of the dealers cards.
  void Print() override;
};
#endif  // PLAYER_H_
