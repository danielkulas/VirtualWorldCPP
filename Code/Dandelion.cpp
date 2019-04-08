#include "Dandelion.h"


Dandelion::Dandelion(World &world)
{
	int xGameSize = world.getXGameSize();
	int yGameSize = world.getYGameSize();
	setXPosition(rand() % xGameSize + 1);
	setYPosition(rand() % yGameSize + 1);
	force = 0;
	initiative = 0;
	age = 1;
	name = "Dandelion";
	(*this).world = &world;
}

Dandelion::Dandelion(World &world, int x, int y)
{
	setXPosition(x);
	setYPosition(y);
	force = 0;
	initiative = 0;
	age = 1;
	(*this).world = &world;
}

void Dandelion::action()
{
	for (int i = 0; i < 3; i++)
		Plant::action();
}

void Dandelion::draw()
{
	int x0 = GAME_X_POSITION;
	int y0 = GAME_Y_POSITION;
	World::gotoxy(x0 + getXPosition(), y0 + getYPosition());
	cout << "m";
}

Organism* Dandelion::getObject()
{
	return new Dandelion(*world);
}