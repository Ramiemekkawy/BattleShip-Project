/*#include "Highscores.h"
#include <iostream>
#include "Menu.h"
#include <fstream>
#include <vector>
using namespace std;
using namespace sf;

Highscores :: Highscores() //constructor 
{
	screenDimension= Vector2i(400,300);
	High_window.create(VideoMode(screenDimension.x,screenDimension.y), "Highscores");
	f1="Highscores.txt";
	for (int i=0;i<10;i++) //Loop to insert in vector
	{
		ifstream f2;
		f2.open(f1);
		if (f2.fail()) //Temporary Testing
		{
			cerr<<"Fail to read from Highscore save file";
		}
		f2>>V[i].name;
		f2>>V[i].score;
	}
}
void Highscores :: display_scores()
{
	for (int i=0;i<10;i++) //Loop to display
		cout<<i<<"   "<<V[i].name<<"   "<<V[i].score;
}
void Highscores :: check_score(int num1)
{
	string s1;
	for (int i=1;i<10;i++)
	{
		if(num1>V[i].score)
		{
			cout<<"New Highscore!"<<endl;
			cout<<"Please Enter Name:"<<endl;
			cin>>s1;
			save_score(s1,num1,i);
		}
	}
}
void Highscores :: save_score(string s1,int num,int i)
{
	V[i].name=s1;
	V[i].score=num;
}
Highscores:: ~Highscores()
{
	ofstream f2;
	f2.open(f1);
	for(int i=0;i<10;i++)
	{
		f2<<V[i].name;
		f2<<' ';
		f2<<V[i].score;
		f2<<'/n';
	}
}*/