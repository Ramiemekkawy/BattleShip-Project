#ifndef Grid_h
#define Grid_h

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "MainWindow.h"
using namespace sf;
using namespace std;

class Grid{
    
private:
    RenderWindow *window;
     Cell A[10][10];
    
public:
    
    Grid();
    ~Grid();
    void drawContent(RenderWindow*);
    void initialize(int,int);
    void gameLoop();
    void setgridPos(int,int);

    

   
    
};
#endif
