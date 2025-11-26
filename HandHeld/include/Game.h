#pragma once
#include <Arduino.h>// Arduino library for microcontroller functions
#include "PinModule.h"//would be use for every app to handle input

class GameManager
{
private:
    
public:
    // Lifecycle methods and some can be unused in some games
    virtual void start(){};
    virtual void update(){};
    virtual void reset(){};
    virtual void resume(){};
    virtual void pause(){};
    virtual void stop(){};

};
