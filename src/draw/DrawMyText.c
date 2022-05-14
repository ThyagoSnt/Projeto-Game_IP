#include "../../include/game.h"

void DrawMyText(SetGame set){
		//TEXTO DE TESTE GAMEPLAY
	if(set.map == 0){
		DrawText("GAMEPLAY SCREEN", 50, 120, 40, BLACK);
		DrawText("PRESS ESC TO MENU SCREEN", 50, 160, 20, BLACK);
		DrawText("PRESS F11 TO FULL SCREEN MODE", 850, 160, 20, BLACK);
	}
	else if(set.map == 1){
		DrawText("GAMEPLAY SCREEN", 50, 120, 40, WHITE);
		DrawText("PRESS ESC TO MENU SCREEN", 50, 160, 20, WHITE);
		DrawText("PRESS F11 TO FULL SCREEN MODE", 850, 160, 20, WHITE);
	}
}
