#pragma once
#include <string>
using namespace std;

class World;


class Organism
{
public:
	int xPosition;
	int yPosition;
	int age;
	int force;
	int initiative;
	string name;
	World *world;

public:
	Organism();
	virtual void setXPosition(int x);
	virtual void setYPosition(int y);
	virtual void setAge(int age);
	virtual void setInitiative(int initiative);
	virtual void setForce(int force);
	virtual int getXPosition();
	virtual int getYPosition();
	virtual int getAge();
	virtual int getInitiative();
	virtual int getForce();
	virtual string getName();
	virtual void action() = 0;
	virtual void collision() = 0;
	virtual void draw() = 0;
	virtual Organism* getObject() = 0;
	virtual bool defense(Organism* organism);
	virtual ~Organism();
};