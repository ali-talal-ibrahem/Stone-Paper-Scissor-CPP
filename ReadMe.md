# 🪨📄✂️ Stone - Paper - Scissors Game

Welcome to my **first simple program**! This project was developed as the initial milestone in **Dr. Mohammed Abu Hadhoud’s Roadmap**. It is a classic "Rock, Paper, Scissors" game where the player competes against the computer in a series of rounds.

---

## 🚀 Key Features

* **Multi-Round System:** Play from 1 to 10 rounds in a single session.
* **Smart Game Logic:** * Comparison between Player and Computer choices.
    * Instant detection of Winner, Loser, or Draw.
* **Dynamic Visual Feedback:** * **Green Screen:** When the player wins the round.
    * **Red Screen:** When the computer wins (includes a sound alert 🔔).
    * **Yellow Screen:** In case of a draw.
* **Detailed Game Analytics:** A final summary table showing:
    * Total rounds played.
    * Times the player won.
    * Times the computer won.
    * Number of draws.
    * The overall game winner.

---

## 🛠 Technical Implementation

This project demonstrates a solid understanding of fundamental C++ concepts:

| Concept | Description |
| :--- | :--- |
| **Enums** | Used `enGameChoice` and `enWinner` for readable and manageable code. |
| **Structs** | Used `stRoundInfo` and `stGameResults` to pass complex data between functions. |
| **Randomization** | Implemented `rand()` and `srand(time)` for unpredictable computer moves. |
| **UI/UX** | Used `system("color")` and `system("cls")` to create an interactive console experience. |
| **Input Validation** | Ensuring the user enters valid choices and round numbers. |



---

## 🎮 How to Play

1.  **Enter Rounds:** Specify how many rounds you want to play (1-10).
2.  **Make a Choice:** Choose [1] Stone, [2] Paper, or [3] Scissor.
3.  **Round Result:** The screen will change color and show who won the round.
4.  **Final Result:** After all rounds, the "Game Over" screen displays the final champion.
5.  **Replay:** You can choose to start a new game immediately.

---

## 📝 Developer’s Note

> "This was my very first step into the world of software development. It helped me understand the logic of game loops and the importance of organized data structures. It's the beginning of a long and exciting journey."
>
> — **Ali Talal Ibrahem** (December 2, 2025)

---

## 📥 Installation & Running

1.  **Clone/Download** the source code.
2.  **Compile** using any C++ compiler (GCC, Visual Studio, etc.):
    ```bash
    g++ main.cpp -o StonePaperScissor
    ```
3.  **Run** the executable:
    ```bash
    ./StonePaperScissor
    ```

---