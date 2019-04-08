#include "Antelope.h"


Antelope::Antelope(World &world)
{
	int xGameSize = world.getXGameSize();
	int yGameSize = world.getYGameSize();
	setXPosition(rand() % xGameSize + 1);
	setYPosition(rand() % yGameSize + 1);
	force = 4;
	initiative = 4;
	age = 1;
	name = "Antelope";
	(*this).world = &world;
}

void Antelope::draw()
{
	int x0 = GAME_X_POSITION;
	int y0 = GAME_Y_POSITION;
	World::gotoxy(x0 + getXPosition(), y0 + getYPosition());
	cout << "A";
}

void Antelope::action()
{
	for (int i = 0; i < 2; i++)
		Animal::action();
}

bool Antelope::defense(Organism* organism)
{
	double random = rand() % 100 + 1;
	if (random <= 50)
		return true;

	return false;
}

Organism* Antelope::getObject()
{
	return new Antelope(*world);
}