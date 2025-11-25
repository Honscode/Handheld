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
// Implementation of PinModule functions
void PinModule::initializePins(const PinModule::GamePadPins& pins) {
    pinMode(pins.up, INPUT_PULLUP);
    pinMode(pins.down, INPUT_PULLUP);
    pinMode(pins.left, INPUT_PULLUP);
    pinMode(pins.right, INPUT_PULLUP);
}
// Function to set a pin high
void PinModule::setPinHigh(int pinNumber) {
    digitalWrite(pinNumber, HIGH);
}
// Function to set a pin low
void PinModule::setPinLow(int pinNumber) {
    digitalWrite(pinNumber, LOW);
}
// Function to check if a specific button is pressed
bool PinModule::isButtonPressed(const PinModule::GamePadPins& pins, Button button) {
    int pinToCheck;
    switch (button) {
        case Button::Up:
            pinToCheck = pins.up;
            break;
        case Button::Down:
            pinToCheck = pins.down;
            break;
        case Button::Left:
            pinToCheck = pins.left;
            break;
        case Button::Right:
            pinToCheck = pins.right;
            break;
        default:
            return false; // Invalid button
    }
    return digitalRead(pinToCheck) == HIGH;
}