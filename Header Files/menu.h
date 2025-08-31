#ifndef MENU_H
#define MENU_H

#include "game.h"
#include <SFML/Graphics.hpp>

using namespace sf;

// Group Members:
// 1. 22i-0928 Ibrahim Azhar 
// 2. 22i-1177 Usman Haroon
// OOP Section-C

class Menu {
private:
    Music backgroundMusic;
    RenderWindow window;
    Text options[4];
    bool displayHelp;
    Text HelpText;
    Font font;
    Texture backgroundTexture;
    Sprite backgroundSprite;
    int selectedOption;
    int maxOptions = 4;

public:
    Menu() : selectedOption(0), window(VideoMode(800, 600), "Dodge 'Em Menu"),
             displayHelp(false) {

        backgroundTexture.loadFromFile("C:/Users/Ibrah/Desktop/Lab Work and Practice/DodgeEmProject/oopProject1/img/BackGround2.png");
        backgroundSprite.setTexture(backgroundTexture);
        backgroundSprite.setScale(2.5f, 2.35f);

        font.loadFromFile("C:/Users/Ibrah/Desktop/Lab Work and Practice/DodgeEmProject/oopProject1/fonts/INVASION2000.TTF");

        if (backgroundMusic.openFromFile("C:\\Users\\Ibrah\\Desktop\\Lab Work and Practice\\DodgeEmProject\\oopProject1\\sound\\MainMusic.mp3")) {
            backgroundMusic.setLoop(true);
            backgroundMusic.play();
        }

        // Initialize Menu Options
        options[0] = Text("Start a New Game", font, 24);
        options[1] = Text("See High-Scores", font, 24);
        options[2] = Text("Help", font, 24);
        options[3] = Text("Exit", font, 24);

        HelpText = Text("Use The Arrow Keys To Move. That is all the help for now", font, 24);
        HelpText.setPosition(10.f, 150.f);
        HelpText.setFillColor(Color::White);

        // Position The Menu Options
        for (int i = 0; i < maxOptions; ++i) {
            options[i].setPosition(275.f, 360.f + i * 50);
            options[i].setFillColor(i == selectedOption ? Color::Blue : Color::White);
        }
    }

    void display_menu() {
        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    window.close();
                }
                if (event.type == Event::KeyPressed) {
                    if (event.key.code == Keyboard::Up) {
                        if (selectedOption > 0) selectedOption--;
                    }
                    else if (event.key.code == Keyboard::Down) {
                        if (selectedOption < maxOptions - 1) selectedOption++;
                    }
                    else if (event.key.code == Keyboard::Enter) {
                        handleMenuSelection();
                    }
                    else if (event.key.code == Keyboard::Escape && displayHelp) {
                        displayHelp = false; // Exit Help Screen And Return To Main Menu
                    }
                }
            }

            window.clear();
            // Draw The Background Sprite
            window.draw(backgroundSprite);

            if (!displayHelp) {
                // Draw Menu Options
                for (int i = 0; i < maxOptions; ++i) {
                    options[i].setFillColor(i == selectedOption ? Color::Blue : Color::White);
                    window.draw(options[i]);
                }
            }
            else {
                // Display Help Text
                window.draw(HelpText);
            }

            window.display();
        }
    }

    void handleMenuSelection() {
        // Handle Selection Based On The Index
        if (selectedOption == 0) {
            // Start A New Game
            window.close();
            Game g;
            g.startGame();
        }
        else if (selectedOption == 1) {
            
        }
        else if (selectedOption == 2) {
            displayHelp = true;
        }
        else if (selectedOption == 3) {
            // Exit
            window.close();
        }
    }
};

#endif