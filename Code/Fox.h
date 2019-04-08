#pragma once
#include "World.h"
#include "Animal.h"


class Fox : public Animal
{
public:
	Fox(World &world);
	void draw() override;
	void action() override;
	Organism* getObject() override;
};