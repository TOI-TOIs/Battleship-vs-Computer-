# Battleship-vs-Computer

In the 1st Semester in college we were assinged to make the game Battleship in the coding launguge C.

The game features a complete ship placement phase with boundary and collision validations, and pits the player against an algorithmic bot opponent.

## 🧠 Features
*   **Smart Bot Opponent:** The computer uses a random hunting strategy, but switches to a "smart targeting" mode once it registers a hit.
*   **Input Validation:** Robust checks for out-of-bounds coordinates, overlapping ships, and invalid inputs during the placement and shooting phases.

## 💻 Tech Stack
*   **Language:** C
*   **Libraries used:** `<stdio.h>`, `<stdlib.h>`, `<time.h>`, `<string.h>`

## 🚀 How to Compile and Run

To play the game on a Linux/Unix terminal or Windows command prompt, use the following GCC commands:

```bash
# Compile the code
gcc main.c -o battleship

# Run the executable
./battleship
