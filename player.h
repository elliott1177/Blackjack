#ifndef PLAYER_H_
#define PLAYER_H_

#include "card_struct.h"

#include <random>
#include <vector>
#include <iostream>

class Player {
  std::vector<Card> hand;
  // score1 tracks the score without any aces, or the low score if you have
  // drawn an ace. score2 is the score with the ace being eleven. score2bust
  // is triggered when the hand is busted with ace being 11. After that only
  // play with the aces low score.
  int score1 = 0;
  int score2 = 0;
  int score2bust = 0;
  // add a variable that tracks if score 2 has been triggered.
  int haveace = 0;
 public:
  // Returns score
  int Score();
  // Takes a card in as a parameter and adds it to the hand. returns 1 if busted
  int Hit(Card dealt);
  // updates the scores. returns 1 if busted.
  int Update(Card dealt);
  // Resets everything for the next hand.
  void Clear();
};
#endif  // PLAYER_H_
