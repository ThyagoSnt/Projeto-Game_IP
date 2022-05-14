#include "../../include/game.h"

void DrawMyText(SetGame set){
	//TEXTO DE TESTE GAMEPLAY
	if(set.final == 1){
		DrawText("Press Enter", set.finalVet.x-10, set.finalVet.y-100, 10, WHITE);
	}
}