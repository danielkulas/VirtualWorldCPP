#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
#include <time.h>
#include "Organism.h"
#include "Human.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Grass.h"
#include "Dandelion.h"
#include "Guarana.h"
#include "DeadlyNightshade.h"
#include "SosnowskysHogweed.h"
using namespace std;

#define LEGEND_X_POSITION 1
#define LEGEND_Y_POSITION 1
#define GAME_X_POSITION 32
#define GAME_Y_POSITION 3
#define NUMBER_OF_ORGANISMS 1 //Organizmy na pocz¹tku rozgrywki, w '%' w stosunku do rozmiaru planszy
#define SPREAD_PROBABILITY 8 //Prawdopodobienstwo rozprzestrzeniania roslin, w '%o'
#define NUMBER_OF_ORGANISMS_TYPES 10 //Ilosc typow organizmow

class Organism;
class Human;
class Wolf;
class Sheep;
class Fox;
class Turtle;
class Antelope;
class Grass;
class Dandelion;
class Guarana;
class DeadlyNightshade;
class SosnowskysHogweed;

class World
{
private:
	int xGameSize;
	int yGameSize;
	int round;
	
	void setXGameSize(int x);
	void setYGameSize(int y);
	void setRound(int rd);
	void drawFrame(int sx, int sy);
	void drawLegend();
	void sortArray();
	void initialization();
	void checkTheEnd();
	string info;
	string alsureInfo;
	
public:
	vector<Organism*> organism;
	World();
	int getXGameSize();
	int getYGameSize();
	int getRound();
	void makeTurn();
	void save();
	void load();
	void setInfo(string info);
	void setAlsureInfo(string alsureInfo);
	void static gotoxy(int x, int y);
	~World();
};