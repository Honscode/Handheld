#pragma once
#include "Game.h"
#include "Games/FlappyBird/bird.h"
#include "Games/FlappyBird/pipe.h"

PinModule::GamePadPins flappyBirdControls = {31, 33, 35, 37};
Bird bird(flappyBirdControls);

class FlappyBird : public GameManager
{
private:

public:
    FlappyBird() {}
    void start() override
    {
        bird.start();
    }
    void update() override
    {
        bird.update();
    }
    void reset() override
    {
        bird.reset();
    }
    ~FlappyBird() {}
};

