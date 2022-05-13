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
	life->portion = LoadTexture("../assets/gui/portion.png");
	life->veneno = LoadTexture("../assets/gui/veneno.png");

	//Plataforma
	plataforma->plataform = LoadTexture("../assets/img_teste/plat.png");

	//TELAS DE FUNDO
	background->backg[0] = LoadTexture("../assets/background/background1.png");
	background->midg[0] = LoadTexture("../assets/background/midground1.png");
	background->foreg[0] = LoadTexture("../assets/background/foreground1.png");
	background->backg[1] = LoadTexture("../assets/background/background2.png");
	background->midg[1] = LoadTexture("../assets/background/midground2.png");
	background->foreg[1] = LoadTexture("../assets/background/foreground2.png");
	background->floorg[0] = LoadTexture("../assets/background/floor1.png");
	background->floorg[1] = LoadTexture("../assets/background/floor1.png");

	menu->background = LoadTexture("../assets/background/title_game.png");
	menu->title = LoadTexture("../assets/background/title.png");

	//FANATICO
	fanatico->walk_right = LoadTexture("../assets/inimigos/Fanatico/walk_right.png");
	fanatico->walk_left = LoadTexture("../assets/inimigos/Fanatico/walk_left.png");
	fanatico->idle_right = LoadTexture("../assets/inimigos/Fanatico/idle_right.png");
	fanatico->idle_left = LoadTexture("../assets/inimigos/Fanatico/idle_left.png");
	fanatico->atack_right = LoadTexture("../assets/inimigos/Fanatico/atack_right.png");
	fanatico->atack_left = LoadTexture("../assets/inimigos/Fanatico/atack_left.png");
	fanatico->die_right = LoadTexture("../assets/inimigos/Fanatico/die_right.png");
	fanatico->die_left = LoadTexture("../assets/inimigos/Fanatico/die_left.png");
}

void UnloadAllTexture(Player *player, Heart *life,Background *background,Plataform *plataforma, Menu *menu, SetGame *set, Fanatico *fanatico){
	//DESCARREGANDO AS TEXTURAS
	UnloadTexture(background->backg[0]);
	UnloadTexture(background->midg[0]);
	UnloadTexture(background->foreg[0]);
	UnloadTexture(background->backg[1]);
	UnloadTexture(background->midg[1]);
	UnloadTexture(background->foreg[1]);
	UnloadTexture(background->floorg[0]);
	UnloadTexture(background->floorg[1]);

	UnloadTexture(menu->background);
	UnloadTexture(menu->title);

	UnloadTexture(plataforma->plataform);
	UnloadTexture(player->personRight);
	UnloadTexture(player->personLeft);
	UnloadTexture(player->personStopRight);
	UnloadTexture(player->personStopLeft);

	UnloadTexture(fanatico->walk_right);
	UnloadTexture(fanatico->walk_left);
	UnloadTexture(fanatico->idle_right);
	UnloadTexture(fanatico->idle_left);
	UnloadTexture(fanatico->atack_right);
	UnloadTexture(fanatico->atack_left);
	UnloadTexture(fanatico->die_right);
	UnloadTexture(fanatico->die_left);

	UnloadTexture(life->heartFull);
	UnloadTexture(life->heartEmpty);
}
