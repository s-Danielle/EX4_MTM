# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Werror -pedantic-errors

# Target executable
TARGET = program

# Source files
SRCS = main.cpp Mtmchkin.cpp StringUtils.cpp \
        Players/Healer.cpp Players/Ninja.cpp \
        Players/Player.cpp Players/Warrior.cpp \
        Cards/Barfight.cpp Cards/Battle.cpp Cards/Card.cpp \
        Cards/Dragon.cpp Cards/Gremlin.cpp Cards/Mana.cpp \
        Cards/Merchant.cpp Cards/Treasure.cpp Cards/Well.cpp Cards/Witch.cpp \
        Leaderboard.cpp utilities.cpp Exception.cpp

# Object files
OBJS = main.o Mtmchkin.o StringUtils.o \
        Players/Healer.o Players/Ninja.o \
        Players/Player.o Players/Warrior.o \
        Cards/Barfight.o Cards/Battle.o Cards/Card.o \
        Cards/Dragon.o Cards/Gremlin.o Cards/Mana.o \
        Cards/Merchant.o Cards/Treasure.o Cards/Well.o Cards/Witch.o \
        Leaderboard.o utilities.o Exception.o

# Default rule
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Rule to compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Additional dependencies
Mtmchkin.o: Mtmchkin.h Cards/Card.h Players/Player.h \
	Leaderboard.h Exception.h utilities.h StringUtils.h
StringUtils.o: StringUtils.h
main.o: main.cpp Mtmchkin.h Cards/Card.h Players/Player.h \
	Leaderboard.h Exception.h
test.o: test.cpp Players/Player.h Cards/Card.h Mtmchkin.h \
	Leaderboard.h Cards/Witch.h Cards/Battle.h Cards/Card.h \
	Cards/Barfight.h Cards/Dragon.h Cards/Mana.h Cards/Gremlin.h \
	Cards/Merchant.h Cards/Well.h Cards/Treasure.h Players/Ninja.h \
	Players/Player.h Players/Healer.h Players/Warrior.h Exception.h
utilities.o: utilities.cpp utilities.h Exception.h Players/Player.h
Exception.o: Exception.h
Leaderboard.o: Leaderboard.cpp Leaderboard.h Players/Player.h utilities.h \
	Exception.h
Healer.o: Players/Healer.cpp Players/Healer.h Players/Player.h \
	utilities.h Exception.h Players/Player.h
Ninja.o: Players/Ninja.cpp Players/Ninja.h Players/Player.h \
	utilities.h Exception.h Players/Player.h
Player.o: Players/Player.cpp Players/Player.h utilities.h \
	Exception.h Players/Ninja.h Players/Warrior.h Players/Healer.h \
	Exception.h Players/Player.h
Warrior.o: Players/Warrior.cpp Players/Warrior.h Players/Player.h \
	utilities.h Exception.h Players/Player.h
Barfight.o: Cards/Barfight.cpp Cards/Barfight.h Cards/Card.h \
	Players/Player.h utilities.h Exception.h Players/Player.h
Battle.o: Cards/Battle.cpp Cards/Battle.h Cards/Card.h \
	Players/Player.h utilities.h Exception.h Players/Player.h
Card.o: Cards/Card.cpp Cards/Card.h Players/Player.h \
	utilities.h Exception.h Players/Player.h Cards/Witch.h \
	Cards/Battle.h Cards/Barfight.h Cards/Dragon.h Cards/Mana.h \
	Cards/Gremlin.h Cards/Merchant.h Cards/Well.h Cards/Treasure.h
Dragon.o: Cards/Dragon.cpp Cards/Dragon.h Cards/Battle.h Cards/Card.h \
	Players/Player.h utilities.h Exception.h Players/Player.h
Gremlin.o: Cards/Gremlin.cpp Cards/Gremlin.h Cards/Battle.h Cards/Card.h \
	Players/Player.h
Mana.o: Cards/Mana.cpp Cards/Mana.h Cards/Card.h Players/Player.h \
	utilities.h Exception.h Players/Player.h
Merchant.o: Cards/Merchant.cpp Cards/Merchant.h Cards/Card.h \
	Players/Player.h utilities.h Exception.h Players/Player.h
Treasure.o: Cards/Treasure.cpp Cards/Treasure.h Cards/Card.h \
	Players/Player.h utilities.h Exception.h Players/Player.h
Well.o: Cards/Well.cpp Cards/Well.h Cards/Card.h Players/Player.h \
	utilities.h Exception.h Players/Player.h
Witch.o: Cards/Witch.cpp Cards/Witch.h Cards/Battle.h Cards/Card.h \
	Players/Player.h

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)
