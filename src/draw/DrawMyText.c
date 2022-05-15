#include "../../include/game.h"

void DrawMyText(SetGame set){
	//TEXTO DE TESTE GAMEPLAY
	if(set.final == 1){
		DrawText("Press Enter", set.finalVet.x, set.finalVet.y-100, 20, WHITE);
	}
}
