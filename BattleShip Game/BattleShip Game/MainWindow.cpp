#include "MainWindow.h"
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include "Options.h"
#include "PlayGame.h"
#include "Grid.h"
using namespace sf;
using namespace std;


MainWindow::MainWindow() : menu(800,600)
{
   Fullscreen=true;
	//Variable of type integer Vector, used for the screen's dimension
    screenDimension = Vector2i(800,600);
  //Main Window as pointer so the full game would be opened in only one window
    window = new RenderWindow(VideoMode(screenDimension.x,screenDimension.y), "Battleship");
    //Variable is used to adjust the main window to the scree's dimensions
    Menu menu(window->getSize().x, window->getSize().y);
    initialize();
    gameLoop();
    
}

MainWindow::~MainWindow(){
    delete window;
}

//Functions used for linking previously declared variables with their paths or values
void MainWindow::initialize(){
    
    inMusic.open("C:\Rami\Google Drive\AUC\CSCE 1101\Projects\Battleship\Music\MusicFile.txt");
    
    //Inputing the volume from the MusicFile text
    inMusic>>setVol;
    
    //Setting the volume based on the adjusted volume
    music.setVolume(setVol);
    
    //path of the game's music theme
    music.openFromFile("C:\Rami\Google Drive\AUC\CSCE 1101\Projects\Battleship\Music\11 Agent of Chaos.ogg");
    music.setLoop(true);
    music.play();
   
    
   //Path of the background picture
    background.loadFromFile("C:\Rami\Google Drive\AUC\CSCE 1101\Projects\Battleship\Pics\Background1.jpg");
    
    //Linking the Sprit with (Pic) variable of type texture
    pic.setTexture(background);
   

 //Path of the game's icon
    Icon.loadFromFile("C:\Rami\Google Drive\AUC\CSCE 1101\Projects\Battleship\Pics\ICON.png");
   window->setIcon(256,256,Icon.getPixelsPtr());
}
//Loop that contains the open window and poll event loop
void MainWindow::gameLoop(){

    while (window->isOpen()) {
          proccessEvent();
        drawContent();
    }
}

//Function responsible for displaying the content of the game on the Screen
void MainWindow::drawContent(){
    
    window->clear();
    window->draw(pic);
    //Menu is a class with a draw function, which take window pointer and displays the main menu
    menu.draw(*window);
    
    window->display();
   
    
}

//Loop responsible for handling the event happening in the main window
void MainWindow::proccessEvent(){
  
    //Variable of type event used in managing all the event happening in the game
    Event event;
    //Main loop of the events of the game
    while (window->pollEvent(event) )
    {
        switch (event.type)
        {
             
               
            case sf::Event::KeyPressed:
                if( event.key.code == Keyboard::Up){
                    menu.MoveUp();
                        break;
                    }
                else
                    if(event.key.code == Keyboard::Down){
                    menu.MoveDown();
                    break;
                    }
   //Switch case based on variable that indicates the position of the slected menu item
              if(event.key.code == Keyboard::Return )
                    switch (menu.GetPressedItem())
                {
                //Case that opens the Game window
                    case 0:
                        PlayGame(this->window);
                        break;
                        
                //Case that opens the options or the setting window
                    case 1:
                    
                        Options(this->window);
                        inMusic.open("C:\Rami\Google Drive\AUC\CSCE 1101\Projects\Battleship\Music\MusicFile");
                        inMusic>>setVol;
                        music.setVolume(setVol);
                    
                        break;
                //Case that opens the highscore window
                    case 2:
                        if ( true == Fullscreen )
                        {
                            window->create(sf::VideoMode(800, 600), "Battleship", sf::Style::Fullscreen);
                            
                            Fullscreen = false;
                        }
                        else
                        {
                            window->create(sf::VideoMode(800, 600), "battleship", sf::Style::Default);
                            
                            Fullscreen = true;
                        }
                        
                        break;
                    //Case if the Exit menu item is selected
                        
                    case 3:
                        //Highscore
                        break;
                    case 4:
                        window->close();
                        break;
                }
                    break;

            }
                if (event.type == sf::Event::Closed) {
            window->close();
        }
        
        // Escape pressed : exit
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            window->close();
        }
    }
       
    }





