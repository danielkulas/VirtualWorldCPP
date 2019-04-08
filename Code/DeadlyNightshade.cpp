#include "DeadlyNightshade.h"


DeadlyNightshade::DeadlyNightshade(World &world)
{
	int xGameSize = world.getXGameSize();
	int yGameSize = world.getYGameSize();
	setXPosition(rand() % xGameSize + 1);
	setYPosition(rand() % yGameSize + 1);
	force = 99; 
	initiative = 0;
	age = 1;
	name = "DeadlyNightshade";
	(*this).world = &world;
}

DeadlyNightshade::DeadlyNightshade(World &world, int x, int y)
{
	setXPosition(x);
	setYPosition(y);
	force = 99;
	initiative = 0;
	age = 1;
	(*this).world = &world;
}

void DeadlyNightshade::draw()
{
	int x0 = GAME_X_POSITION;
	int y0 = GAME_Y_POSITION;
	World::gotoxy(x0 + getXPosition(), y0 + getYPosition());
	cout << "j";
}

void DeadlyNightshade::collision()
{
	for (int i = 0; i < world->organism.size(); i++)
	{
		if (getXPosition() == world->organism[i]->getXPosition() && getYPosition() == world->organism[i]->getYPosition() && world->organism[i] != this)
		{
			world->setInfo("Wilcze j zabijaja: " + world->organism[i]->getName());
			world->organism[i] = world->organism[world->organism.size() - 1];
			world->organism.pop_back();
		}
	}
}

Organism* DeadlyNightshade::getObject()
{
	return new DeadlyNightshade(*world);
}