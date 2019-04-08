#pragma once
#include "Organism.h"


class Plant : public Organism
{
public:
	void action() override;
	void collision() override;
};