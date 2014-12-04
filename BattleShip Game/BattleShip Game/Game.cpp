#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Menu.h"
using namespace std;
using namespace sf;

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"

int main(int, char const**)
{
    
    enum direction{Down,Left,Right,Up,Jump};
    //declare directions
    Vector2i source(1,Down);
    Vector2i dire(1,Down);
    srand(unsigned(0));
    Font font;
    
    // Create the main window
    Vector2i screendimension(800,600);
    Vector2i blockdimension(10,10);
    RenderWindow window(VideoMode(screendimension.x, screendimension.y), "Battlefield", Style::Default);
    
    
    window.setVerticalSyncEnabled(true);
    
    
    if (!font.loadFromFile(resourcePath() + "SEGA.ttf"))
        cout <<" Couldn't load font" << endl;
    
    
    sf::Text text( "Game", font, 60);
    text.setColor(sf::Color::Red);
    text.setPosition(350,2);
    /*
     RectangleShape rect( Vector2f(50,50));
     rect.setPosition(200, 100);
     rect.setFillColor(sf::Color::Magenta );
     rect.setOutlineColor(sf::Color::White);
     rect.setOutlineThickness(10);
     rect.setRotation(45);
     
     RectangleShape rect2( Vector2f(50,50));
     rect2.setPosition(600, 100);
     rect2.setFillColor(sf::Color::Magenta );
     rect2.setOutlineColor(sf::Color::White);
     rect2.setOutlineThickness(10);
     rect2.setRotation(45);
     
     RectangleShape rect3( Vector2f(40,20));
     rect3.setPosition(410, 300);
     rect3.setFillColor(sf::Color::Magenta );
     rect3.setOutlineColor(sf::Color::White);
     rect3.setOutlineThickness(5);
     rect3.setRotation(90);
     
     CircleShape circle(50);
     circle.setPosition(250, 200);
     circle.setFillColor(sf::Color::Yellow);
     
     
     CircleShape circle2(50);
     circle2.setPosition(450, 200);
     circle2.setFillColor(sf::Color::Yellow);
     
     
     ConvexShape Vircle2(3);
     Vircle2.setPosition(250, 300);
     Vircle2.setPoint(0,Vector2f(100,100));
     Vircle2.setPoint(1,Vector2f(150,150));
     Vircle2.setPoint(2,Vector2f(200,100));
     Vircle2.setFillColor(sf::Color::Red);
     Vircle2.setOutlineColor(sf::Color::White);
     Vircle2.setOutlineThickness(3);
     */
    
    
    //declaring Images
    Texture ptexture; // player 1
    Sprite playerimage;
    
    Texture jtexture; //player2
    Sprite playerMage;
    
    Texture qtexture; //player2
    Sprite layerMage;
    
    
    // Set the Icon
    Image icon;
    if (!icon.loadFromFile(resourcePath() + "games.png")) {
        return EXIT_FAILURE;
    }
    
    if (!ptexture.loadFromFile(resourcePath() + "playerimage.png"))
        cout <<" Couldn't load player image" << endl;
    
    if (!jtexture.loadFromFile(resourcePath() + "playerMage.png"))
        cout <<" Couldn't load player image" << endl;
    
    if (!qtexture.loadFromFile(resourcePath() + "layerMage.png"))
        cout <<" Couldn't load player image" << endl;
    
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    playerMage.setTexture(jtexture);
    playerimage.setTexture(ptexture);
    layerMage.setTexture(qtexture);
    
    playerimage.setPosition(380, 250);
    layerMage.setPosition(280, 250);
    playerMage.setPosition(480, 250);
    
    // Load a music to play
    
    Music music;
    if (!music.openFromFile(resourcePath() + "1-02 Mirror Haus.ogg")) {
        return EXIT_FAILURE;
    }    // Play the music
    music.play();
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                {
                    case sf::Keyboard::Up:
                        menu.MoveUp();
                        break;
                        
                    case sf::Keyboard::Down:
                        menu.MoveDown();
                        break;
                        
                    case sf::Keyboard::Return:
                        switch (menu.GetPressedItem())
                    {
                        case 0:
                            std::cout << "Play button has been pressed" << std::endl;
                            break;
                        case 1:
                            std::cout << "Option button has been pressed" << std::endl;
                            break;
                        case 2:
                            window.close();
                            break;
                    }
                        
                        break;
                }
                    break;
                case sf::Event::Closed:
                    window.close();
                    
                    break;
                    
            }
            
            
            //MUSIC CONTROL
            if (event.key.code == Keyboard::M)
                music.setVolume(music.getVolume()-10);
            if (event.key.code == Keyboard::P)
                music.setVolume(music.getVolume()+10);
            if (event.key.code == Keyboard::Q)
                music.stop();
            if (event.key.code == Keyboard::Q)
                music.play();
            
            
            //INITIALIZING THE CONTROLS
            
            // Player move
            if (Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                source.y=Up;
                playerimage.move(0,-4);
                
            }
            else
                if (Keyboard::isKeyPressed(sf:: Keyboard::Down)){
                    source.y=Down;
                    playerimage.move(0,4);
                    
                }
            if (Keyboard::isKeyPressed(sf::Keyboard::Left)){
                
                source.y=Left;
                playerimage.move(-4,0);
                
            }
            if (Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                source.y=Right;
                playerimage.move(4,0);
                
            }
            
            
            // player 2 move
            if (Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                dire.y=Up;
                playerMage.move(0,-4);
            }
            else
                if (Keyboard::isKeyPressed(sf:: Keyboard::S)){
                    dire.y=Down;
                    playerMage.move(0,4);
                }
            if (Keyboard::isKeyPressed(sf::Keyboard::A)){
                
                dire.y=Left;
                playerMage.move(-4,0);
            }
            if (Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                dire.y=Right;
                playerMage.move(4,0);
            }
            // player 2 move
            if (Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                dire.y=Up;
                layerMage.move(0,-4);
            }
            else
                if (Keyboard::isKeyPressed(sf:: Keyboard::S)){
                    dire.y=Down;
                    layerMage.move(0,4);
                }
            
            
            if (Keyboard::isKeyPressed(sf::Keyboard::A)){
                
                dire.y=Left;
                layerMage.move(-4,0);
            }
            if (Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                dire.y=Right;
                layerMage.move(4,0);
            }
            
            source.x++;
            if (source.x * 32 >= ptexture.getSize().x){
                source.x  = 0;
            }
            dire.x++;
            if (dire.x * 32 >= jtexture.getSize().x){
                dire.x  = 0;
            }
            
            if (dire.x * 32 >= qtexture.getSize().x){
                dire.x  = 0;
            }
            playerimage.setTextureRect(IntRect(source.x *32, source.y*32, 32,32 ));
            playerMage.setTextureRect(IntRect(dire.x *32, dire.y*32, 32,32 ));
            layerMage.setTextureRect(IntRect(dire.x *32, dire.y*32, 32,32 ));
            
            
            for (int i = 0; i < screendimension.x / blockdimension.x; i++) {
                for (int j = 0; j < screendimension.y / blockdimension.y; j++){
                    VertexArray vArray(Quads,4);
                    vArray[0].position = Vector2f(i * blockdimension.x, j*blockdimension.y);
                    vArray[1].position = Vector2f(i * blockdimension.x + blockdimension.x, j*blockdimension.y );
                    vArray[2].position = Vector2f(i * blockdimension.x + blockdimension.x, j* blockdimension.y + blockdimension.y );
                    vArray[3].position = Vector2f(i * blockdimension.x ,j*blockdimension.y + blockdimension.y );
                    
                    for (int k=0; k<4; k++) {
                        
                        
                        /*
                         int red = rand() %1;
                         int blue = rand() %2;
                         int green = rand() %255;
                         */
                        vArray[k].color = sf::Color::White;
                    }
                    window.draw(vArray);
                    
                }
                
            }
            
            // Draw the spritex
            /*
             window.draw(rect);
             window.draw(rect2);
             window.draw(rect3);
             window.draw(circle);
             window.draw(circle2);
             window.draw(Vircle2);
             */
            
            window.draw(text);
            menu.draw(window);
            window.draw(playerimage);
            window.draw(playerMage);
            window.draw(layerMage);
            
            
            // Update the window
            window.display();
            window.clear();
            
            
        }
        
    }
    
    
    return EXIT_SUCCESS;
}


