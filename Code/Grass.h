#pragma once
#include "World.h"
#include "Plant.h"


class Grass : public Plant
{
public:
	Grass(World &world);
	Grass(World &world, int x, int y);
	void draw() override;
	Organism* getObject() override;
};