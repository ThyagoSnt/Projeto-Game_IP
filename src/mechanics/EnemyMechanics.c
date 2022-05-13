#include "../../include/game.h"
//MECANICA DE MOVIMENTO & HIT DO FANATICO
void EnemyMechanics(Fanatico *fanatico, SetGame *set, Player *player)
{
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

}
