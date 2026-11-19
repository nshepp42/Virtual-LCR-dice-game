# Left Center Right Dice Game

A C++ console game for 3 to 10 players, written for CS 150 Project 1. Players share one terminal and start with three chips each.

## Build and run

From the project folder, use one of the following commands.

**Windows with Visual Studio 2022** (x64 Native Tools Command Prompt)

```bat
cl /nologo /EHsc /std:c++17 CS150p1njs.cpp diceF.cpp /Fe:lcr.exe
.\lcr.exe
```

**Linux with GCC**

```sh
g++ -std=c++17 -pthread CS150p1njs.cpp diceF.cpp -o lcr
./lcr
```

## How to play

Enter the number of players, then type `Y` and press Enter when prompted to roll. On each turn, the active player rolls one die per chip, up to three dice. A player with zero chips can receive chips from a neighbor on a later turn.

| Roll | What happens |
| --- | --- |
| `L` | Pass one chip to the player on the left. |
| `C` | Put one chip in the center pot. |
| `R` | Pass one chip to the player on the right. |
| `O` | Keep the chip. |

The last player with chips wins the center pot.

## Source files

- `CS150p1njs.cpp` handles setup, turns, and the win condition.
- `diceF.cpp` handles chip transfers, roll prompts, and score display.
- `diceF.h` declares the `Dicef` class.
