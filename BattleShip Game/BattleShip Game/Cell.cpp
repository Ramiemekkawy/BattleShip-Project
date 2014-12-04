#include "Cell.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ResourcePath.hpp"
using namespace sf;
using namespace std;


Cell::Cell(){ initialize(); }

Cell::~Cell(){}

//intitalizing the sprites to their textures and locations

void Cell::initialize(){
    h = m = false;
    
    if (!backpic.loadFromFile(resourcePath() + "Backcell.png"))
        cout <<" Couldn't load playgame back image" << endl;
    
    if (!bX.loadFromFile(resourcePath() + "BlackX.png"))
        cout <<" Couldn't load player image" << endl;
    
    if (!rX.loadFromFile(resourcePath() + "RedX.png"))
        cout <<" Couldn't load player image" << endl;

    
    backcell.setTexture(backpic);
    RedX.setTexture(rX);
    blackX.setTexture(bX);
    
}

// hit will be given a position where it will draw Red X
void Cell::hit(){
    h = true;
    

}
//miss will be given a position where it will draw black X
void Cell::miss(){

    m = true;
    
    
}

void Cell::setShift(int xshift, int yshift){
    lx = xshift;
    ly = yshift;
}

void Cell::draw(RenderWindow *w){
    w->draw(backcell);
    
    if(h) w->draw(RedX);
    else if(m) w->draw(blackX);
}

bool Cell::is_hit(bool x){
    
    return x;
}

void Cell::sPosition(int xPosition, int yPosition){
    
    xPosition*=32;
    yPosition*=32;
    
    xPosition += lx;
    yPosition += ly;
    
    RedX.setPosition(xPosition, yPosition);
    blackX.setPosition(xPosition, yPosition);
    backcell.setPosition(xPosition, yPosition);
    
    
}
