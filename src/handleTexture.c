#include "../include/game.h"

void LoadAllTexture(Player *player, Heart *life,Background *background,Plataform *plataforma,Menu *menu, SetGame *set, Fanatico *fanatico){ //CARREGANDO AS TEXTURAS
	//PERSONAGEM
	player->personRight = LoadTexture("../assets/personagem/scarfy.png");
	player->personLeft = LoadTexture("../assets/personagem/scarfy_2.png");
	player->personStopRight = LoadTexture("../assets/personagem/stop.png");
	player->personStopLeft = LoadTexture("../assets/personagem/stopLeft.png");

	//GUI
	life->heartFull = LoadTexture("../assets/gui/Heart1.png");
	life->heartEmpty = LoadTexture("../assets/gui/Heart2.png");

	//Plataforma
	plataforma->plataform = LoadTexture("../assets/img_teste/plat.png");

	//TELAS DE FUNDO
	background->backg[0] = LoadTexture("../assets/background/background1.png");
	background->midg[0] = LoadTexture("../assets/background/midground1.png");
	background->foreg[0] = LoadTexture("../assets/background/foreground1.png");
	background->backg[1] = LoadTexture("../assets/background/background2.png");
	background->midg[1] = LoadTexture("../assets/background/midground2.png");
	background->foreg[1] = LoadTexture("../assets/background/foreground2.png");
	menu->background = LoadTexture("../assets/background/title_game.png");

	//FANATICO
	fanatico->walk_right = LoadTexture("../assets/inimigos/Fanatico/walk_right.png");
	fanatico->walk_left = LoadTexture("../assets/inimigos/Fanatico/walk_left.png");
	fanatico->stop_right = LoadTexture("../assets/inimigos/Fanatico/stop_right.png");
	fanatico->stop_left = LoadTexture("../assets/inimigos/Fanatico/stop_left.png");
}

void UnloadAllTexture(Player *player, Heart *life,Background *background,Plataform *plataforma, Menu *menu, SetGame *set, Fanatico *fanatico){
	//DESCARREGANDO AS TEXTURAS
	UnloadTexture(background->backg[0]);
	UnloadTexture(background->midg[0]);
	UnloadTexture(background->foreg[0]);
	UnloadTexture(background->backg[1]);
	UnloadTexture(background->midg[1]);
	UnloadTexture(background->foreg[1]);

	UnloadTexture(plataforma->plataform);
	UnloadTexture(player->personRight);
	UnloadTexture(player->personLeft);
	UnloadTexture(player->personStopRight);
	UnloadTexture(player->personStopLeft);

	UnloadTexture(fanatico->walk_right);
	UnloadTexture(fanatico->walk_left);
	UnloadTexture(fanatico->stop_right);
	UnloadTexture(fanatico->stop_left);

	UnloadTexture(life->heartFull);
	UnloadTexture(life->heartEmpty);
}
