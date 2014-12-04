#include "Soundtrack.h"
#include "ResourcePath.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;


Controls::Controls(RenderWindow *con, Music* m){
    //Variable of type float Vector, used for the screen's dimension
    screenDimension = Vector2f(800,600);
     //Window is declared in the Mainwindow class, used to indiacte the window of the controls class
    window = con;
    music = m;
    initialize(screenDimension.x,screenDimension.y);
    gameLoop();
}

Controls::~Controls(){
    
}

//Functions used for linking previously declared variables with their paths or values
void Controls::initialize(float width, float height){
    
    outCont.open("/Users/bahermursi/Desktop/ProjectGame/ProjectGame/ControlsFile");
    if (!outCont.is_open())
        cout<<"ERROR control file can't be opened"<<endl;
    
        if (!ControlText.loadFromFile(resourcePath() + "ControlBack.jpg"))
        cout << "Couldn't load Control Backgroung file " << endl;
    

    if (!contfont.loadFromFile(resourcePath() + "vicioushungerexpand.ttf"))
        cout << "Couldn't load Control font file " << endl;
    
    // contmenu is an array of type text that displays the menu on the screen
    contmenu[0].setFont(contfont);
    contmenu[0].setColor(sf::Color(128,0,0));
    contmenu[0].setString("1- Face Down - The Red Jumpsuit Apparatus");
    contmenu[0].setPosition(sf::Vector2f(15, 20));
    
    contmenu[1].setFont(contfont);
    contmenu[1].setColor(sf::Color::White);
    contmenu[1].setString("2- Blame - Calvin Harris feat. John Newman");
    contmenu[1].setPosition(sf::Vector2f(15, 120));
    
    contmenu[2].setFont(contfont);
    contmenu[2].setColor(sf::Color::White);
    contmenu[2].setString("3- One Night (Vicetone Remix) - Matthew Koma");
    contmenu[2].setPosition(sf::Vector2f(15, 220));
    
    contmenu[3].setFont(contfont);
    contmenu[3].setColor(sf::Color::White);
    contmenu[3].setString("4- Burn It to the Ground - Nickelback");
    contmenu[3].setPosition(sf::Vector2f(15, 330));
    
    contmenu[4].setFont(contfont);
    contmenu[4].setColor(sf::Color::White);
    contmenu[4].setString("5- Agent Of Chaos - Hanz Zimmer");
    contmenu[4].setPosition(sf::Vector2f(15, 430));
    
    contmenu[5].setFont(contfont);
    contmenu[5].setColor(sf::Color::White);
    contmenu[5].setString("6- Ameno - Era");
    contmenu[5].setPosition(sf::Vector2f(15, 530));

    //variable used to indiacte the position of the selected menu item
    selectedMenu = 0;
}

//Loop that contains the open window and poll event loop
void Controls::gameLoop(){
    bool conb=true;
    while (window->isOpen() && conb) {
        conb = proccessEvent();
        drawContent();
    }
}

//Loop responsible for handling the event happening in the constrols window
bool Controls::proccessEvent(){
    bool conb=true;
    char Enter='\n';
    Event event;
    while (window->pollEvent(event) && conb)
    {
        
        //Up = 73, Down = 74, Right = 72, Left = 71
       //If the pressed key is up
        
        if (event.type == sf::Event::KeyPressed && event.key.code == Keyboard::Up){
                    MoveUp();
                    break;
                }
          //If the pressed key is down
                else
                    if (event.type == sf::Event::KeyPressed && event.key.code == Keyboard::Down){
                       MoveDown();
                        break;
                    }
        if (event.type == sf::Event::KeyPressed && event.key.code == Keyboard::Return){
            
            if(GetPressedCont() == 0){
              
                music->openFromFile(resourcePath() + "Face down.ogg");
                music->setLoop(true);
                music->play();
                       if (event.KeyPressed ==  13)
                          break;
                   }
                   if(GetPressedCont() == 1){
                       music->openFromFile(resourcePath() + "Blame.ogg");
                       music->setLoop(true);
                       music->play();

                        break;
                   }
                   if(GetPressedCont() ==  2){
                           music->openFromFile(resourcePath() + "One Night (Vicetone Remix).ogg");
                           music->setLoop(true);
                           music->play();
                
                        break;
                   }
                   if(GetPressedCont() == 3){
                       music->openFromFile(resourcePath() + "Burn It to the Ground.ogg");
                       music->setLoop(true);
                       music->play();
                   
                        break;
                   }
            if(GetPressedCont() == 4){
                music->openFromFile(resourcePath() + "Agent Of Chaos.ogg");
                music->setLoop(true);
                music->play();
                
                break;
            }
            if(GetPressedCont() == 5){
                music->openFromFile(resourcePath() + "Ameno.ogg");
                music->setLoop(true);
                music->play();
                
                break;
            }

              }
    
         if(Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
            conb=false;
         
        //If the event is finished the window will close
        if (event.type == sf::Event::Closed)
            window->close();
        
        // Escape pressed : exit
        if (event.type == sf::Event::KeyPressed && event.key.code == Keyboard::Escape)
            window->close();
    
        }
    
    return conb;
}


//Function that manages dispkaying the option menu on the screen
//CONT_MENU_ITEM is the number of items in the menu
void Controls::drawContent()

{     window->clear();
    window->draw(ControlBackground);
    for (int i=0; i<CONT_MENU_ITEMS; i++)
        window->draw(contmenu[i]);
    
    window->display();
}

// Four functions responsible for constructing the movement in the opitons menu
//SelectedMenu is a variable used to indicate the position of the selected menu item
//CONT_MENU_ITEM is the number of items in the menu
void Controls::MoveUp(){
    
    
    if (selectedMenu - 1 >=0 ) {
        contmenu[selectedMenu].setColor(sf::Color::White);
        selectedMenu --;
        contmenu[selectedMenu].setColor(sf::Color(128,0,0));
        
        
    }
    
}
//CONT_MENU_ITEM is the number of items in the menu
void Controls::MoveDown(){
    
    if (selectedMenu +1 < CONT_MENU_ITEMS) {
        contmenu[selectedMenu].setColor(sf::Color::White);
        selectedMenu++;
        contmenu[selectedMenu].setColor(sf::Color(128,0,0));
        
    }
    
}


int Controls::GetPressedCont(){
    return selectedMenu;
}



