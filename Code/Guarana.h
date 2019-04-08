#pragma once
#include "World.h"
#include "Plant.h"


class Guarana : public Plant
{
public:
	Guarana(World &world);
	Guarana(World &world, int x, int y);
	void draw() override;
	void collision() override;
	Organism* getObject() override;
};