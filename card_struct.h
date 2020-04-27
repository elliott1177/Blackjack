#ifndef CARD_STRUCT_H_
#define CARD_STRUCT_H_

#include <string>

struct Card {
  Card(std::string name, int value): name(name), value(value) {}
  std::string name;
  int value;
};
