#include "PlayGame.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"
#include "Cell.h"
using namespace std;
using namespace sf;

PlayGame::PlayGame(RenderWindow *w){
    
    window = w;
    initialize();
    gameLoop();
}

PlayGame:: ~PlayGame(){
    
}

void PlayGame:: initialize(){
    Ply_Grid.setgridPos(50, 60);
    Comp_Grid.setgridPos(400, 60);
    
  
    Us1.initialize(1);
  
    
}

void PlayGame:: gameLoop(){
    bool o = true;
    while (window->isOpen() && o) {
        o = proccessEvent();
        drawContent();
    }
}

void PlayGame::drawContent(){
    window->clear();
    Ply_Grid.drawContent(window);
    Comp_Grid.drawContent(window);
    Us1.drawShip(window);
    //Us2.drawShip(window);
    //Us3.drawShip(window);
    window->display();
 
}

bool PlayGame:: proccessEvent(){
    bool o = true;
    Event event;
    while (window->pollEvent(event) && o)
    {
        Vector2i mouseposition = sf::Mouse::getPosition(*window);

        //Us1.Position(320, 320);
             if(Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
                o = false;
        
        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) ){
                       Us1.Position(mouseposition.x, mouseposition.y);
        }
      
        cout <<"X: "<<mouseposition.x <<"    "<<"Y: "<<mouseposition.y<<endl;
    }
    return o;
}






