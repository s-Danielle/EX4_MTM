# MTMCHKIN - Full Edition

## Overview
**MTMCHKIN** is a multiplayer card-based game implemented in C++ for up to 6 players. Players aim to win battles, level up, and reach level 10 while managing resources like health and coins. The game features dynamic interactions with cards and a leaderboard ranking system. This implementation is designed with modularity, clean code principles, and extensibility in mind.

## Features
### Player Types
- **Ninja**:
  - Doubles the coins earned from rewards.
  - Can evade penalties from specific cards (e.g., Well).
- **Healer**:
  - Receives double the health points restored by healing cards.
  - Gains unique benefits from Mana cards.
- **Warrior**:
  - Attack power is enhanced, calculated as `level^2 + force`.
  - Resilient in Barfight situations.

### Card Types
- **Battle Cards**:
  - **Gremlin**: Moderate difficulty, with moderate rewards and penalties.
  - **Witch**: Higher difficulty, with additional penalties like force reduction.
  - **Dragon**: Extremely challenging, offering high rewards but can eliminate a player upon loss.
- **Merchant**:
  - Allows players to purchase health or force upgrades for coins.
- **Treasure**:
  - Provides players with a reward of 10 coins.
- **Well**:
  - Penalizes most players by reducing health, except for Ninjas who evade penalties.
- **Barfight**:
  - Penalizes most players by reducing health, except for Warriors who are immune.
- **Mana**:
  - Grants healing benefits exclusively to Healers, who gain twice the standard amount.

### Leaderboard
- Players are ranked dynamically:
  - **First**: Players who reach level 10.
  - **Middle**: Players still in the game, sorted by turn order.
  - **Last**: Players who lose all health points, sorted by elimination order.

---

## File Structure
### Core Files
- **`Mtmchkin.h` / `Mtmchkin.cpp`**:
  - Core class managing the game logic, including rounds, card deck, and players.
- **`Player.h` / `Player.cpp`**:
  - Handles player attributes, behaviors, and unique class interactions (e.g., Ninja, Healer, Warrior).
- **`Card.h` / `Card.cpp`**:
  - Defines card behaviors and specific card types (e.g., Dragon, Mana, Merchant).

### Supporting Files
- **`utilities.h`**:
  - Contains helper functions for printing game messages and handling errors.
- **`Exception.h`**:
  - Defines custom exceptions (e.g., invalid deck file or format).
- **`test.cpp`**:
  - Test suite for validating game mechanics and functionality.
- **`main.cpp`**:
  - Entry point for initializing and running the game.

---

## How to Build
1. Clone the repository:
   ```bash
   git clone <repository_url>
   cd mtmchkin
   ```
2. Build the project:
   ```bash
   g++ --std=c++11 -o mtmchkin -Wall -pedantic-errors -Werror -DNDEBUG *.cpp Cards/*.cpp Players/*.cpp
   ```

---

## How to Run
1. Run the program:
   ```bash
   ./mtmchkin
   ```
2. Provide the path to a valid deck file and initialize players interactively.

---

## Example Usage
1. **Deck File** (`deck.txt`):
   ```
   Mana
   Gremlin
   Witch
   Barfight
   Dragon
   Treasure
   Merchant
   ```
2. **Input Example**:
   - Number of players: `3`
   - Player details:
     ```
     Alice Ninja
     Bob Healer
     Charlie Warrior
     ```

3. **Sample Gameplay**:
   - Players take turns drawing and resolving cards.
   - The leaderboard updates dynamically based on progress.

---

## Good Practices
- **Memory Management**:
  - Ensure no memory leaks by using smart pointers or freeing allocated memory.
- **Modular Design**:
  - Each card and player type is independent, making the system extensible.
- **Error Handling**:
  - Properly handle invalid deck files, inputs, and edge cases.

---

## Conclusion
MTMCHKIN is a fun and engaging multiplayer game, designed to showcase advanced object-oriented programming techniques and clean code principles. Its modular design makes it easy to extend with new card types or player behaviors.
