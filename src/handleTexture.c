#include "../include/game.h"

void LoadAllTexture(Person *persona, Heart *life,Background *background, Menu *menu, SetGame *set, Fantext *fantxt){ //CARREGANDO AS TEXTURAS
	//PERSONAGEM
	persona->personRight = LoadTexture("../assets/personagem/scarfy.png");
	persona->personLeft = LoadTexture("../assets/personagem/scarfy_2.png");
	persona->personStopRight = LoadTexture("../assets/personagem/stop.png");
	persona->personStopLeft = LoadTexture("../assets/personagem/stopLeft.png");

	//GUI
	life->heartFull = LoadTexture("../assets/gui/Heart1.png");
	life->heartEmpty = LoadTexture("../assets/gui/Heart2.png");

	//TELAS DE FUNDO
	background->back[0] = LoadTexture("../assets/background/background1.png");
	background->mid[0] = LoadTexture("../assets/background/midground1.png");
	background->fore[0] = LoadTexture("../assets/background/foreground1.png");
	background->back[1] = LoadTexture("../assets/background/background2.png");
	background->mid[1] = LoadTexture("../assets/background/midground2.png");
	background->fore[1] = LoadTexture("../assets/background/foreground2.png");
	menu->background = LoadTexture("../assets/background/title_game.png");

	//FANATICO
	fantxt->walk_right = LoadTexture("../assets/Fanatico/walk_right.png");
	fantxt->walk_left = LoadTexture("../assets/Fanatico/walk_left.png");
	fantxt->stop_right = LoadTexture("../assets/Fanatico/stop_right.png");
	fantxt->stop_left = LoadTexture("../assets/Fanatico/stop_left.png");
}

void UnloadAllTexture(Person *persona, Heart *life,Background *background, Menu *menu, SetGame *set, Fantext *fantext){
	//DESCARREGANDO AS TEXTURAS
	UnloadTexture(background->back[0]);
	UnloadTexture(background->mid[0]);
	UnloadTexture(background->fore[0]);
	UnloadTexture(background->back[1]);
	UnloadTexture(background->mid[1]);
	UnloadTexture(background->fore[1]);
	UnloadTexture(persona->personRight);
	UnloadTexture(persona->personLeft);
	UnloadTexture(fantext->walk_right);
	UnloadTexture(fantext->walk_left);
	UnloadTexture(fantext->stop_right);
	UnloadTexture(fantext->stop_left);
	UnloadTexture(life->heartFull);
	UnloadTexture(life->heartEmpty);
}