#pragma once
#include "World.h"
#include "Plant.h"


class SosnowskyHogweed : public Plant
{
public:
	SosnowskyHogweed(World &world);
	SosnowskyHogweed(World &world, int x, int y);
	void draw() override;
	void action() override;
	void collision() override;
	Organism* getObject() override;
};