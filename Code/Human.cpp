#include "Human.h"


Human::Human(World &world)
{
	int xGameSize = world.getXGameSize();
	int yGameSize = world.getYGameSize();
	setXPosition(rand() % xGameSize + 1);
	setYPosition(rand() % yGameSize + 1);
	force = 5;
	initiative = 4;
	age = 1;
	specialSkillCounter = 0;
	alsuraShield = false;
	name = "Human";
	(*this).world = &world;
}

void Human::draw()
{
	int x0 = GAME_X_POSITION;
	int y0 = GAME_Y_POSITION;
	World::gotoxy(x0 + getXPosition(), y0 + getYPosition());
	cout << "C";
}

void Human::action()
{
	char input = NULL;
	
	do
	{
		input = getch();
		if (input == 'a' && getXPosition() > 1)
		{
			setXPosition(getXPosition() - 1);
			break;
		}
		else if (input == 'd' && getXPosition() < world->getXGameSize())
		{
			setXPosition(getXPosition() + 1);
			break;
		}
		else if (input == 'w' && getYPosition() > 1)
		{
			setYPosition(getYPosition() - 1);
			break;
		}
		else if (input == 's' && getYPosition() < world->getYGameSize())
		{
			setYPosition(getYPosition() + 1);
			break;
		}
		else if (input == 'q')
		{
			exit(1);
		}
		else if (input == 'p')
		{
			if(getSpecialSkillCounter() >= 5)
				specialSkill();
		}
		else if (input == 'i')
		{
			world->save();
		}
		else if (input == 'o')
		{
			world->load();
			break;
		}
	} while (true);

	setSpecialSkillCounter(getSpecialSkillCounter() + 1);
	if (getSpecialSkillCounter() == 0)
	{
		alsuraShield = false;
		world->setAlsureInfo("wylaczona");
	}
}

void Human::setSpecialSkillCounter(int counter)
{
	specialSkillCounter = counter;
}

void Human::setAlsuraShield(bool sentence)
{
	alsuraShield = sentence;
}

int Human::getSpecialSkillCounter()
{
	return specialSkillCounter;
}

void Human::specialSkill()
{
	setSpecialSkillCounter(-5);
	alsuraShield = true;
	world->setAlsureInfo("wlaczona");
}

bool Human::defense(Organism* organism)
{
	return alsuraShield;
}

Organism* Human::getObject()
{
	return new Human(*world);
}