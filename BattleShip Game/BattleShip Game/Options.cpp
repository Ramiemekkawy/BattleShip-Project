#include "Options.h"
#include "Controls.h"
#include "MainWindow.h"
#include "ResourcePath.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

Options::Options(RenderWindow *op){
   
    //Variable of type float Vector, used for the screen's dimension
    screenDimension = Vector2f(800,600);
    //Window is declared in the Mainwindow class, used to indiacte the window of the options class
    window = op;
    initialize(screenDimension.x,screenDimension.y);
    gameLoop();
    
}
//Output stream is used to overwite the old value in the MusicFile text, to adjust the new volume

Options::~Options(){
    outMusic.open("/Users/bahermursi/Desktop/ProjectGame/ProjectGame/MusicFile");
    outMusic << Vol;
    outMusic.close();
}

//Functions used for linking previously declared variables with their paths or values
void Options::initialize(float width, float height){
    inMusic.open( resourcePath() + "MusicFile");
    inMusic>>Vol;
    if (!inMusic.is_open()) {
        cout<<" ERROR CANT OPEN FILE ";
    }
    
    cout<<Vol;
 
    if (!OptionText.loadFromFile(resourcePath() + "OptionBack.jpg")) {
        cout << "Couldn't load option background " << endl;
    }
    
    OptionBackground.setTexture(OptionText);
    
  
    if (!optfont.loadFromFile(resourcePath() + "vicioushungerexpand.ttf")) {
        cout << "Couldn't load option font file " << endl;
    }
   // optmenu is an array of type text that displays the menu on the screen
    //OPT_MENU_ITEM is the number of items in the menu
    
    
    optmenu[0][0].setFont(optfont);
    optmenu[0][0].setColor(sf::Color(128,0,0));
    optmenu[0][0].setString("Music: ");
    optmenu[0][0].setPosition(sf::Vector2f(100, height/(OPT_MENU_ITEMS +1) *1));
    
    optmenu[0][1].setFont(optfont);
    optmenu[0][1].setColor(sf::Color::White);
    optmenu[0][1].setString("Plus +");
    optmenu[0][1].setPosition(sf::Vector2f(400, height/(OPT_MENU_ITEMS +1) *1));
    
    optmenu[0][2].setFont(optfont);
    optmenu[0][2].setColor(sf::Color::White);
    optmenu[0][2].setString("Minus -");
    optmenu[0][2].setPosition(sf::Vector2f(600, height/(OPT_MENU_ITEMS +1) *1));
    
    optmenu[1][0].setFont(optfont);
    optmenu[1][0].setColor(sf::Color::White);
    optmenu[1][0].setString("Controls");
    optmenu[1][0].setPosition(sf::Vector2f(100, height/(OPT_MENU_ITEMS +1) *2));
    
    optmenu[2][0].setFont(optfont);
    optmenu[2][0].setColor(sf::Color::White);
    optmenu[2][0].setString("Back");
    optmenu[2][0].setPosition(sf::Vector2f(100, height/(OPT_MENU_ITEMS +1) *3));
    
   optPosX = 0;
    optPosY=0;
    
}

//C is a boolean used to manage the event of going back to the previous window, it sets the processevent loop to fale when backspace button if pressed

//Main loop of the options class
void Options::gameLoop(){
    bool opt=true;
    while (window->isOpen() && opt) {
    opt = proccessEvent();
        drawContent();
    }
}

//C is a boolean used to manage the event of going back to the previous window, it sets the processevent loop to fale when backspace button if pressed

//Loop responsible for handling the event happening in the options window
bool Options::proccessEvent(){
    bool opt =true;
    Event event;
    while (window->pollEvent(event) && opt)
    {


                    if (event.type == sf::Event::KeyPressed && event.key.code ==  73){
                    MoveUp();
                    break;
                    }
                   else
                       if (event.type == sf::Event::KeyPressed && event.key.code == 74){
                    MoveDown();
                    break;
                    }
                    else
                        if (event.type == sf::Event::KeyPressed && event.key.code == 72){
                    MoveRight();
                    break;
                   }
                   else
                       if (event.type == sf::Event::KeyPressed && event.key.code == 71){
                    MoveLeft();
                        break;}
                    
        if (event.type == sf::Event::KeyPressed && event.key.code == Keyboard::Return){
            
            //Case 1 and 2 are plus and minus menu items, used for adjusting the volume of the game
            
         /*   if (GetPressedOpt() == ){
                break;
            }
            else
          */
            int x,y;
            GetPressedOpt(x, y);
                if (x  == 0 && y ==1){
                    if (Vol<=90)
                        Vol+=10;
                        break;
                }
          else
              if (x == 0 && y==2){
                        if (Vol>=10)
                            Vol-=10;
                        break;
            }
        //Case 3 is responsible for opening the controls window
           else
            if (x == 1 && y==0){
                       Controls(this->window);
                        break;
            }
        //Case 4 is sets c to false when back is selected fro the options menu
           else
            if (x == 2 && y == 0){
                opt = false;
                
                }
            
            //Case when BackSpace is pressed to go to the previous window
            
            
        //Case when event ends, so the window would be closed
            //If the event is finished the window will close
            if (event.type == sf::Event::Closed)
                window->close();
            
            
            // Escape pressed : exit
            if (event.type == sf::Event::KeyPressed && event.key.code == Keyboard::Escape)
                window->close();
        }
        
    }
    
    if(Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
        opt = false;
    
    return opt;
}

//Function that manages displaying the option menu on the screen
void Options::drawContent()
{     window->clear();
      window->draw(OptionBackground);
  
    for (int i=0; i<OPT_MENU_ITEMS; i++)
        for (int j=0; j<HORIZ; j++){
        window->draw(optmenu[i][j]);
        }
    
  
    window->display();
}

// Four functions responsible for constructing the movement in the opitons menu
//Selectedoption is a variable used to indicate the position of the selected menu item
void Options::MoveUp(){
    
    if (optPosX - 1 >=0 ) {
        optmenu[optPosX][0].setColor(sf::Color::White);
        optPosX --;
        optmenu[optPosX][0].setColor(sf::Color(128,0,0));
        
    }
    
}

//Selectedoption is a variable used to indicate the position of the selected menu item
//OPT_MENU_ITEM is the number of items in the menu
void Options::MoveDown(){

 if (optPosX +1 < HORIZ) {
 optmenu[optPosX][0].setColor(sf::Color::White);
 optPosX ++;
 optmenu[optPosX][0].setColor(sf::Color(128,0,0));
            
        }
        
    }
//Selectedoption is a variable used to indicate the position of the selected menu item
void Options::MoveLeft(){
    
    if (optPosY -1 >=0) {
        optmenu[0][optPosY].setColor(sf::Color::White);
        optPosY --;
        optmenu[0][optPosY].setColor(sf::Color(128,0,0));
    }
      
    
}
//Selectedoption is a variable used to indicate the position of the selected menu item
//OPT_MENU_ITEM is the number of items in the menu
void Options::MoveRight(){
    
    if (optPosY +1 < HORIZ ) {
        optmenu[0][optPosY].setColor(sf::Color::White);
        optPosY ++;
             optmenu[0][optPosY].setColor(sf::Color(128,0,0));
        }
    }

//Fucntion that returs the position of the selected item

void Options::GetPressedOpt( int& x, int& y ){
    
    x = optPosX;
    y = optPosY;
    
}