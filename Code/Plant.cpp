#include "Plant.h"
#include "World.h"


void Plant::action()
{
	double random = rand() % 1000 + 1;

	if (random <= SPREAD_PROBABILITY)
	{
		random = rand() % 100 + 1;
		world->organism.push_back((*this).getObject());
		int k = world->organism.size() - 1;

		if (random <= 25 && getXPosition() - 1 > 1)
		{
			world->organism[k]->setXPosition(getXPosition() - 1);
			world->organism[k]->setYPosition(getYPosition());
		}
		else if (random > 25 && random <= 50 && getXPosition() + 1 < world->getXGameSize())
		{
			world->organism[k]->setXPosition(getXPosition() + 1);
			world->organism[k]->setYPosition(getYPosition());
		}
		else if (random > 50 && random <= 75 && getYPosition() - 1 > 1)
		{
			world->organism[k]->setXPosition(getXPosition());
			world->organism[k]->setYPosition(getYPosition() - 1);
		}
		else if (random > 75 && getYPosition() + 1 < world->getYGameSize())
		{
			world->organism[k]->setXPosition(getXPosition());
			world->organism[k]->setYPosition(getYPosition() + 1);
		}

		for (int i = 0; i < k; i++)
		{
			if (world->organism[i]->getXPosition() == world->organism[k]->getXPosition() && world->organism[i]->getYPosition() == world->organism[k]->getYPosition())
			{
				world->organism.pop_back();
				break;
			}
			else
			{
				world->setInfo("Rozp: " + world->organism[k]->getName());
			}
		}
	}
}

void Plant::collision(){
}