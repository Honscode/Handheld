#pragma once
#include "Game.h"
#include "math.h"

class Bird
{
private:
    int birdY;
    int birdVelocity;
    const int gravity = 1;
    const int jumpStrength = -10;
    PinModule::GamePadPins controlPins;
public:
    Bird(PinModule::GamePadPins pins) : controlPins(pins),
    birdY(0), birdVelocity(0) {}
    void start() 
    {
        birdY = 0;
        birdVelocity = 0;
    }
    void update() 
    {
        birdVelocity += gravity;
        birdY += birdVelocity;
        birdY = fmax(0, fmin(birdY, 64)); // Clamp birdY between 0 and 64
        if (PinModule::isButtonPressed(controlPins, PinModule::Button::Up)) 
        {
            birdVelocity = jumpStrength;
        }
    }
    void draw(Adafruit_GFX& display) 
    {
        Serial.println(birdY);
        display.fillCircle(10, birdY, 5, SSD1306_WHITE);
    }
    void reset()
    {
        birdY = 0;
        birdVelocity = 0;
    }
    ~Bird() {}
};