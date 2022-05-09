#include "../include/game.h"

void InitVar(Scroll *scroll, SetGame *set,Player *player, Fanatico *fanatico){

	//MECANICA DE ROLAGEM DE MAPA
	scroll->back = 0.0f;
	scroll->mid = 0.0f;
	scroll->fore = 0.0f;

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
	player->characterRadius = 125;
	player->characterPosition = (Vector2){240, 628}; //POSICAO INICIAL DO PLAYER

	//ATRIBUTOS DO FANATICO
	fanatico->damage = 2;
	fanatico->hp = 6;
	fanatico->direction = -1;
	fanatico->stop = 0;
	fanatico->enemyPosition = (Vector2){1350, 610}; //POSICAO INICIAL DO FANATICO
}