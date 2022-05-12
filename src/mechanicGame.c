#include "../include/game.h"
static int	descer;
void jumpMechanics(Player *player, Plataform *plataform){
	bool colision;

	if(CheckCollisionRecs(player->rec,plataform->rec))
		colision = 1;
	if(IsKeyDown(KEY_SPACE) && (player->canJump == 0))
		player->canJump = 1;

	if(colision)
	{
		if(player->characterPosition.y > plataform->position.y)
		{
			descer = 1;
			player->characterPosition.y += 2;
			player->canJump = 2;
		}
		else
			player->canJump = 2;
	}
	else
	{
		if((player->canJump == 1) && ((player->characterPosition.y != 300)))
			player->characterPosition.y -= 2;
		if(player->characterPosition.y == 300)
			player->canJump = 2;
		if((player->canJump == 2) && (((player->characterPosition.y != 628) && !colision) || descer))
			player->characterPosition.y += 2;
		if(player->characterPosition.y == 628)
			player->canJump = 0;
	}
}

void GameMechanics(Background *background,SetGame *set,Plataform *platafoma, Player *player, Heart *life, GameScreen *currentScreen, Fanatico *fanatico, Goblin *goblin, Cogumelo *cogumelo, Olho *olho){

	player->rec.x = player->characterPosition.x + 50;
	player->rec.y = player->characterPosition.y;
	fanatico->rec.x = fanatico->enemyPosition.x;
	fanatico->rec.y = fanatico->enemyPosition.y;
	platafoma->rec.x = platafoma->position.x;
	platafoma->rec.y = platafoma->position.y;

	if(IsKeyPressed(KEY_M))
		*currentScreen = MENU;

	//ALTERANDO A POSICAO DO PLAYER NO EIXO X
	if(IsKeyDown(KEY_D) && (player->characterPosition.x + player->characterRadius < screenWidth)){ //MOVIMENTO DO PLAYER PARA DIREITA
		player->stop = 0;
		player->characterPosition.x += 3.0f;
		if(player->characterPosition.x > 560){
			platafoma->position.x -= 0.5;
			set->steps++;
			player->characterPosition.x = 560;
			background->back -= 0.1f;
			background->mid -= 0.5f;
			background->fore -= 1.4f;
			fanatico->enemyPosition.x -= 2;
		}
		player->direction = 1;
	}
	else if(IsKeyDown(KEY_A) && player->characterPosition.x > 0){ //MOVIMENTO DO PLAYER PARA ESQUERDA
		player->stop = 0;
		player->characterPosition.x -= 3.0f;
		player->direction = -1;
	}

	//MECANICA DE PULO
	jumpMechanics(player,platafoma);

	//MECANICA DO BACKGROUND
	if (background->back <= -background->backg[set->map].width*4)
		background->back = 0;
	if (background->mid <= -background->midg[set->map].width*4)
		background->mid = 0;
	if (background->fore <= -background->foreg[set->map].width*4)
		background->fore = 0;

	//TESTE DE ALTERAR A VIDA COM AS SETAS DO TECLADO
	if(IsKeyPressed(KEY_RIGHT) && (player->vida <= 4))
		player->vida++;
	if(IsKeyPressed(KEY_LEFT) && (player->vida >= 1))
		player->vida--;
	if(player->vida == 0)
		*currentScreen = GAME_OVER; //TELA DE MORTE

	if(set->steps == 3600){ //TROCA DE MAPA
		set->map = 1;
		set->steps = 0;
	}
	//MECANICA DE MOVIMENTO & HIT DO FANATICO
	if((fanatico->enemyPosition.x - player->characterPosition.x > 200) && (fanatico->enemyPosition.x - player->characterPosition.x < 600)){
		fanatico->stop = 0;
		fanatico->direction = -1;
		fanatico->enemyPosition.x -= 1;
	}
	else if((fanatico->enemyPosition.x - player->characterPosition.x < -200) && (fanatico->enemyPosition.x - player->characterPosition.x > -600)){
		fanatico->stop = 0;
		fanatico->direction = 1;
		fanatico->enemyPosition.x += 1;
	}
	else fanatico->stop = 1;

	if(player->esperaHit != 0)
		player->esperaHit--;
	if(CheckCollisionRecs(player->rec,fanatico->rec) && player->esperaHit == 0){
		player->vida--;
		player->esperaHit = 451;
	}

	//MECANICA DE MOVIMENTO DO GOBLIN
	//  if(goblin->enemyPosition.x - player->characterPosition.x > 100){
	// 	goblin->stop = 0;
	// 	goblin->direction = -1;
	// 	goblin->enemyPosition.x -= 1;
	// }
	// else if(goblin->enemyPosition.x - player->characterPosition.x < -100){
	// 	goblin->stop = 0;
	// 	goblin->direction = 1;
	// 	goblin->enemyPosition.x += 1;
	// }
	// else goblin->stop = 1;

	//MECANICA DE MOVIMENTO DO COGUMELO
	/* if(cogumelo->enemyPosition.x - player->characterPosition.x > 100){
		cogumelo->stop = 0;
		cogumelo->direction = -1;
		cogumelo->enemyPosition.x -= 1;
	}
	else if(cogumelo->enemyPosition.x - player->characterPosition.x < -100){
		cogumelo->stop = 0;
		cogumelo->direction = 1;
		cogumelo->enemyPosition.x += 1;
	}
	else cogumelo->stop = 1; */

	//MECANICA DE MOVIMENTO DO OLHO
	/* if(olho->enemyPosition.x - player->characterPosition.x > 100){
		olho->stop = 0;
		olho->direction = -1;
		olho->enemyPosition.x -= 1;
	}
	else if(olho->enemyPosition.x - player->characterPosition.x < -100){
		olho->stop = 0;
		olho->direction = 1;
		olho->enemyPosition.x += 1;
	}
	else olho->stop = 1; */
}

void TitleMechanics(GameScreen *currentScreen, Menu *menu){ //MECANICAS DO TITULO PRINCIPAL
	if(IsKeyPressed(KEY_ENTER) && menu->start == 1)
		*currentScreen = GAMEPLAY;
	else if(IsKeyPressed(KEY_ENTER) && menu->start == 0)
		*currentScreen = INFO;
	if(IsKeyPressed(KEY_UP))
		menu->start = 1;
	else if(IsKeyPressed(KEY_DOWN))
		menu->start = 0;
}

void MenuMechanics(GameScreen *currentScreen){
	if(IsKeyPressed(KEY_M))
		*currentScreen = GAMEPLAY;
}

void InfoMechanics(GameScreen *currentScreen, Menu *menu){
	if(IsKeyPressed(KEY_Z))
		*currentScreen = TITLE;
}

void OverMechanics(GameScreen *currentScreen, Player *player, SetGame *set){
	if(IsKeyPressed(KEY_Z)){
		player->vida = 4;
		*currentScreen = TITLE;
	}
}
