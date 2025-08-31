#ifndef CAR_H
#define CAR_H

#include <SFML/Graphics.hpp>
#include "arena.h"
#include <iostream>
#include <string>

using namespace sf;
using namespace std;

// Group Members:
// 1. 22i-0928 Ibrahim Azhar 
// 2. 22i-1177 Usman Haroon
// OOP Section-C

class Car {
protected:
    Texture texture;
    Sprite sprite;
    Vector2f velocity;

public:
    Car(const string& texturePath, float x, float y) : velocity(0.f, 0.f) { // Initialize Velocity
        texture.loadFromFile(texturePath);
        sprite.setTexture(texture);
        sprite.setPosition(x, y);
        sprite.setScale(0.03f, 0.03f);
    }

    void move() {
        sprite.move(velocity);
    }

    Vector2f getPosition() {
        return sprite.getPosition();
    }

    void draw(RenderWindow& window) {
        window.draw(sprite);
    }

    virtual FloatRect getBounds() const {
        return sprite.getGlobalBounds();
    }

    virtual void update(Arena& arena) = 0;
};

class PlayerCar : public Car {
private:
    bool speedBoostActive;
    Clock speedBoostTimer;
    float normalSpeed;
    float boostedSpeed;
    float currentSpeed;
    Vector2f initialPosition; // Store The Initial Position For Resetting

public:
    PlayerCar(const string& texturePath, float x, float y) : Car(texturePath, x, y),
        speedBoostActive(false),
        normalSpeed(5.f),
        boostedSpeed(7.5f),
        currentSpeed(5.f) {
        sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2); // Set Origin To Center For Rotation
    }

    FloatRect getBounds() const override {
        return sprite.getGlobalBounds();
    }

    void update(Arena& arena) override {
        Vector2f previousPosition = sprite.getPosition();

        // Calculate Direction Based On Keyboard Input
        Vector2f direction(0.f, 0.f);
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            direction.y = -1;
            sprite.setRotation(0);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down)) {
            direction.y = 1;
            sprite.setRotation(180);
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            direction.x = -1;
            sprite.setRotation(270);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right)) {
            direction.x = 1;
            sprite.setRotation(90);
        }

        // Apply Current Speed To Velocity
        velocity = direction * currentSpeed;
        sprite.move(velocity);

        // Check For Collision With The Walls
        if (arena.checkCollisionWithWalls(sprite.getGlobalBounds())) {
            // Collision Detected, Move Back To The Previous Position
            sprite.setPosition(previousPosition);
        }

        // Ensure The Car Is Within The Arena Bounds
        FloatRect arenaBounds = arena.getOuterBounds();
        Vector2f currentPosition = sprite.getPosition();
        if (currentPosition.x < arenaBounds.left || currentPosition.x > arenaBounds.left + arenaBounds.width
          || currentPosition.y < arenaBounds.top || currentPosition.y > arenaBounds.top + arenaBounds.height) {
            sprite.setPosition(previousPosition);
        }
    }

    void resetPosition() {
        // Reset The Car's Position To Its Initial Location
        Vector2f arenaCenter(400.f, 300.f);
        sprite.setPosition(arenaCenter);
        if (speedBoostActive) {
            speedBoostActive = false;
            currentSpeed = normalSpeed;
        }
    }

    void handleCollisionWithOpponent() {
        resetPosition(); // Reset The Position Of The Player Car
    }

    void activateSpeedBoost() {
        if (!speedBoostActive) {
            speedBoostActive = true;
            speedBoostTimer.restart();
            currentSpeed = boostedSpeed; // Increase Speed
        }
    }

    void updateSpeedBoost() {
        if (speedBoostActive && speedBoostTimer.getElapsedTime().asSeconds() > 10) {
            speedBoostActive = false;
            currentSpeed = normalSpeed; // Reset Speed
        }
    }
};

class OpponentCar : public Car {
private:
    float moveSpeed;
    Vector2f initialPosition;
    Vector2f outOfBoundsPosition;
    bool movingUp;
    bool IsActive; // Flag To Indicate Active State

public:
    OpponentCar(const string& texturePath, float x, float y)
        : Car(texturePath, x, y), moveSpeed(2.0f), initialPosition(x, y), movingUp(true) {
        sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2); // Set Origin To Center
        outOfBoundsPosition = Vector2f(-100.f, -100.f); // Position Off-Screen
    }

    void update(Arena& arena) override {
        if (!IsActive) return; // Skip Updating If Not Active

        // Update The Vertical Velocity Based On The Current Direction
        velocity.y = movingUp ? -moveSpeed : moveSpeed;
        velocity.x = 0; // Ensure No Horizontal Movement

        // Predict The Next Position
        Vector2f nextPosition = sprite.getPosition() + velocity;

        // Get The Global Bounds Of The Sprite
        FloatRect globalBounds = sprite.getGlobalBounds();

        // Adjust Next Position Based On The Arena Boundaries
        if (movingUp && nextPosition.y <= arena.getOuterBounds().top) {
            movingUp = false;
            nextPosition.y = arena.getOuterBounds().top; // Adjust To Top Boundary
        }
        else if (!movingUp && (nextPosition.y + globalBounds.height) >= (arena.getOuterBounds().top + arena.getOuterBounds().height)) {
            movingUp = true;
            nextPosition.y = (arena.getOuterBounds().top + arena.getOuterBounds().height) - globalBounds.height; // Adjust To Bottom Boundary
        }

        // Set The Sprite Position
        sprite.setPosition(nextPosition);
    }

    void resetPosition() {
        sprite.setPosition(initialPosition);
        movingUp = true; // Reset To Initial Direction
    }

    bool isActive() {
        return this->IsActive;
    }

    void setActive(bool active) {
        IsActive = active;
        if (!IsActive) {
            // Move The Car Out Of Bounds When Deactivated
            sprite.setPosition(outOfBoundsPosition);
            velocity = Vector2f(0.f, 0.f); // Stop The Car
        }
        else {
            // Move The Car Back In Bounds When Reactivated
            sprite.setPosition(initialPosition);
        }
    }
};
#endif