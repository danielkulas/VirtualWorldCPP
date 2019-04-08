#include "Organism.h"

Organism::Organism()
{

}

void Organism::setXPosition(int x)
{
	xPosition = x;
}

void Organism::setYPosition(int y)
{
	yPosition = y;
}

void Organism::setAge(int age)
{
	(*this).age = age;
}

void Organism::setInitiative(int initiative)
{
	(*this).initiative = initiative;
}

void Organism::setForce(int force)
{
	(*this).force = force;
}

int Organism::getXPosition()
{
	return xPosition;
}

int Organism::getYPosition()
{
	return yPosition;
}

int Organism::getAge()
{
	return age;
}

int Organism::getForce()
{
	return force;
}

string Organism::getName()
{
	return name;
}

int Organism::getInitiative()
{
	return initiative;
}

bool Organism::defense(Organism* organism)
{
	return false;
}

Organism::~Organism()
{

}