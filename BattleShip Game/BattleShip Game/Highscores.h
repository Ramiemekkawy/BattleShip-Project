/*#ifndef Highscores_h;
#define Highscores_h;

#include <vector>
#include <string>
#include "Menu.h"
#include <SFML/Graphics.hpp>
using namespace std;

class Highscores
{
public:
	Highscores(); //Constructor
	void display_scores(); //Displays the score
	void check_score(int); //Checks the score
	~Highscores();
private:
	Event event;
	Vector2i screenDimension;
	struct scores //struct for the scores
	{
		string name;
		int score;
	};
	vector <scores> V; //Vector to store the highscores
	string f1; //String for filename
	RenderWindow High_window; //The Window
	void save_score(string, int, int); //Saves Score
};
#endif*/