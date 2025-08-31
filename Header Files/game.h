#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include "car.h"
#include "arena.h"
#include "food.h"

using namespace sf;
using namespace std;

const char title[] = "Dodge 'Em - OOP Project";

// Group Members:
// 1. 22i-0928 Ibrahim Azhar 
// 2. 22i-1177 Usman Haroon
// OOP Section-C

class Game {
private:
    // For Game 
    RenderWindow window;
    PlayerCar playerCar;
    OpponentCar opponentCar;
    Arena arena;
    bool levelCompleted;
    bool enemiesVisible;
    Clock enemyVisibilityTimer;
    // For Food Object
    static const int MAX_FOOD_ITEMS = 70;
    Food* foodItems[MAX_FOOD_ITEMS];
    // For Level Logic
    int currentLevel;
    int totalLevels;
    bool isLevelCompleted;
    // For Display Purposes
    Text scoreText;
    Text livesText;
    Font DisplayFont;
    int score;
    int playerLives;
    // For Pausing and Un-Pausing
    bool isPaused;
    Text pauseText;
    // For Game Over
    Texture gameOverTexture;
    Sprite gameOverSprite;
    bool isGameOver;
    Music GameOverSound;

    void updateDisplayText() {
        scoreText.setString("P1 Score: " + to_string(score));
        livesText.setString("P1 Lives: " + to_string(playerLives));
    }

    void initializeDisplayText() {
        DisplayFont.loadFromFile("C:/Users/Ibrah/Desktop/Lab Work and Practice/DodgeEmProject/oopProject1/fonts/INVASION2000.TTF");
        scoreText.setFont(DisplayFont);
        scoreText.setCharacterSize(24);
        scoreText.setFillColor(Color::Red);
        scoreText.setPosition(200.f, 50.f);
        livesText.setFont(DisplayFont);
        livesText.setCharacterSize(24);
        livesText.setFillColor(Color::Red);
        livesText.setPosition(200.f, 30.f);
        pauseText.setFont(DisplayFont);
        pauseText.setCharacterSize(30);
        pauseText.setFillColor(Color::White);
        pauseText.setString("Press P to Un-Pause The Game");
        pauseText.setPosition(165.f, 275.f);
    }

    void handleCollision() {
        if (opponentCar.isActive() && playerCar.getBounds().intersects(opponentCar.getBounds())) {
            playerCar.resetPosition();
            opponentCar.resetPosition();
            playerLives--;
            if (playerLives <= 0) {
                GameOverSound.play();
                isGameOver = true;
            }
        }
    }

