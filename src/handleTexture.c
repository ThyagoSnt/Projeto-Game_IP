#include "../include/game.h"

void LoadAllTexture(Player *player, Heart *life,Background *background, Menu *menu, SetGame *set, Fanatico *fanatico, Goblin *goblin, Cogumelo *cogumelo, Olho *olho){ //CARREGANDO AS TEXTURAS
	//PERSONAGEM
	player->personRight = LoadTexture("../assets/personagem/scarfy.png");
	player->personLeft = LoadTexture("../assets/personagem/scarfy_2.png");
	player->personStopRight = LoadTexture("../assets/personagem/stop.png");
	player->personStopLeft = LoadTexture("../assets/personagem/stopLeft.png");

	//GUI
	life->heartFull = LoadTexture("../assets/gui/Heart1.png");
	life->heartEmpty = LoadTexture("../assets/gui/Heart2.png");

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

	//GOBLIN
	goblin->walk_right = LoadTexture("../assets/inimigos/Goblin/run_right.png");
	goblin->walk_left = LoadTexture("../assets/inimigos/Goblin/run_left.png");
	goblin->stop_right = LoadTexture("../assets/inimigos/Goblin/idle_right.png");
	goblin->stop_left = LoadTexture("../assets/inimigos/Goblin/idle_left.png");

	//COGUMELO
	cogumelo->walk_right = LoadTexture("../assets/inimigos/Cogumelo/run_right.png");
	cogumelo->walk_left = LoadTexture("../assets/inimigos/Cogumelo/run_left.png");
	cogumelo->stop_right = LoadTexture("../assets/inimigos/Cogumelo/idle_right.png");
	cogumelo->stop_left = LoadTexture("../assets/inimigos/Cogumelo/idle_left.png");

	//OLHO
	olho->walk_right = LoadTexture("../assets/inimigos/Olho/run_right.png");
	olho->walk_left = LoadTexture("../assets/inimigos/Olho/run_left.png");
	olho->stop_right = LoadTexture("../assets/inimigos/Olho/idle_right.png");
	olho->stop_left = LoadTexture("../assets/inimigos/Olho/idle_left.png");
}

void UnloadAllTexture(Player *player, Heart *life,Background *background, Menu *menu, SetGame *set, Fanatico *fanatico, Goblin *goblin, Cogumelo *cogumelo, Olho *olho){
	//DESCARREGANDO AS TEXTURAS
	UnloadTexture(background->backg[0]);
	UnloadTexture(background->midg[0]);
	UnloadTexture(background->foreg[0]);
	UnloadTexture(background->backg[1]);
	UnloadTexture(background->midg[1]);
	UnloadTexture(background->foreg[1]);

	UnloadTexture(player->personRight);
	UnloadTexture(player->personLeft);
	UnloadTexture(player->personStopRight);
	UnloadTexture(player->personStopLeft);

	UnloadTexture(fanatico->walk_right);
	UnloadTexture(fanatico->walk_left);
	UnloadTexture(fanatico->stop_right);
	UnloadTexture(fanatico->stop_left);

	UnloadTexture(goblin->walk_right);
	UnloadTexture(goblin->walk_left);
	UnloadTexture(goblin->stop_right);
	UnloadTexture(goblin->stop_left);

	UnloadTexture(cogumelo->walk_right);
	UnloadTexture(cogumelo->walk_left);
	UnloadTexture(cogumelo->stop_right);
	UnloadTexture(cogumelo->stop_left);

	UnloadTexture(olho->walk_right);
	UnloadTexture(olho->walk_left);
	UnloadTexture(olho->stop_right);
	UnloadTexture(olho->stop_left);

	UnloadTexture(life->heartFull);
	UnloadTexture(life->heartEmpty);
}