#ifndef FOOD_H
#define FOOD_H

#include <SFML/Graphics.hpp>

using namespace sf;

// Group Members:
// 1. 22i-0928 Ibrahim Azhar 
// 2. 22i-1177 Usman Haroon
// OOP Section-C

// This File Contains The Abstract Food Class Which Uses Inheritance To 
// Develop The 4 Types Of Food Used Throughout The Game 

class Food {
protected:
    int points;
    bool isActive;

public:
    Food(int p) : points(p), isActive(true) {}
    virtual void draw(RenderWindow& window) = 0;
    virtual void setPosition(const Vector2f& position) = 0;
    virtual int collectIfCollided(const FloatRect& playerBounds) = 0;
    virtual int getPoints() const = 0;
};

class RedFood : public Food {
private:
    RectangleShape shape;
public:
    RedFood(const Vector2f& position) : Food(10) {
        shape.setSize(Vector2f(10.f, 20.f));
        shape.setFillColor(Color::Red);
        shape.setPosition(position);
    }

    void draw(RenderWindow& window) override {
        if (isActive) {
            window.draw(shape);
        }
    }

    void setPosition(const Vector2f& position) override {
        shape.setPosition(position);
    }

    int getPoints() const override {
        return isActive ? points : 0;
    }

    int collectIfCollided(const FloatRect& playerBounds) override {
        if (isActive && shape.getGlobalBounds().intersects(playerBounds)) {
            isActive = false;
            return points;
        }
        return 0;
    }
};

class GreenFood : public Food {
private:
    CircleShape shape;

public:
    GreenFood(const Vector2f& position) : Food(20) {  // 20 Points For GreenFood
        shape.setRadius(10.f);  // Set The Radius For The Circle
        shape.setFillColor(Color::Green);  // Set The Fill Color To Green
        shape.setPosition(position);
        // Adjust Position To Center The Circle Correctly
        shape.setOrigin(shape.getRadius(), shape.getRadius());
    }

    void draw(RenderWindow& window) override {
        if (isActive) {
            window.draw(shape);
        }
    }

    void setPosition(const Vector2f& position) override {
        shape.setPosition(position);
    }

    int collectIfCollided(const FloatRect& playerBounds) override {
        if (isActive && shape.getGlobalBounds().intersects(playerBounds)) {
            isActive = false;
            return points;
        }
        return 0;
    }

    int getPoints() const override {
        return isActive ? points : 0;
    }
};

class OrangeHexagonFood : public Food {
private:
    ConvexShape shape;

public:
    OrangeHexagonFood(const Vector2f& position) : Food(10) {
        shape.setPointCount(6); // Hexagon Has 6 Points
        // Define Points Of Hexagon
        shape.setPoint(0, Vector2f(10.f, 0.f));
        shape.setPoint(1, Vector2f(20.f, 5.f));
        shape.setPoint(2, Vector2f(20.f, 15.f));
        shape.setPoint(3, Vector2f(10.f, 20.f));
        shape.setPoint(4, Vector2f(0.f, 15.f));
        shape.setPoint(5, Vector2f(0.f, 5.f));
        shape.setFillColor(Color(255, 165, 0)); // Orange Color According To RGB
        shape.setPosition(position);
    }

    void draw(RenderWindow& window) override {
        if (isActive) {
            window.draw(shape);
        }
    }

    void setPosition(const Vector2f& position) override {
        shape.setPosition(position);
    }

    int collectIfCollided(const FloatRect& playerBounds) override {
        if (isActive && shape.getGlobalBounds().intersects(playerBounds)) {
            isActive = false;
            return points;
        }
        return 0;
    }

    int getPoints() const override {
        return isActive ? points : 0;
    }
};

class WhiteTriangularFood : public Food {
private:
    ConvexShape shape;

public:
    WhiteTriangularFood(const Vector2f& position) : Food(15) { // 15 points For WhiteTriangularFood
        shape.setPointCount(3); // Triangle Has 3 Points
        // Define Points Of Triangle
        shape.setPoint(0, Vector2f(0.f, 0.f));
        shape.setPoint(1, Vector2f(10.f, 20.f));
        shape.setPoint(2, Vector2f(20.f, 0.f));
        shape.setFillColor(Color::White);
        shape.setPosition(position);
    }

    void draw(RenderWindow& window) override {
        if (isActive) {
            window.draw(shape);
        }
    }

    void setPosition(const Vector2f& position) override {
        shape.setPosition(position);
    }

    int collectIfCollided(const FloatRect& playerBounds) override {
        if (isActive && shape.getGlobalBounds().intersects(playerBounds)) {
            isActive = false;
            return points;
        }
        return 0;
    }

    int getPoints() const override {
        return isActive ? points : 0;
    }
};

#endif