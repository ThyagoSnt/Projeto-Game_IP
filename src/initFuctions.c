#include "../include/game.h"

void InitVar(Background *background,Plataform *platafoma,SetGame *set,Player *player,Menu *menu, Fanatico *fanatico, Heart *life){

	//MECANICA DE ROLAGEM DE MAPA
	background->back = 0.0f;
	background->mid = 0.0f;
	background->fore = 0.0f;

	//MECANICAS DE MENU
	menu->start = 1;
	menu->inGame = 1;
	menu->exit = 1;

	//retangulo da porção
	life->portionRec.width = life->portion.width - 25;
	life->portionRec.height = life->portion.height - 25;
	life->getPortion = 1;
	life->venenoRec.width = life->veneno.width - 25;
	life->venenoRec.height = life->veneno.height - 25;
	//ATRIBUTOS PLATAFORMA
	platafoma->position = (Vector2){1200,600};
	platafoma->rec.width = platafoma->plataform.width;
	platafoma->rec.height = platafoma->plataform.height;

	//MECANICAS EXTRAS
	set->map = 0;
	set->time = 0.0f;
	set->framesCounter = 0;
	set->steps = 0;
	set->gameOver = 0;

	//ATRIBUTOS DO PLAYER
	player->stop = 1;
	player->canJump = 0;
	player->vida = 3;
	player->direction = 0;
	player->esperaHit = 0;
	player->characterRadius = 125;
	player->characterPosition = (Vector2){240, 628}; //POSICAO INICIAL DO PLAYER
	player->rec.width = player->personStopLeft.width - 100;
	player->rec.height = player->personStopLeft.height;

	//ATRIBUTOS DO FANATICO
	fanatico->damage = 3;
	fanatico->hp = 12;
	fanatico->direction = -1;
	fanatico->stop = 0;
	fanatico->enemyPosition = (Vector2){3350, 590};
	fanatico->rec.width = fanatico->stop_right.width;
	fanatico->rec.height = fanatico->stop_right.height;
	fanatico->rec.x = fanatico->enemyPosition.x;
	fanatico->rec.y = fanatico->enemyPosition.y; //POSICAO INICIAL DO FANATICO
}
