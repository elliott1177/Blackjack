#include "dealer.h"

// overrides the Parent class print functions because dealer aren't supposed to
// show all their cards.
void Dealer::Print() {
  std::cout<<hand.size()<< "Handsize"<<std::endl;
  if(hand.size()<=2) {
    std::cout<< "Dealer's face-up card: "<< hand[1].name << std::endl <<
    "Value of that card is: " << hand[1].value;
    // If card is an ace print out 11 alongside 1.
    if(hand[1].value == 1){
      std::cout<< "or "<< 11;
    }
    std::cout<< std::endl;
    return;
  }
  std::cout<< "Dealer's cards are: ";
  Player::PrintCards();
  std::cout<< "Dealer's ";
  Player::PrintScore();
}
