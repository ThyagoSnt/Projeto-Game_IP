#include "../../include/game.h"

<<<<<<< HEAD
void DrawEnvironment(Background background, SetGame set){ //CENARIOS DO FUNDO

	DrawTextureEx(background.mapa, (Vector2){ background.scroll, 20 }, 0.0f, 3.0f, WHITE);
	DrawTextureEx(background.mapa, (Vector2){ background.mapa.width*3 + background.scroll, - 20 }, 0.0f, 3.0f, WHITE);

	DrawRectangle(background.mapa.width, 608, 200, 100, YELLOW);
}
=======
void DrawEnvironment(Background background, SetGame set){
	//CENARIOS DO FUNDO
	DrawTextureEx(background.backg[set.map], (Vector2){ background.back, 40 }, 0.0f, 4.0f, WHITE);
	DrawTextureEx(background.backg[set.map], (Vector2){ background.backg[set.map].width*4 + background.back, 40 }, 0.0f, 4.0f, WHITE);
	//CENARIOS DO MEIO
	DrawTextureEx(background.midg[set.map], (Vector2){ background.mid, 40 }, 0.0f, 4.0f, WHITE);
	DrawTextureEx(background.midg[set.map], (Vector2){ background.midg[set.map].width*4 + background.mid, 40 }, 0.0f, 4.0f, WHITE);
	//CENARIOS DA FRENTE
	DrawTextureEx(background.foreg[set.map], (Vector2){ background.fore, 40 }, 0.0f, 4.0f, WHITE);
	DrawTextureEx(background.foreg[set.map], (Vector2){ background.foreg[set.map].width*4 + background.fore, 40 }, 0.0f, 4.0f, WHITE);
	//FLOOR
	DrawTextureEx(background.floorg[set.map], (Vector2){ background.floor, 57 }, 0.0f, 3.0f, WHITE);
	DrawTextureEx(background.floorg[set.map], (Vector2){ background.floorg[set.map].width*3 + background.floor, - 57 }, 0.0f, 3.0f, WHITE);
}
>>>>>>> 52aa243e51b90f149a3bbf7018daa25b16df96d6
