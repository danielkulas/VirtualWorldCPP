#define _CRT_NONSTDC_NO_DEPRECATE
#include <conio.h>
#include "World.h"
using namespace std;

int main()
{
	char input = NULL;
	World world;
	while (true)
	{
		world.makeTurn();
	}
	return 0;
}