#ifndef Options_h
#define Options_h

#include <stdio.h>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <fstream>
using namespace sf;
using namespace std;
#define OPT_MENU_ITEMS 5  
#define HORIZ 3
//Variable that show the items in the option menu
class Options{
    
private:
    RenderWindow *window;
    Font optfont;                   //Variable of type font to used for the intialiing the font type
    Text optmenu[OPT_MENU_ITEMS][OPT_MENU_ITEMS];   //Array of type text containg the texts in the menu
    Vector2f screenDimension;      //Variable used for the screen's dimension
    int optPosX;           //Variable used to indicate the selected menu item
    int optPosY;
    Sprite OptionBackground;
    Texture OptionText;
   
public:
    //Constructor recieves a window pointer from the MainWindo class
    Options(RenderWindow *op);
    ~Options();
    
    //Function for linking the Previous game variable with their files
    void initialize(float width, float height);
    
     //Function responsible for managing drawcontent and the processevent loop
    void gameLoop();
    
    //Function resposible for displaying everything on the screen
    void drawContent();
    
    //Function responsible for managing all the event happening in the Options indow
   bool proccessEvent();
    
    //Four functions responsible for constructing the movement in the menu
    void MoveUp();
    void MoveDown();
     void MoveLeft();
     void MoveRight();
    
   //Function returns a variable used in switch cases to know which variable is highlighted in the menu
    void GetPressedOpt(int& x, int& y);
    
    //Variable for the volume of the music
    float Vol;
    
    //music is the variable used in playing the game's main music
    Music music;
    //Input stream used to get the volume of the music
    ifstream inMusic;
    //Output stream used to overwrite the old volume of the music
    ofstream outMusic;
    
};

#endif 