    void spawnFood() {
        foodItems[0] = new RedFood(Vector2f(215.f, 150.f));
        foodItems[1] = new RedFood(Vector2f(215.f, 200.f));
        foodItems[2] = new RedFood(Vector2f(215.f, 250.f));
        foodItems[3] = new OrangeHexagonFood(Vector2f(210.f, 110.f));
        foodItems[4] = new OrangeHexagonFood(Vector2f(575.f, 110.f));
        foodItems[5] = new GreenFood(Vector2f(218.f, 350.f));
        foodItems[6] = new WhiteTriangularFood(Vector2f(220.f, 470.f));
        foodItems[7] = new RedFood(Vector2f(255.f, 110.f));
        foodItems[8] = new RedFood(Vector2f(295.f, 110.f));
        foodItems[9] = new RedFood(Vector2f(335.f, 110.f));
        foodItems[10] = new RedFood(Vector2f(455.f, 110.f));
        foodItems[11] = new RedFood(Vector2f(495.f, 110.f));
        foodItems[12] = new RedFood(Vector2f(535.f, 110.f));
        foodItems[13] = new RedFood(Vector2f(580.f, 150.f));
        foodItems[14] = new RedFood(Vector2f(580.f, 200.f));
        foodItems[15] = new RedFood(Vector2f(580.f, 250.f));
        foodItems[16] = new RedFood(Vector2f(580.f, 330.f));
        foodItems[17] = new RedFood(Vector2f(580.f, 380.f));
        foodItems[18] = new RedFood(Vector2f(580.f, 430.f));
        foodItems[19] = new RedFood(Vector2f(214.f, 383.f));
        foodItems[20] = new RedFood(Vector2f(214.f, 428.f));
        foodItems[21] = new RedFood(Vector2f(270.f, 160.f));
        foodItems[22] = new RedFood(Vector2f(270.f, 200.f));
        foodItems[23] = new RedFood(Vector2f(270.f, 240.f));
        foodItems[24] = new RedFood(Vector2f(270.f, 340.f));
        foodItems[25] = new RedFood(Vector2f(270.f, 380.f));
        foodItems[26] = new RedFood(Vector2f(270.f, 420.f));
        foodItems[27] = new RedFood(Vector2f(270.f, 470.f));
        foodItems[28] = new RedFood(Vector2f(310.f, 470.f));
        foodItems[29] = new RedFood(Vector2f(350.f, 470.f));
        foodItems[30] = new OrangeHexagonFood(Vector2f(570.f, 470.f));
        foodItems[31] = new RedFood(Vector2f(450.f, 470.f));
        foodItems[32] = new RedFood(Vector2f(490.f, 470.f));
        foodItems[33] = new RedFood(Vector2f(530.f, 470.f));
        foodItems[34] = new RedFood(Vector2f(525.f, 160.f));
        foodItems[35] = new RedFood(Vector2f(525.f, 200.f));
        foodItems[36] = new RedFood(Vector2f(525.f, 240.f));
        foodItems[37] = new RedFood(Vector2f(525.f, 340.f));
        foodItems[38] = new RedFood(Vector2f(525.f, 380.f));
        foodItems[39] = new RedFood(Vector2f(525.f, 420.f));
        foodItems[40] = new RedFood(Vector2f(300.f, 160.f));
        foodItems[41] = new RedFood(Vector2f(330.f, 160.f));
        foodItems[42] = new RedFood(Vector2f(360.f, 160.f));
        foodItems[43] = new RedFood(Vector2f(300.f, 420.f));
        foodItems[44] = new RedFood(Vector2f(330.f, 420.f));
        foodItems[45] = new RedFood(Vector2f(360.f, 420.f));
        foodItems[46] = new RedFood(Vector2f(430.f, 420.f));
        foodItems[47] = new RedFood(Vector2f(460.f, 420.f));
        foodItems[48] = new RedFood(Vector2f(490.f, 420.f));
        foodItems[46] = new RedFood(Vector2f(430.f, 420.f));
        foodItems[47] = new RedFood(Vector2f(460.f, 420.f));
        foodItems[48] = new RedFood(Vector2f(490.f, 420.f));
        foodItems[49] = new RedFood(Vector2f(430.f, 160.f));
        foodItems[50] = new RedFood(Vector2f(460.f, 160.f));
        foodItems[51] = new RedFood(Vector2f(490.f, 160.f));
        foodItems[52] = new GreenFood(Vector2f(325.f, 225.f));
        foodItems[53] = new OrangeHexagonFood(Vector2f(320.f, 360.f));
        foodItems[54] = new WhiteTriangularFood(Vector2f(463.f, 215.f));
        foodItems[55] = new RedFood(Vector2f(322.f, 250.f));
        foodItems[56] = new RedFood(Vector2f(350.f, 216.f));
        foodItems[57] = new RedFood(Vector2f(322.f, 330.f));
        foodItems[58] = new RedFood(Vector2f(350.f, 360.f));
        foodItems[59] = new RedFood(Vector2f(440.f, 360.f));
        foodItems[60] = new RedFood(Vector2f(470.f, 360.f));
        foodItems[61] = new RedFood(Vector2f(470.f, 330.f));
        foodItems[62] = new RedFood(Vector2f(470.f, 250.f));
        foodItems[63] = new RedFood(Vector2f(440.f, 216.f));

        for (int i = 64; i < MAX_FOOD_ITEMS; ++i) {
            foodItems[i] = nullptr;
        } // If A Food Array Index Is Not In Use, Keep It Null
    }

