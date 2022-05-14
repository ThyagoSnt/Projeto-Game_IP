#include "../../include/game.h"

void EnvironmentMechanic(Background *background,SetGame *set){
	if (background->scroll <= -background->mapa.width*4)
		background->scroll = 0;
}
