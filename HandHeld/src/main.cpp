#include <Arduino.h>
#include "Games/FlappyBird/BirdGame.h"

FlappyBird flappyBird;

GameManager *currentGame = nullptr;
void setup() {
  Serial.begin(9600);
  currentGame = &flappyBird;
  currentGame->start();
}

void loop() {
  if (currentGame != nullptr) currentGame->update();
}

