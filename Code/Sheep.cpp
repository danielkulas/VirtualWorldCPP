#include "Sheep.h"


Sheep::Sheep(World &world)
{
	int xGameSize = world.getXGameSize();
	int yGameSize = world.getYGameSize();
	setXPosition(rand() % xGameSize + 1);
	setYPosition(rand() % yGameSize + 1);
	force = 4;
	initiative = 4;
	age = 1;
	name = "Sheep";
	(*this).world = &world;
}

void Sheep::draw()
{
	int x0 = GAME_X_POSITION;
	int y0 = GAME_Y_POSITION;
	World::gotoxy(x0 + getXPosition(), y0 + getYPosition());
	cout << "O";
}

Organism* Sheep::getObject()
{
	return new Sheep(*world);
}