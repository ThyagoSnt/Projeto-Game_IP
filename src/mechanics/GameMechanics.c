#include "../../include/game.h"

void GameMechanics(Background *background,SetGame *set,Plataform *platafoma, Player *player, Heart *life, GameScreen *currentScreen, Fanatico *fanatico){

	if(IsKeyDown(KEY_ESCAPE))
		*currentScreen = MENU;
	UpdateMusicStream(set->music.natureza);
	UpdateMusicStream(set->music.start);
	setRec(player,fanatico,platafoma,life);
	PlayerMechanics(player,set,background,fanatico,platafoma);
	EnemyMechanics(fanatico,set,player);
	InteractiveMechanics(player,set,life,currentScreen);
	EnvironmentMechanic(background,set);
}