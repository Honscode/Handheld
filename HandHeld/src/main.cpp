#include <Arduino.h>
#include "Games/FlappyBird/BirdGame.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

FlappyBird flappyBird;

GameManager *currentGame = nullptr;
void setup() {
  Serial.begin(9600);
    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  currentGame = &flappyBird;
  currentGame->start();
}

void loop() {
  display.clearDisplay();
  if (currentGame != nullptr) 
  {
    currentGame->update();
    // Here you would typically call a draw method to update the display  
    currentGame->draw(display); // Assuming 'display' is your Adafruit_SSD1306 object
  }
  display.display();
}
