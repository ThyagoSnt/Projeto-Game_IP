#include "../../include/game.h"

static int	descer = 0;
static int colision = 0;
void runMechanics(Player *player,SetGame *set, Background *background,Fanatico *fanatico,Plataform *plataform){

	if(IsKeyDown(KEY_D) && (player->characterPosition.x + player->characterRadius < screenWidth)){ //MOVIMENTO DO PLAYER PARA DIREITA
		player->stop = 0;
		player->characterPosition.x += 1.7f;
		UpdateMusicStream(set->music.run);
		set->steps++;
		background->back -= 0.2f;
		background->mid -= 0.5f;
		background->fore -= 1.0f;
		background->floor -= 1.0f;
		plataform->position.x -= 1;
		if(player->characterPosition.x > 560){
			player->characterPosition.x = 560;
			fanatico->enemyPosition.x -= 2;
		}
		player->direction = 1;
	}
	else if(IsKeyDown(KEY_A) && player->characterPosition.x > 0){ //MOVIMENTO DO PLAYER PARA ESQUERDA
		UpdateMusicStream(set->music.run);
		player->stop = 0;
		player->characterPosition.x -= 1.7f;
		player->direction = -1;
	}
}

void jumpMechanics(Player *player, Plataform *plataform, SetGame *set){

	colision = 0;
	if(CheckCollisionRecs(player->rec,plataform->rec))
		colision = 1;
	if(IsKeyDown(KEY_SPACE) && (player->canJump == 0))
		player->canJump = 1;
	if(player->canJump!= 0 && !colision)
		UpdateMusicStream(set->music.jump);
	if(colision){
		if(player->characterPosition.y > plataform->position.y){
			descer = 1;
			player->characterPosition.y += 2;
			player->canJump = 2;
		}
		else
			player->canJump = 2;
	}
	else{
		if((player->canJump == 1) && ((player->characterPosition.y != 450)))
			player->characterPosition.y -= 2;
		if(player->characterPosition.y == 450)
			player->canJump = 2;
		if((player->canJump == 2) && (((player->characterPosition.y != 628) && !colision) || descer))
			player->characterPosition.y += 2;
		if(player->characterPosition.y == 628)
			player->canJump = 0;
	}
}

//ALTERANDO A POSICAO DO PLAYER NO EIXO X
void PlayerMechanics(Player *player, SetGame *set, Background *background,Fanatico *fanatico,Plataform *platafoma){
	runMechanics(player,set,background,fanatico,platafoma);
	jumpMechanics(player,platafoma,set);
}



