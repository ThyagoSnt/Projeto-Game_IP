#include "../include/game.h"


void InitVar(Scroll *scroll, SetGame *set,Player *player)
{
	scroll->back = 0.0f;
	scroll->mid = 0.0f;
	scroll->fore = 0.0f;

	set->time = 0.0f;
	set->framesCounter = 0;
	set->direction = 0;
	set->characterRadius = 125;
	set->steps = 0;
	set->gameOver = 0;

	player->stop = 1;
	player->canJump = 0;
	player->vida = 3;
	player->characterPosition = (Vector2){240, 628}; //POSICAO INICIAL DO PLAYER
}

