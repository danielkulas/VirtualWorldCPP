#pragma once
#include "World.h"
#include "Animal.h"


class Turtle : public Animal
{
public:
	Turtle(World &world);
	void draw() override;
	void action() override;
	bool defense(Organism* organism) override;
	Organism* getObject() override;
};