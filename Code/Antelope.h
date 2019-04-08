#pragma once
#include "World.h"
#include "Animal.h"


class Antelope : public Animal
{
public:
	Antelope(World &world);
	void draw() override;
	void action() override;
	bool defense(Organism* organism);
	Organism* getObject() override;
};