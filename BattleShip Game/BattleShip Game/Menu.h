#ifndef Menu_h
#define Menu_h

#pragma once
#include <stdio.h>
#include <SFML/Graphics.hpp>
using namespace sf;
#define MENU_ITEMS 5 //Number of items in menu

class Menu
{
private:
    
    Font font;            //Variable used to assign the font of the menu
    Text menu[MENU_ITEMS]; //Array of type text for the items in the menu
    int selectedItemIndex; //Variable of the selected item of the menu

public:
    Menu(float width, float height);
    ~Menu();
   
    void draw(RenderWindow &window); //function that recieves a window pointer to display the menu
    void MoveUp();
    void MoveDown();
    int GetPressedItem();   //Function that returns the position of selected item
    
    
};


#endif 
