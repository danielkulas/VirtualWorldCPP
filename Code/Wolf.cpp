#include "Wolf.h"


Wolf::Wolf(World &world)
{
	int xGameSize = world.getXGameSize();
	int yGameSize = world.getYGameSize();
	setXPosition(rand() % xGameSize + 1);
	setYPosition(rand() % yGameSize + 1);
	force = 9; 
	initiative = 5;
	age = 1;
	name = "Wolf";
	(*this).world = &world;
}

void Wolf::draw()
{
	int x0 = GAME_X_POSITION;
	int y0 = GAME_Y_POSITION;
	World::gotoxy(x0 + getXPosition(), y0 + getYPosition());
	cout << "W";
}

Organism* Wolf::getObject()
{
	return new Wolf(*world);
}