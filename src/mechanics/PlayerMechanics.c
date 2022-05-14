#include "../../include/game.h"

static int	descer = 0;
static int colision = 0;
void runMechanics(Player *player,SetGame *set, Background *background,Fanatico *fanatico,Plataform *plataform){

<<<<<<< HEAD
//MECANICA DE CORRIDA
void runMechanics(Player *player,SetGame *set, Background *background,Fanatico *fanatico,Plataform *platafoma){
=======
>>>>>>> e4914df21c23672814fe681b62f313fcf9312f74
	if(IsKeyDown(KEY_D) && (player->characterPosition.x + player->characterRadius < screenWidth)){ //MOVIMENTO DO PLAYER PARA DIREITA
		player->stop = 0;
		player->characterPosition.x += 1.7f;
		UpdateMusicStream(set->music.run);
<<<<<<< HEAD
		if(player->characterPosition.x > 580 && set->steps < 7900){
			platafoma->position.x -= 0.5;
=======
		if(player->characterPosition.x > 650 && set->steps < 10000){
			plataform->position.x -= 1;
>>>>>>> e4914df21c23672814fe681b62f313fcf9312f74
			set->steps++;
			player->characterPosition.x = 580;
			background->scroll -= 1.0f;
			fanatico->enemyPosition.x -= 1;
		}
		player->direction = 1;
	}
	else if(IsKeyDown(KEY_A) && player->characterPosition.x > 0){ //MOVIMENTO DO PLAYER PARA ESQUERDA
		UpdateMusicStream(set->music.run);
		player->stop = 0;
		player->characterPosition.x -= 1.7f;
		player->direction = -1;
	}

	//COLISAO COM A PORTA
	if(CheckCollisionRecs(player->rec, set->finalRec))
		set->final = 1;
	else
		set->final = 0;
}

<<<<<<< HEAD
//MECANICA DE PULO
void jumpMechanics(Player *player, Plataform *plataform, SetGame *set){ //MECANICA DE PULO
	colision = 0;
=======
void jumpMechanics(Player *player, Plataform *plataform, SetGame *set){
>>>>>>> e4914df21c23672814fe681b62f313fcf9312f74

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
		if((player->canJump == 1))
			player->characterPosition.y -= 2;
		if(player->characterPosition.y == 380)
			player->canJump = 2;
		if((player->canJump == 2 && !colision) || descer)
			player->characterPosition.y += 2;
		if(player->characterPosition.y == 608)
			player->canJump = 0;
	}
}

//UNINDO AS MECANICAS
void PlayerMechanics(Player *player, SetGame *set, Background *background,Fanatico *fanatico,Plataform *platafoma){
	runMechanics(player,set,background,fanatico,platafoma);
	jumpMechanics(player,platafoma,set);
}