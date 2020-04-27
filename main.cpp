#include "deck.h"
#include "card_struct.h"

class Deck;

int main(int argc, char**argv) {
  Deck game_deck;
  for(int i = 0; i<52; i++)
    game_deck.Hit();
}
