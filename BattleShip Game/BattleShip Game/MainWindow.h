#ifndef MainWindow_h
#define MainWindow_h

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include "Menu.h" 
using namespace sf;
using namespace std;

class MainWindow{
private:
    RenderWindow *window;      //the main window
    Vector2i screenDimension; //Variable used to declare the screen dimension
    Menu menu;                //Menu is a class, and the variable is used in displaying the menu on screen
    Texture background;      //Background is the texture of the main backround pic
    Sprite pic;             //Pic is the sprite of the main background pic
    Image Icon;            //icon is the icon of the game
    Music music;          //music is the variable used in playing the game's main music
    ifstream inMusic;    //Input stream used to get the volume of the music
    ofstream outMusic;  //Output stream used to overwrite the old volume of the music
    bool Fullscreen;
    
    
public:
 
	MainWindow();
	~MainWindow();
	void initialize();      //Function for linking the Previous game variable with their files
	void gameLoop();        //Function responsible for managing drawcontent and the processevent loop
	void drawContent();     //Function resposible for displaying everything on the screen
	void proccessEvent();
	int setVol;            //Variable used for the music volume

	//Cont.. are Variables used in adjusting the controls of the game
	int contUp;
	int contDown;
	int contLeft;
	int contRight;

};

#endif 
