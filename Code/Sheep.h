#pragma once
#include "World.h"
#include "Animal.h"


class Sheep : public Animal
{
public:
	Sheep(World &world);
	void draw() override;
	Organism* getObject() override;
};