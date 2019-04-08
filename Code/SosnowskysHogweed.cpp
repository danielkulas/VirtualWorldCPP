#include "SosnowskysHogweed.h"


SosnowskyHogweed::SosnowskyHogweed(World &world)
{
	int xGameSize = world.getXGameSize();
	int yGameSize = world.getYGameSize();
	setXPosition(rand() % xGameSize + 1);
	setYPosition(rand() % yGameSize + 1);
	force = 10;
	initiative = 0;
	age = 1;
	name = "SosnowskyHogweed";
	(*this).world = &world;
}

SosnowskyHogweed::SosnowskyHogweed(World &world, int x, int y)
{
	setXPosition(x);
	setYPosition(y);
	force = 10;
	initiative = 0;
	age = 1;
	(*this).world = &world;
}

void SosnowskyHogweed::draw()
{
	int x0 = GAME_X_POSITION;
	int y0 = GAME_Y_POSITION;
	World::gotoxy(x0 + getXPosition(), y0 + getYPosition());
	cout << "b";
}

void SosnowskyHogweed::action()
{
	Plant::action();

	for (int i = 0; i < world->organism.size(); i++)
	{
		//Sprawdzanie czy w poblizu barszczu sosnowskiego znajduje sie jakies zwierze
		if ((world->organism[i]->getXPosition() == getXPosition() && (world->organism[i]->getYPosition() == getYPosition() - 1 || world->organism[i]->getYPosition() == getYPosition() + 1) && dynamic_cast<Animal*>(world->organism[i])) || (world->organism[i]->getYPosition() == getYPosition() && (world->organism[i]->getXPosition() == getXPosition() - 1 || world->organism[i]->getXPosition() == getXPosition() + 1) && dynamic_cast<Animal*>(world->organism[i])))
		{
			world->setInfo("Barszcz s zabija: " + world->organism[i]->getName());
			world->organism[i] = world->organism[world->organism.size() - 1];
			world->organism.pop_back();
		}
	}
}

void SosnowskyHogweed::collision()
{
	for (int i = 0; i < world->organism.size(); i++)
	{
		if (getXPosition() == world->organism[i]->getXPosition() && getYPosition() == world->organism[i]->getYPosition() && world->organism[i] != this)
		{
			world->setInfo("Barszcz s zabija: " + world->organism[i]->getName());
			world->organism[i] = world->organism[world->organism.size() - 1];
			world->organism.pop_back();
		}
	}
}

Organism* SosnowskyHogweed::getObject()
{
	return new SosnowskyHogweed(*world);
}