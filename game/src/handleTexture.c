#include "../include/game.h"

void UnloadAllTexture(Person *persona, Heart *life,Background *background, Menu *menu)
{
	UnloadTexture(background->back);
	UnloadTexture(background->mid);
	UnloadTexture(background->fore);
	UnloadTexture(persona->personRight);
	UnloadTexture(persona->personLeft);
	UnloadTexture(life->heartFull);
	UnloadTexture(life->heartEmpty);
}

void LoadAllTexture(Person *persona, Heart *life,Background *background, Menu *menu)
{
	//CARREGANDO ASS TEXTURAS
	persona->personRight = LoadTexture("assets/personagem/scarfy.png");
	persona->personLeft = LoadTexture("assets/personagem/scarfy_2.png");
	persona->personStopRight = LoadTexture("assets/personagem/stop.png");
	persona->personStopLeft = LoadTexture("assets/personagem/stopLeft.png");
	life->heartFull = LoadTexture("assets/gui/Heart1.png");
	life->heartEmpty = LoadTexture("assets/gui/Heart2.png");
	background->back = LoadTexture("assets/background/background_layer_1.png");
	background->mid = LoadTexture("assets/background/background_layer_2.png");
	background->fore= LoadTexture("assets/background/background_layer_3.png");
	menu->background = LoadTexture("assets/title_game.png");
}
