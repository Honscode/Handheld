#pragma once
#include "Game.h"
#include "Games/FlappyBird/bird.h"
#include "Games/FlappyBird/pipe.h"

PinModule::GamePadPins flappyBirdControls = {31, 33, 35, 37};
Bird bird(flappyBirdControls);
Pipe pipe;

class FlappyBird : public GameManager
{
public:
    FlappyBird() {}
    void start() override
    {
        bird.start();
    }
    void update() override
    {
        bird.update();
        pipe.update();
    }
    void draw(Adafruit_GFX& display) override
    {
        bird.draw(display);
        pipe.draw(display);
    }
    void reset() override
    {
        bird.reset();
    }
    ~FlappyBird() {}
};

