#pragma once
#define _CRT_NONSTDC_NO_DEPRECATE
#include <conio.h>
#include <cstdlib>
#include "World.h"
#include "Animal.h"


class Human : public Animal
{
private:
	bool alsuraShield;
	int specialSkillCounter;
	void specialSkill();

public:
	Human(World &world);
	void draw() override;
	void action() override;
	void setAlsuraShield(bool sentence);
	void setSpecialSkillCounter(int counter);
	int getSpecialSkillCounter();
	bool defense(Organism* organism) override;
	Organism* getObject() override;
};