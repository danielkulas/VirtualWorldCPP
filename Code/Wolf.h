#pragma once
#include "World.h"
#include "Animal.h"


class Wolf : public Animal
{
public:
	Wolf(World &world);
	void draw() override;
	Organism* getObject() override;
};