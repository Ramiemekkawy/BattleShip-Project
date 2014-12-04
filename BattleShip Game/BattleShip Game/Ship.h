#ifndef Ship_h
#define Ship_h

#include <stdio.h>
#include <SFML/Graphics.hpp>
using namespace sf;

class Ship{
private:
     RenderWindow *window;
    int hlth;
    int shipSize;
    Texture shipText;
    Sprite shipPic;
    
    
public:
    
    Ship();
    ~Ship();
    void Position(int,int);
    int Health(bool,int);
    void initialize(int);
    void oriantation(Sprite,Event);
    void drawShip( RenderWindow*);
    
    
    
};

#endif 

