# 🎮 Dodge Em (C++ OOP Project)

This project is a console-based implementation of the classic **Dodge Em game**, developed in **C++ using Object-Oriented Programming (OOP)** principles.  

The player controls a car in an arena of roadways, collecting gift boxes while avoiding collisions with opponent cars. The game introduces multiple levels, food mechanics, AI-controlled opponents, and a high-score system.  

---

## 🚗 Driving Rules
- The arena has **roadways**, each divided into four turns (after every one-fourth of the road).  
- **Player Car:**
  - Starts in the middle of the top roadway.  
  - Controlled by **arrow keys** for turns.  
- **Opponent Car(s):**
  - Spawn randomly at turns, always at least one turn away from the player’s car.  
  - Opponent AI decides whether to turn based on if it brings them closer to the player’s roadway.  

---

## 🏆 Game Levels
1. **Level 1**  
   - Opponent car is less active.  
   - Cannot take **top or bottom turns**.  
   - Player can take any turn.  

2. **Level 2**  
   - Opponent car is in **active mode** and can take any turn.  

3. **Level 3**  
   - Opponent car is in active mode with **increased speed**.  

4. **Level 4**  
   - Two opponent cars chase the player.  
   - Cars start from **different positions**.  
   - On completion → Display message **“You won!”** and end the game.  

---

## 🍎 Types of Food
1. **Red Rectangle** → +10 points.  
2. **Green Circle** → +20 points & +1 extra life.  
3. **Orange Hexagon** → +10 points & **1.5× speed boost** for 10 seconds.  
4. **White Triangle** → Makes opponents disappear for 10 seconds.  

---

## ⭐ Scoring & High Scores
- Collecting all **gift boxes** gives **+100 points** and starts a new level.  
- High scores are stored in a file `highscores.txt`.  
- On game start:
  - Top 5 scores are read into an array.  
  - If current score qualifies → lowest score is removed and file updated.  

---

## 📋 Menu System
### Main Menu
1. Start a new game  
2. See high-scores  
3. Help  
4. Exit  

### Pause Menu (when player presses `P`)
1. Start a new game  
2. See high-scores  
3. Help  
4. Exit  
5. Continue  

---

## ⚙️ Implementation Details
- **Language:** C++  
- **Paradigm:** Object-Oriented Programming (OOP)  
- **Key OOP Concepts Used:**
  - **Classes & Objects** → Car, OpponentCar, Food, Game, Menu  
  - **Inheritance & Polymorphism** → Different food types and car behaviors  
  - **Encapsulation** → Game logic, score tracking, file handling  
  - **File Handling** → Persistent high-score storage (`highscores.txt`)  
  - **Game Loop** → Handles user input, AI logic, collisions, and rendering  

---

## ▶️ How to Run
### Compile
```bash
g++ main.cpp -o dodgeem
