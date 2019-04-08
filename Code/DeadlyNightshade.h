#pragma once
#include "World.h"
#include "Plant.h"


class DeadlyNightshade : public Plant
{
public:
	DeadlyNightshade(World &world);
	DeadlyNightshade(World &world, int x, int y);
	void draw() override;
	void collision() override;
	Organism* getObject() override;
};