#include "Game.h"

class Pipe
{
private:
    int pipeX;
    int gapY;
    const int pipeWidth = 10;
    const int gapHeight = 30;
    const int speed = 2;
public:
    Pipe() 
    {
        reset();
    }
    void update()
    {
        pipeX -= speed; // Move pipe to the left
        if (pipeX < -pipeWidth) // Reset pipe when it goes off-screen
        {
            reset();
        }
    }
    void draw(Adafruit_GFX& display)
    {
        // Draw upper pipe
        display.fillRect(pipeX, 0, pipeWidth, gapY, SSD1306_WHITE);
        // Draw lower pipe
        display.fillRect(pipeX, gapY + gapHeight, pipeWidth, 64 - (gapY + gapHeight), SSD1306_WHITE);
    }
    bool collisionCheck(int birdY, int birdHeight)
    {
        bool collision = false;
        // Check horizontal overlap
        if (pipeX < 20 + 5 && pipeX + pipeWidth > 10) // Bird x position is 10, radius 5
        {
            // Check vertical overlap
            if (birdY < gapY || birdY + birdHeight > gapY + gapHeight)
            {
                collision = true;
            }
        }
        return collision;
    }
    void reset()
    {
        pipeX = 128; // Start off-screen to the right
        gapY = rand() % (64 - gapHeight); // Random gap position
    }
};



