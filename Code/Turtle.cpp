#include "Turtle.h"


Turtle::Turtle(World &world)
{
	int xGameSize = world.getXGameSize();
	int yGameSize = world.getYGameSize();
	setXPosition(rand() % xGameSize + 1);
	setYPosition(rand() % yGameSize + 1);
	force = 2;
	initiative = 1;
	age = 1;
	name = "Turtle";
	(*this).world = &world;
}

void Turtle::draw()
{
	int x0 = GAME_X_POSITION;
	int y0 = GAME_Y_POSITION;
	World::gotoxy(x0 + getXPosition(), y0 + getYPosition());
	cout << "Z";
}

void Turtle::action()
{
	double random = rand() % 100 + 1;

	if (random >= 75)
		Animal::action();
}

bool Turtle::defense(Organism* organism)
{
	if (organism->getForce() < 5)
		return true;

	return false;
}

Organism* Turtle::getObject()
{
	return new Turtle(*world);
}