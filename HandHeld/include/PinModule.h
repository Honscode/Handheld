#pragma once
#include <Arduino.h>

namespace PinModule {
    // Enumeration for gamepad buttons 
    enum class Button { Up, Down, Left, Right };
    // Structure to hold pin numbers for each button
    struct GamePadPins
    {
        int up;
        int down;
        int left;
        int right;
    };
    // Function to initialize pins
    void initializePins(const GamePadPins& pins);
    // Functions to set pin states
    void setPinHigh(int pinNumber);
    void setPinLow(int pinNumber);

    // Function to check if a button is pressed
    bool isButtonPressed(const GamePadPins& pins, Button button);
}
