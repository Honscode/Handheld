#include <Arduino.h>

class GameManager
{
private:
    
public:
    GameManager();
    // Lifecycle methods and some can be unused in some games
    virtual void start(){};
    virtual void update(){};
    virtual void reset(){};
    virtual void resume(){};
    virtual void pause(){};
    virtual void stop(){};

    ~GameManager();
};
