#pragma once
#include "Game.h"



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
        
        if (PinModule::isButtonPressed(controlPins, PinModule::Button::Up)) 
        {
            birdVelocity = jumpStrength;
        }
    }
    void reset()
    {
        birdY = 0;
        birdVelocity = 0;
    }
    ~Bird() {}
};