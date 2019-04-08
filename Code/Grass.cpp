#include "Grass.h"


Grass::Grass(World &world)
{
	int xGameSize = world.getXGameSize();
	int yGameSize = world.getYGameSize();
	setXPosition(rand() % xGameSize + 1);
	setYPosition(rand() % yGameSize + 1);
	force = 0;
	initiative = 0;
	age = 1;
	name = "Grass";
	(*this).world = &world;
}

Grass::Grass(World &world, int x, int y)
{
	setXPosition(x);
	setYPosition(y);
	force = 0;
	initiative = 0;
	age = 1;
	(*this).world = &world;
}

void Grass::draw()
{
	int x0 = GAME_X_POSITION;
	int y0 = GAME_Y_POSITION;
	World::gotoxy(x0 + getXPosition(), y0 + getYPosition());
	cout << "t";
}

Organism* Grass::getObject()
{
	return new Grass(*world);
}