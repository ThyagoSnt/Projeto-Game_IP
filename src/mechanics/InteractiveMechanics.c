#include "../../include/game.h"

void InteractiveMechanics(Player *player, SetGame *set, Heart *life,GameScreen *currentScreen,Plataform *plataform){

	if(set->steps % 2000 == 0 && set-> steps != 0)
	{
		plataform->position.x = plataform->storePositon;
		plataform->position.y = rand() % 1000;
		if(plataform->position.y > 650)
			plataform->position.y = 650;
		else if(plataform->position.y < 550)
			plataform->position.y = 550;
	}

	if(player->vida == 0)
		*currentScreen = GAME_OVER; //TELA DE MORTE

	if(set->steps % 2000 == 0){
		int number = rand();
		if(number %2 == 0){
			life->getPortion=1;
			life->getVeneno=0;
		}
		else{
			life->getVeneno= 1;
			life->getPortion = 0;
		}
	}

	if(life->getPortion){
		life->portion.height = 50;
		life->veneno.height = 0;
	}
	else if (life->getVeneno){
		life->portion.height = 0;
		life->veneno.height = 50;
	}

	if((set->final == 1) && IsKeyDown(KEY_ENTER)){ //ATIVACAO DO GAMEWIN
		*currentScreen = WIN;
	}

	//Mecanica da porção
	if(CheckCollisionRecs(player->rec,life->portionRec) && life->getPortion){
		life->getPortion=0;
		if ((player->vida <= 4)){
			player->vida++;
			life->portion.height = 0;
		}
	}

	//Mecanica da porção
	if(CheckCollisionRecs(player->rec,life->venenoRec) && life->getVeneno){
		life->getVeneno=0;
		if ((player->vida > 0)){
			player->vida--;
			life->veneno.height = 0;
		}
	}
}
