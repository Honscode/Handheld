#include "PinModule.h"
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
    return digitalRead(pinToCheck) == LOW;
}