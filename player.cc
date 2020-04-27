#include "player.h"

// returns 1 if bust
int Player::Hit(Card dealt){
  hand.push_back(dealt);
  std::cout<< "You receive a: " << dealt.name << std::endl;
  int result = Update(dealt);
  return result;
}

int Player::Update(Card dealt){
  // If ace in hand we keep track of both scores.
  if (haveace){
    score1 += dealt.value;
    score2 += dealt.value;
}
  else if (dealt.value == 1 && score2bust == 0 ){
    score2 += score1 + 11;
    score1 += 1;
    haveace = 1;
  }
  else {
  score1 += dealt.value;
}
  // This big bust is a guaranteed loss.
  if(score1 > 21){
    score1 = -1;
    return 1;
  }
  // The hand is busted now with the ace being 11 so we have to cut it out.
  if(score2>21){
    score2 = 0;
    score2bust = 1;
  }
  if(haveace){
    std::cout<< "Your Score is either: " << score1 << " or " << score2 << std::
    endl;
  }
  else{
    std::cout<< "Yout Score is: " << score1 << std::endl;
  }
  return 0;
}

void Player::Clear(){
  score1 = 0;
  score2 = 0;
  score2bust = 0;
  haveace = 0;
  hand.clear();
}

int Player::Score(){
  if (score2>score1 && score2bust == 0) {
    return score2;
  }
  return score1;
}
