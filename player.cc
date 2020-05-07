#include "player.h"

// returns 1 if bust
int Player::Hit(Card dealt) {
  hand.push_back(dealt);
  //std::cout<< "You receive a: " << dealt.name << std::endl;
  int result = Update(dealt);
  return result;
}

// Call clear because this is a new round. Take two cards then print out stats.
void Player::Deal(Card c_one, Card c_two){
  Clear();
  Hit(c_one);
  Hit(c_two);
  Print();
}

int Player::Update(Card dealt) {
  // If ace in hand we keep track of both scores.
  if (dealt.value == 1 && score2bust == 0) {
      score2 += score1 + 11;
      score1 += 1;
      haveace = 1;
  } else if (haveace && score2bust == 0) {
    score1 += dealt.value;
    score2 += dealt.value;
  } else {
   score1 += dealt.value;
}
  // This big bust is a guaranteed loss.
  if (score1 > 21) {
    score1 = -1;
    return 1;
  }
  // The hand is busted now with the ace being 11 so we have to cut it out.
  if (score2 > 21) {
    score2 = 0;
    score2bust = 1;
  }
  return 0;
}

void Player::Clear() {
  score1 = 0;
  score2 = 0;
  score2bust = 0;
  haveace = 0;
  hand.clear();
}

int Player::Score() {
  if (score2 > score1 && score2bust == 0) {
    return score2;
  }
  return score1;
}

// This method prints out the names of the cards.
void Player::PrintCards() {
  for (std::vector<Card>::iterator it = hand.begin(); it != hand.end(); ++it) {
    std::cout<< (*it).name << ", ";
  }
  std::cout<< std::endl;
}

// Prints score out according to wether the person has an ace and a non-busted
// second score. Or just one score they need to keep track of.
void Player::PrintScore() {
  if (haveace && score2bust == 0 ) {
    std::cout << " score is either: " << score1 << " or " << score2 << std::
    endl;
  } else if (score1 < 0) {
    std::cout << " hand is busted" << std::endl;
  } else {
    std::cout << " score is: " << score1 << std::endl;
  }
}

// This method prints out the cards that someone has and their score. It is
// virtual because it may be overriden for different types of players.
void Player::Print(){
  std::cout<< "Your cards are: ";
  PrintCards();
  std::cout<< "Your";
  PrintScore();
}
