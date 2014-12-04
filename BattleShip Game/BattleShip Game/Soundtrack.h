#ifndef Soundtrack_h
#define Soundtrack_h

#include <stdio.h>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <fstream>
using namespace sf;
using namespace std;
#define CONT_MENU_ITEMS 6 //Number of items in menu
class Controls{
    
private:
    RenderWindow *window;
    Font contfont;      //Variable of type font, used to assign the font of the menu
    Text contmenu[CONT_MENU_ITEMS]; //Array of type text, fot the items in the control menu
    Vector2f screenDimension;       //Variable of type float Vector for the screen's Dimensions
    ifstream inCont;                //input stream for the controls of the game
    ofstream outCont;               //Outputstream for the controls of the game
     int selectedMenu;              //variable that indicates the position of the menu
    Event event;
    Sprite ControlBackground;
    Texture ControlText;
    Music* music;
public:
    Soundtrack(RenderWindow *op, Music* );
    ~Soundtrack();
    //Function for linking the Previous game variable with their files
    void initialize(float width, float height);
     //Function responsible for managing drawcontent and the processevent loop
    void gameLoop();
    //Function resposible for displaying everything on the screen
    void drawContent();

  //Function responsible for managing all the event happening in the Controls window
    bool proccessEvent();

    void MoveUp();
    void MoveDown();
    
    int GetPressedCont();           //Function that indicates the position of the menu
        string s;
    char contUp;
    char contDown;
    char contLeft;
    char contRight;
};

#endif 