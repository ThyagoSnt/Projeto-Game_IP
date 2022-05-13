#include "../../include/game.h"

void GameMechanics(Background *background,SetGame *set,Plataform *platafoma, Player *player, Heart *life, GameScreen *currentScreen, Fanatico *fanatico){

	if(IsKeyPressed(KEY_ESCAPE))
		*currentScreen = MENU;
	UpdateMusicStream(set->music.natureza);
	UpdateMusicStream(set->music.start);
	setRec(player,fanatico,platafoma,life);
	PlayerMechanics(player,set,background,fanatico,platafoma);
	EnemyMechanics(fanatico,set,player);
	InteractiveMechanics(player,set,life,currentScreen);
	EnvironmentMechanic(background,set);
}


//TESTE DE ALTERAR A VIDA COM AS SETAS DO TECLADO
	// if(IsKeyPressed(KEY_RIGHT) && (player->vida <= 4))
	// 	player->vida++;
	// if(IsKeyPressed(KEY_LEFT) && (player->vida >= 1))
	// 	player->vida--;
