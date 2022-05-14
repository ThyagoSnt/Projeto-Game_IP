#include "../../include/game.h"

void DrawEnvironment(Background background, SetGame set){ //CENARIOS DO FUNDO

	DrawTextureEx(background.mapa, (Vector2){ background.scroll, 20 }, 0.0f, 3.0f, WHITE);
	DrawTextureEx(background.mapa, (Vector2){ background.mapa.width*3 + background.scroll, - 20 }, 0.0f, 3.0f, WHITE);

<<<<<<< HEAD
	DrawRectangleLines(set.finalVet.x, set.finalVet.y, set.finalRec.width ,set.finalRec.height, WHITE);
}
=======
	DrawRectangle(background.mapa.width, 608, 200, 100, YELLOW);
}
>>>>>>> e4914df21c23672814fe681b62f313fcf9312f74
