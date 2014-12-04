#ifndef PlayGame_h
#define PlayGame_h

#include <stdio.h>
#include "SFML/Graphics.hpp"
#include <vector>
#include "Cell.h"
#include "Grid.h"
#include "Ship.h"

using namespace sf;
class PlayGame{
    
private:
    RenderWindow *window;
    Vector2i screenDimension;
    vector<Ship>User_Ships[10];
    vector<Ship>Computer_Ships[10];
    Ship Us1;
    Grid Ply_Grid, Comp_Grid;
    Sprite shippic;
    Texture shiptext;
    
    
public:
    PlayGame(RenderWindow *w);
    ~PlayGame();
    //Function for linking the Previous game variable with their files
    void initialize();
    //Function responsible for managing drawcontent and the processevent loop
    void gameLoop();
    //Function resposible for displaying everything on the screen
    void drawContent();
    //Function responsible for managing all the event happening in the Controls window
    bool proccessEvent();

};

#endif /* defined(__G123__PlayGame__) */
