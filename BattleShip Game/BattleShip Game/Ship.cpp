#include "Ship.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;


Ship::Ship(){}
Ship:: ~Ship(){}

void Ship:: initialize(int x){
    
    if (x ==1)
        shipText.loadFromFile("C:\Rami\Google Drive\AUC\CSCE 1101\Projects\Battleship\Pics\Ship1.png");
    else
        if (x ==2)
            shipText.loadFromFile("C:\Rami\Google Drive\AUC\CSCE 1101\Projects\Battleship\Pics\Ship2.png");
    else
        if (x ==3)
            shipText.loadFromFile("C:\Rami\Google Drive\AUC\CSCE 1101\Projects\Battleship\Pics\Ship3.png");
    else
        if (x ==4)
            shipText.loadFromFile("C:\Rami\Google Drive\AUC\CSCE 1101\Projects\Battleship\Pics\Ship4.png");
    else
        if (x ==5)
            shipText.loadFromFile("C:\Rami\Google Drive\AUC\CSCE 1101\Projects\Battleship\Pics\Ship5.png");
    
    shipPic.setTexture(shipText);
}

void Ship::Position(int x, int y){
    shipPic.setPosition(x, y);

    
   }

int Ship:: Health(bool x, int shipSize){
    if (x==true)
        hlth-=1;
	else
		hlth = shipSize;
	return hlth;
}

void Ship::oriantation(Sprite shipPic, Event event){
    
    if (event.key.code ==Keyboard::Right)
    shipPic.setRotation(90);
    
   if (event.key.code ==Keyboard::Left)
    shipPic.setRotation(-90);
    
}

void Ship::drawShip(RenderWindow *window){
    window->draw(shipPic);
}

