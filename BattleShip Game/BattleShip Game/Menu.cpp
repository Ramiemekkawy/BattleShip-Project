#include "Menu.h"
#include <iostream>
#include <SFML/Graphics.hpp>


using namespace sf;
using namespace std;

Menu::Menu(float width, float height){
    //to load the font file
    if (!font.loadFromFile("C:\Rami\Google Drive\AUC\CSCE 1101\Projects\Battleship\Font\vicioushungerexpand.ttf")) {
        cout << "Couldn't load font file " << endl;
    }
    
// Menu is an array of type text that displays the menu on the screen
//MENU_ITEM is the number of items in the menu
    menu[0].setFont(font);
    menu[0].setCharacterSize(50);
    menu[0].setColor(sf::Color(128,0,0));
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(350, height/(MENU_ITEMS +1) *1));
    
    menu[1].setFont(font);
    menu[1].setCharacterSize(50);
    menu[1].setColor(sf::Color(240,248,255));
    menu[1].setString("Options");
    menu[1].setPosition(sf::Vector2f(330, height/(MENU_ITEMS +1) *2));
    
    menu[2].setFont(font);
    menu[2].setCharacterSize(50);
    menu[2].setColor(sf::Color(240,248,255));
    menu[2].setString("Fullscreen");
    menu[2].setPosition(sf::Vector2f(300, height/(MENU_ITEMS +1) *3));
    
    menu[3].setFont(font);
    menu[3].setCharacterSize(50);
    menu[3].setColor(sf::Color(240,248,255));
    menu[3].setString("Highscore");
    menu[3].setPosition(sf::Vector2f(300, height/(MENU_ITEMS +1) *4));
    
    menu[4].setFont(font);
    menu[4].setCharacterSize(50);
    menu[4].setColor(sf::Color(240,248,255));
    menu[4].setString("Exit");
    menu[4].setPosition(sf::Vector2f(370, height/(MENU_ITEMS +1.3) *5));
    
    selectedItemIndex = 0; //It states the index that the menu point at
}



Menu :: ~Menu(){
    
}

//MENU_ITEMS is the number of items in the menu

//A function that draws the menu on the screen through a loop
//MENU_ITEM is the number of items in the menu
void Menu::draw(RenderWindow &window)
{
    for (int i=0; i<MENU_ITEMS; i++)
        window.draw(menu[i]);
    
}

//Function for moving up in the menu
void Menu::MoveUp()
{
    if (selectedItemIndex - 1 >=0) {
        menu[selectedItemIndex].setColor(sf::Color(224,255,255));
        selectedItemIndex --;
        menu[selectedItemIndex].setColor(sf::Color(128,0,0));
        
    }
    
}

//Function for moving down in the menu
//MENU_ITEM is the number of items in the menu
    void Menu::MoveDown()
    {
        if (selectedItemIndex +1 < MENU_ITEMS) {
            menu[selectedItemIndex].setColor(sf::Color(224,255,255));
            
            selectedItemIndex ++;
            menu[selectedItemIndex].setColor(sf::Color(128,0,0));
            
            
        }
        
}

//Function returns a variable used in switch cases to know which variable is highlighted in the menu
int Menu::GetPressedItem(){
    return selectedItemIndex;
}

