#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Menu.h"
#include "MainWindow.h"
using namespace std;
using namespace sf;

int main(int, char const**)
{
    
    delete new MainWindow();
    return EXIT_SUCCESS;
}

