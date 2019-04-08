#include "Guarana.h"


Guarana::Guarana(World &world)
{
	int xGameSize = world.getXGameSize();
	int yGameSize = world.getYGameSize();
	setXPosition(rand() % xGameSize + 1);
	setYPosition(rand() % yGameSize + 1);
	force = 0;
	initiative = 0;
	age = 1;
	name = "Guarana";
	(*this).world = &world;
}

Guarana::Guarana(World &world, int x, int y)
{
	setXPosition(x);
	setYPosition(y);
	force = 0;
	initiative = 0;
	age = 1;
	(*this).world = &world;
}

void Guarana::draw()
{
	int x0 = GAME_X_POSITION;
	int y0 = GAME_Y_POSITION;
	World::gotoxy(x0 + getXPosition(), y0 + getYPosition());
	cout << "g";
}

void Guarana::collision()
{
	for (int i = 0; i < world->organism.size(); i++)
	{
		if (getXPosition() == world->organism[i]->getXPosition() && getYPosition() == world->organism[i]->getYPosition() && world->organism[i] != this)
		{
			world->setInfo("Guarana dodaje 3pkt sily do: " + world->organism[i]->getName());
			world->organism[i]->setForce(world->organism[i]->getForce() + 3);
		}
	}
}

Organism* Guarana::getObject()
{
	return new Guarana(*world);
}