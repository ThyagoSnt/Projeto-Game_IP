#include "../include/game.h"

void InitVar(Background *background,Plataform *platafoma,SetGame *set,Player *player,Menu *menu, Fanatico *fanatico, Heart *life){

	int number = random();
	//MECANICA DE ROLAGEM DE MAPA
	background->scroll = 0.0f;

	//MECANICAS DE MENU
	menu->start = 1;
	menu->inGame = 1;
	menu->exit = 1;
	menu->restart = 1;

	//retangulo da porção
	life->portionRec.width = life->portion.width - 25;
	life->portionRec.height = life->portion.height - 25;
	if(number%2 ==0)
		life->getPortion = 1;
	else
		life->getVeneno = 1;
	life->venenoRec.width = life->veneno.width - 25;
	life->venenoRec.height = life->veneno.height - 25;

	//ATRIBUTOS PLATAFORMA
	platafoma->storePositon = 1200;
	platafoma->position = (Vector2){1200,580};
	platafoma->rec.width = platafoma->plataform.width;
	platafoma->rec.height = platafoma->plataform.height;

	//MECANICAS EXTRAS
	set->map = 0;
	set->time = 0.0f;
	set->framesCounter = 0;
	set->steps = 0;
	set->gameOver = 0;
	set->finalFase = (Vector2){background->mapa.width, 608};

	//ATRIBUTOS DO PLAYER
	player->stop = 1;
	player->canJump = 0;
	player->vida = 3;
	player->direction = 0;
	player->esperaHit = 0;
	player->characterRadius = 125;
	player->characterPosition = (Vector2){240, 608}; //POSICAO INICIAL DO PLAYER
	player->rec.width = player->personStopLeft.width - 100;
	player->rec.height = player->personStopLeft.height;

	//ATRIBUTOS DO FANATICO
	fanatico->damage = 2;
	fanatico->hp = 12;
	fanatico->direction = -1;
	fanatico->stop = 0;
	fanatico->atack = 0;
	fanatico->die = 0;
	fanatico->enemyPosition = (Vector2){3350, 560};
	fanatico->rec.width = fanatico->idle_right.width / 6;
	fanatico->rec.height = fanatico->idle_right.height;
	fanatico->rec.x = fanatico->enemyPosition.x;
	fanatico->rec.y = fanatico->enemyPosition.y; //POSICAO INICIAL DO FANATICO
}
