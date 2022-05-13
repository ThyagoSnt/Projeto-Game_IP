#include "../include/game.h"

static int	descer = 0;
static int colision = 0;

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

void setRec(Player *player,Fanatico *fanatico, Plataform * plataform, Heart *life){ //SETANDO AS COLISOES
	player->rec.x = player->characterPosition.x + 50;
	player->rec.y = player->characterPosition.y;
	fanatico->rec.x = fanatico->enemyPosition.x;
	fanatico->rec.y = fanatico->enemyPosition.y;
	plataform->rec.x = plataform->position.x;
	plataform->rec.y = plataform->position.y;
	life->portionRec.x = plataform->position.x + 20;
	life->portionRec.y = plataform->position.y - 70;
	life->venenoRec.x = plataform->position.x + 100;
	life->venenoRec.y = plataform->position.y + 50;

}

void GameMechanics(Background *background,SetGame *set,Plataform *platafoma, Player *player, Heart *life, GameScreen *currentScreen, Fanatico *fanatico){

	UpdateMusicStream(set->music.natureza);
	UpdateMusicStream(set->music.start);
	setRec(player,fanatico,platafoma,life);

	if(IsKeyPressed(KEY_ESCAPE))
		*currentScreen = MENU;

	//ALTERANDO A POSICAO DO PLAYER NO EIXO X
	if(IsKeyDown(KEY_D) && (player->characterPosition.x + player->characterRadius < screenWidth)){ //MOVIMENTO DO PLAYER PARA DIREITA
		player->stop = 0;
		player->characterPosition.x += 1.7f;
		UpdateMusicStream(set->music.run);
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
		UpdateMusicStream(set->music.run);
		player->stop = 0;
		player->characterPosition.x -= 1.7f;
		player->direction = -1;
	}

	//MECANICA DE PULO
	jumpMechanics(player,platafoma,set);

	//TESTE DE ALTERAR A VIDA COM AS SETAS DO TECLADO
	if(IsKeyPressed(KEY_RIGHT) && (player->vida <= 4))
		player->vida++;
	if(IsKeyPressed(KEY_LEFT) && (player->vida >= 1))
		player->vida--;

	if(player->vida == 0)
		*currentScreen = GAME_OVER; //TELA DE MORTE

	if(set->steps == 3600){ //TROCA DE MAPA
		//set->map = 1;
		set->steps = 0;
		life->getPortion=1;
		life->getVeneno=1;

	}


	//Mecanica da porção
	if(CheckCollisionRecs(player->rec,life->portionRec) && life->getPortion)
	{
		life->getPortion=0;
		if ((player->vida <= 4))
		{
			player->vida++;
			life->portion.height = 0;
		}

	}
	//Mecanica da porção
	if(CheckCollisionRecs(player->rec,life->venenoRec) && life->getVeneno)
	{
		life->getVeneno=0;
		if ((player->vida > 0))
		{
			player->vida--;
			life->veneno.height = 0;
		}

	}


	//MECANICA DE MOVIMENTO & HIT DO FANATICO
	if(set->steps  > 3000 && set->steps < 3400){
		if(fanatico->enemyPosition.x - player->characterPosition.x < 0)
			fanatico->enemyPosition.x += 2.0;
		else
			fanatico->enemyPosition.x -= 2.0;

	}
	if(fanatico->enemyPosition.x < 1000){
		UpdateMusicStream(set->music.startFanatic);
		StopMusicStream(set->music.start);
	}
	if(fanatico->enemyPosition.x - player->characterPosition.x > -1000 && fanatico->enemyPosition.x - player->characterPosition.x < -500)
		fanatico->enemyPosition.x += 1.3;
	if((fanatico->enemyPosition.x - player->characterPosition.x > 20) && (fanatico->enemyPosition.x - player->characterPosition.x < 20000)){
		fanatico->stop = 0;
		fanatico->direction = -1;
		fanatico->enemyPosition.x -= 1.3;
	}
	else if((fanatico->enemyPosition.x - player->characterPosition.x < -20) && (fanatico->enemyPosition.x - player->characterPosition.x > -20000)){
		fanatico->stop = 0;
		fanatico->direction = 1;
		fanatico->enemyPosition.x += 1.3;
	}
	else
		fanatico->stop = 1;
	if(player->esperaHit != 0)
		player->esperaHit--;
	if(CheckCollisionRecs(player->rec,fanatico->rec) && player->esperaHit == 0){
		player->vida--;
		player->esperaHit = 451;
	}

	//MECANICA DO BACKGROUND
	if (background->back <= -background->backg[set->map].width*4)
		background->back = 0;
	if (background->mid <= -background->midg[set->map].width*4)
		background->mid = 0;
	if (background->fore <= -background->foreg[set->map].width*4)
		background->fore = 0;
}

void TitleMechanics(GameScreen *currentScreen, Menu *menu, Music *music){ //MECANICAS DO TITULO PRINCIPAL
	UpdateMusicStream(*music);
	if(IsKeyPressed(KEY_ENTER) && menu->start == 1)
		*currentScreen = GAMEPLAY;
	else if(IsKeyPressed(KEY_ENTER) && menu->start == 0)
		*currentScreen = INFO;
	if(IsKeyPressed(KEY_UP))
		menu->start = 1;
	else if(IsKeyPressed(KEY_DOWN))
		menu->start = 0;
}

void MenuMechanics(GameScreen *currentScreen, Menu *menu){ //MECANICAS DO MENU
	if(IsKeyPressed(KEY_ENTER) && menu->inGame == 1)
		*currentScreen = TITLE;
	else if(IsKeyPressed(KEY_ENTER) && menu->inGame == 2)
		*currentScreen = OPTIONS;
	else if(IsKeyPressed(KEY_ENTER) && menu->inGame == 3)
		*currentScreen = SAVEGAME;
	else if(IsKeyPressed(KEY_ENTER) && menu->inGame == 4)
		*currentScreen = EXIT;

	if(IsKeyPressed(KEY_UP) && (menu->inGame) > 1)
		menu->inGame--;
	else if(IsKeyPressed(KEY_DOWN) && (menu->inGame) < 4)
		menu->inGame++;
}

void InfoMechanics(GameScreen *currentScreen, Menu *menu,Music *music){ //MECANICAS DA INFO
	UpdateMusicStream(*music);
	if(IsKeyPressed(KEY_ESCAPE))
		*currentScreen = TITLE;
}

void OptionsMechanics(GameScreen *currentScreen, Menu *menu){ //MECANICAS DA OPCOES
	if(IsKeyPressed(KEY_ESCAPE))
		*currentScreen = MENU;
}

void SaveMechanics(GameScreen *currentScreen, Menu *menu){ //MECANICAS DO SAVE
	if(IsKeyPressed(KEY_ESCAPE))
		*currentScreen = MENU;
}

void ExitMechanics(GameScreen *currentScreen, Menu *menu){ //MECANICAS DO EXIT
	if(IsKeyPressed(KEY_ENTER) && (menu->exit == 1))
		exit(1);
	else if(IsKeyPressed(KEY_ENTER) && (menu->exit == 2))
		*currentScreen = MENU;

	if(IsKeyPressed(KEY_LEFT))
		menu->exit = 1;
	else if(IsKeyPressed(KEY_RIGHT))
		menu->exit = 2;
}

void OverMechanics(GameScreen *currentScreen, Player *player, SetGame *set){ //MECANICAS DO GAMEOVER
	if(IsKeyPressed(KEY_ESCAPE)){
		player->vida = 4;
		*currentScreen = TITLE;
	}
}
