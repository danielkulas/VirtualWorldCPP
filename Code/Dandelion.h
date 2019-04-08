#pragma once
#include "World.h"
#include "Plant.h"


class Dandelion : public Plant
{
public:
	Dandelion(World &world);
	Dandelion(World &world, int x, int y);
	void action() override;
	void draw() override;
	Organism* getObject() override;
};