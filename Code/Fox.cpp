#include "Fox.h"


Fox::Fox(World &world)
{
	int xGameSize = world.getXGameSize();
	int yGameSize = world.getYGameSize();
	setXPosition(rand() % xGameSize + 1);
	setYPosition(rand() % yGameSize + 1);
	force = 3;
	initiative = 7;
	age = 1;
	name = "Fox";
	(*this).world = &world;
}

void Fox::draw()
{
	int x0 = GAME_X_POSITION;
	int y0 = GAME_Y_POSITION;
	World::gotoxy(x0 + getXPosition(), y0 + getYPosition());
	cout << "L";
}

void Fox::action()
{
	int flag = 0, iteration = 0;
	int prevXPos = getXPosition();
	int prevYPos = getYPosition();

	do {
		double random = rand() % 100 + 1;
		iteration++;

		if (random <= 25 && getXPosition() > 1)
		{
			setXPosition(getXPosition() - 1);
			flag = 1;
		}
		else if (random > 25 && random <= 50 && getXPosition() < world->getXGameSize())
		{
			setXPosition(getXPosition() + 1);
			flag = 1;
		}
		else if (random > 50 && random <= 75 && getYPosition() > 1)
		{
			setYPosition(getYPosition() - 1);
			flag = 1;
		}
		else if (random > 75 && getYPosition() < world->getYGameSize())
		{
			setYPosition(getYPosition() + 1);
			flag = 1;
		}

		for (int i = 0; i < world->organism.size(); i++)
		{
			if (getXPosition() == world->organism[i]->getXPosition() && getYPosition() == world->organism[i]->getYPosition() && world->organism[i]->getForce() > getForce() && world->organism[i] != this)
			{
				flag = 0;
				setXPosition(prevXPos);
				setYPosition(prevYPos);
			}
		}

		if (iteration > 100)
			break;

	} while (flag = 0);
}

Organism* Fox::getObject()
{
	return new Fox(*world);
}