    void checkFoodCollection() {
        for (int i = 0; i < MAX_FOOD_ITEMS; ++i) {
            if (foodItems[i] != nullptr) {
                int pointsCollected = foodItems[i]->collectIfCollided(playerCar.getBounds());
                if (pointsCollected > 0) {
                    score += pointsCollected;

                    //--------File Handling--------//
                    fstream F1;

                    // Make Sure Data Is Not Over-Written
                    F1.open("highscores.txt", ios::app);
                    F1 << "Total Score Is The Last One \n";

                    if (F1.is_open()) {
                        F1 << score << " ";
                        F1 << "----------------------";
                        F1.close();
                    }

                    updateDisplayText();

                    if (dynamic_cast<OrangeHexagonFood*>(foodItems[i])) {
                        playerCar.activateSpeedBoost();
                    } // Speed Boost Check For Orange Hexagon Food

                    if (dynamic_cast<GreenFood*>(foodItems[i])) {
                        playerLives++;
                    } // Lives Increment For Green Food

                    if (dynamic_cast<WhiteTriangularFood*>(foodItems[i])) {
                        enemiesVisible = false; // Make Enemies Disappear
                        opponentCar.setActive(false); // Deactivate The Opponent Car
                        enemyVisibilityTimer.restart(); // Start The Timer
                    }

                    delete foodItems[i];
                    foodItems[i] = nullptr;
                }
            }
        }
    }

public:
    // Constructor
    Game() : playerCar("C:\\Users\\Ibrah\\Desktop\\Lab Work and Practice\\DodgeEmProject\\oopProject1\\img\\PixelCar.png", 400.f, 400.f),
        opponentCar("C:\\Users\\Ibrah\\Desktop\\Lab Work and Practice\\DodgeEmProject\\oopProject1\\img\\EnemyCar.png", 215.f, 500.f),
        arena(100.f, 10.f, 45.f),
        window(VideoMode(800, 600), title),
        score(0) {

        window.setFramerateLimit(60);
        playerLives = 3;
        spawnFood(); // Initialize Food Items
        initializeDisplayText(); // Display All Texts Required
        updateDisplayText();

        isGameOver = false;
        isPaused = false;
        enemiesVisible = true;
        gameOverSprite.setScale(0.6f, 0.6f);

        if (gameOverTexture.loadFromFile("C:\\Users\\Ibrah\\Desktop\\Lab Work and Practice\\DodgeEmProject\\oopProject1\\img\\Dodge Em Game Over.png")) {
            gameOverSprite.setTexture(gameOverTexture);
            gameOverSprite.setPosition(200.f, 200.f);
        }

        GameOverSound.openFromFile("C:\\Users\\Ibrah\\Desktop\\Lab Work and Practice\\DodgeEmProject\\oopProject1\\sound\\GameOver.wav");
    }

    ~Game() {
        for (int i = 0; i < MAX_FOOD_ITEMS; ++i) {
            if (foodItems[i] != nullptr) {
                delete foodItems[i]; // Free Memory
                foodItems[i] = nullptr; // Set To Null To Avoid Future Access Violations
            }
        }
    }

    void startGame() {
        currentLevel = 1;

        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    window.close();
                }

                // Handle The 'P' Key Press For Pausing And Resuming
                if (event.type == Event::KeyPressed && event.key.code == Keyboard::P) {
                    isPaused = !isPaused; // Toggle Pause State
                }
            }

            if (isGameOver) {
                // If The Game Is Over, Press The Escape Key To Exit
                if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                    window.close();
                }
            }

            if (!isPaused) {
                update();
            } // Only Update When The Game Is Not Paused

            render();
        }
    }

private:
    // Update Function For Game. Handles All The Features That Are Constantly Updating
    void update() {
        playerCar.update(arena);
        opponentCar.update(arena);
        playerCar.updateSpeedBoost();
        checkFoodCollection();
        handleCollision();
        updateDisplayText();

        // Check For Collision Between Player And Opponent
        if (playerCar.getBounds().intersects(opponentCar.getBounds())) {
            playerCar.handleCollisionWithOpponent();
            opponentCar.resetPosition();
        }

        if (!enemiesVisible && enemyVisibilityTimer.getElapsedTime().asSeconds() > 10) {
            enemiesVisible = true; // Make Enemies Visible Again After 10 Seconds
            opponentCar.setActive(true); // Reactivate The Opponent Car
        }

        if (enemiesVisible) {
            opponentCar.update(arena); // Update Opponent Only If Visible
        }
    }

    void render() {
        window.clear();

        if (isGameOver) {
            // Position The Game Over Sprite At The Center Of The Window
            gameOverSprite.setPosition((window.getSize().x - gameOverSprite.getGlobalBounds().width) / 2.0f,
                (window.getSize().y - gameOverSprite.getGlobalBounds().height) / 2.0f);

            // Draw Only The Game Over Sprite
            window.draw(gameOverSprite);
        }
        else {
            // Draw The Game Elements Only If The Game Is Not Over
            arena.draw(window);
            playerCar.draw(window);

            for (int i = 0; i < MAX_FOOD_ITEMS; ++i) {
                if (foodItems[i] != nullptr) {
                    foodItems[i]->draw(window);
                }
            }

            if (isPaused) {
                window.draw(pauseText);
            }

            if (enemiesVisible) {
                opponentCar.draw(window); // Draw Opponent Only If Visible
            }

            window.draw(scoreText);
            window.draw(livesText);
        }

        window.display();
    }

};

#endif