#ifndef Cell_h
#define Cell_h

#include <stdio.h>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Cell{
    
private:
    //RenderWindow *window;
    Sprite backcell;
    Sprite blackX;
    Sprite RedX;
    
    bool h, m;
    int lx, ly;
    
    Texture backpic;
    Texture bX;
    Texture rX;
    int Xposition;
    int Yposition;
    //Ship* ship;
    
public:
   
    Cell();
    ~Cell();
    void hit();
    void miss();
    void draw(RenderWindow*);
    void initialize();
    bool is_hit(bool);
    void setShift(int,int);
    void sPosition(int,int);
    
};

#endif 
