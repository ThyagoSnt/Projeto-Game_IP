#include "../../include/game.h"

void EnvironmentMechanic(Background *background,SetGame *set)
{
	if (background->back <= -background->backg[set->map].width*4)
		background->back = 0;
	if (background->mid <= -background->midg[set->map].width*4)
		background->mid = 0;
	if (background->fore <= -background->foreg[set->map].width*4)
		background->fore = 0;
	if (background->floor <= -background->floorg[set->map].width*4)
	background->floor = 0;
}
