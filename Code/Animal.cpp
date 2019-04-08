#include "Animal.h"
#include "World.h"


void Animal::action()
{
	do {
		double random = rand() % 100 + 1;

		if (random <= 25 && getXPosition() > 1)
		{
			setXPosition(getXPosition() - 1);
			break;
		}
		else if (random > 25 && random <= 50 && getXPosition() < world->getXGameSize())
		{
			setXPosition(getXPosition() + 1);
			break;
		}
		else if (random > 50 && random <= 75 && getYPosition() > 1)
		{
			setYPosition(getYPosition() - 1);
			break;
		}
		else if (random > 75 && getYPosition() < world->getYGameSize())
		{
			setYPosition(getYPosition() + 1);
			break;
		}
	} while (true);
}

void Animal::moveToEmpty(Organism* organ)
{
	int flaga = 0;
	int size = world->getXGameSize();
	int arraySize = world->organism.size();
	if (world->getYGameSize() < world->getXGameSize())
		size = world->getYGameSize();

	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (j == 0)
			{
				if (organ->getXPosition() - i > 1)
				{
					organ->setXPosition(organ->getXPosition() - i);
					organ->setYPosition(organ->getYPosition());
				}
			}
			else if (j == 1)
			{
				if (organ->getXPosition() + i < world->getXGameSize())
				{
					organ->setXPosition(organ->getXPosition() + i);
					organ->setYPosition(organ->getYPosition());
				}
			}
			else if (j == 2)
			{
				if (organ->getYPosition() - i > 1)
				{
					organ->setXPosition(organ->getXPosition());
					organ->setYPosition(organ->getYPosition() - i);
				}
			}
			else if (j == 3)
			{
				if (organ->getYPosition() + i < world->getYGameSize())
				{
					organ->setXPosition(organ->getXPosition());
					organ->setYPosition(organ->getYPosition() + i);
				}
			}

			flaga = 0;
			for (int k = 0; k < arraySize; k++)
			{
				if (organ->getXPosition() == world->organism[k]->getXPosition() && organ->getYPosition() == world->organism[k]->getYPosition() && organ != world->organism[k])
				{
					flaga = 1;
				}
			}

			if (flaga == 0)
			{
				i = 64;
				j = 64;
				break;
			}
		}
	}
}

void Animal::collision()
{
	int j; //Identyfikator elementu w tablicy, ktory wchodzi w kolizje: j(ten), i(przeciwny)
	for (j = 0; j < world->organism.size(); j++)
	{
		if (world->organism[j] == this)
			break;
	}
	Organism* organ = world->organism[j];

	for (int i = 0; i < world->organism.size(); i++)
	{
		if (getXPosition() == world->organism[i]->getXPosition() && getYPosition() == world->organism[i]->getYPosition() && world->organism[i] != this)
		{
			//Rozmnazanie
			if(world->organism[j]->getName() == world->organism[i]->getName())
			{
				world->organism.push_back((*this).getObject());
				int size = world->organism.size();
				moveToEmpty(world->organism[j]);
				world->organism[size - 1]->setXPosition(getXPosition());
				world->organism[size - 1]->setYPosition(getYPosition());
				moveToEmpty(world->organism[size - 1]);
				if (world->organism[size - 1]->getXPosition() == getXPosition() && world->organism[size - 1]->getYPosition() == getYPosition())
					world->organism.pop_back();
				else
					world->setInfo("Rozmnazanie: " + getName());
				break;
			}

			//Kolizja
			if (dynamic_cast<Plant*>(world->organism[i]))
				world->organism[i]->collision();

			if (organ != world->organism[j])
				break;

			if (world->organism[i]->defense(this) == true)
			{
				world->setInfo("Obrona ataku przez: " + world->organism[i]->getName());
				moveToEmpty(world->organism[j]);
				break;
			}
			else if (getForce() > world->organism[i]->getForce())
			{
				world->setInfo(world->organism[j]->getName() + " zjada " + world->organism[i]->getName());
				world->organism[i] = world->organism[world->organism.size() - 1];
				world->organism.pop_back();
			}
			else if (getForce() == world->organism[i]->getForce())
			{
				if (j < i)
				{
					world->setInfo(world->organism[j]->getName() + " zjada " + world->organism[i]->getName());
					world->organism[i] = world->organism[world->organism.size() - 1];
					world->organism.pop_back();
				}
				else
				{
					world->setInfo(world->organism[i]->getName() + " zjada " + world->organism[j]->getName());
					world->organism[j] = world->organism[world->organism.size() - 1];
					world->organism.pop_back();
				}
			}
			else if (getForce() < world->organism[i]->getForce())
			{
				world->setInfo(world->organism[i]->getName() + " zjada " + world->organism[j]->getName());
				world->organism[j] = world->organism[world->organism.size() - 1];
				world->organism.pop_back();
			}
		}
	}
}