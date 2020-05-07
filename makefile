# Makefile for Blackjack simulation.

# Variables:

CXX = g++
CXXFLAGS = -Wall -g

# Targets:

# ./main to run simulation.
main: main.o deck.o player.o dealer.o
	$(CXX) $(CXXFLAGS) -o main main.o deck.o player.o dealer.o

# Executable file for main.
main.o: main.cpp deck.h player.h dealer.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Executable file for deck.
deck.o: deck.h card_struct.h

# Executable file for player.
player.o: player.h card_struct.h

# Executable file for dealer.
dealer.o: player.h dealer.h card_struct.h
