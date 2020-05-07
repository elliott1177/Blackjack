/**
 * @file player.h
 *
 * @Copyright 2020 Elliott Krohnke, All rights reserved.
 */
#ifndef BLACKJACK_PLAYER_H_
#define BLACKJACK_PLAYER_H_

#include <random>
#include <vector>
#include <iostream>

#include "Blackjack/card_struct.h"

class Player {
  // score1 tracks the score without any aces, or the low score if you have
  // drawn an ace. score2 is the score with the ace being eleven. score2bust
  // is triggered when the hand is busted with ace being 11. After that only
  // play with the aces low score.
  int score1 = 0;
  int score2 = 0;
  int score2bust = 0;
  // add a variable that tracks if score 2 has been triggered.
  int haveace = 0;

 protected:
  std::vector<Card> hand;
  // Prints out cards.
  void PrintCards();
  // Prints out the score.
  void PrintScore();
  // updates the scores. returns 1 if busted.
  int Update(Card dealt);

 public:
  // Clear the player's variables and cards in the hand. Deal two cards and
  // print. Can be overriden.
  virtual void Deal(Card c_one, Card c_two);
  // Returns score
  int Score();
  // Takes a card in as a parameter and adds it to the hand. returns 1 if busted
  int Hit(Card dealt);
  // Resets everything for the next hand.
  void Clear();
  // Prints out card names and score. Formatted for command line game play.
  // Virtual so it can be overriden in classes for other types of players.
  virtual void Print();
};
#endif  // BLACKJACK_PLAYER_H_
