#include "../../include/game.h"

void GameMechanics(Background *background,SetGame *set,Plataform *plataform, Player *player, Heart *life, GameScreen *currentScreen, Fanatico *fanatico){

	if(IsKeyDown(KEY_ESCAPE))
		*currentScreen = MENU;
	UpdateMusicStream(set->music.natureza);
	UpdateMusicStream(set->music.start);
	setRec(player,fanatico,plataform,life);
	PlayerMechanics(player,set,background,fanatico,plataform);
	EnemyMechanics(fanatico,set,player);
	InteractiveMechanics(player,set,life,currentScreen,plataform);
	EnvironmentMechanic(background,set);
}
