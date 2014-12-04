#include "Grid.h"
#include "Cell.h"
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "MainWindow.h"
using namespace sf;
using namespace std;


Grid::Grid(){}
Grid::~Grid(){}

void Grid::initialize(int x, int y){

}


void Grid::drawContent(RenderWindow *w){
        
    
        
        for (int i=0; i<10; i++) {
            for(int j=0; j<10; j++)
                A[i][j].draw(w);
      
       
        
   }
}

 void Grid::setgridPos(int x, int y){
     
     for (int i=0; i<10; i++) {
         for(int j=0; j<10; j++){
             A[i][j].setShift(x, y);
             A[i][j].sPosition(i , j);
         }
     }

 }


