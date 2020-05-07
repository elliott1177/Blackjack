/**
 * @card_struct.h
 *
 * @Copyright 2020 Elliott Krohnke, All rights reserved.
 */
#ifndef BLACKJACK_CARD_STRUCT_H_
#define BLACKJACK_CARD_STRUCT_H_

#include <string>

struct Card {
  Card(std::string name, int value): name(name), value(value) {}
  std::string name;
  int value;
};
#endif  // BLACKJACK_CARD_STRUCT_H_
