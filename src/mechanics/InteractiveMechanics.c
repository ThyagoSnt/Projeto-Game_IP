#include "../../include/game.h"

void InteractiveMechanics(Player *player, SetGame *set, Heart *life,GameScreen *currentScreen)
{
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

}
