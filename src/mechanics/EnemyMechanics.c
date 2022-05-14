#include "../../include/game.h"

//MECANICA DE MOVIMENTO & HIT DO FANATICO
void EnemyMechanics(Fanatico *fanatico, SetGame *set, Player *player){
	if(set->steps > 3000 && set->steps < 3400 || set->steps > 6000 && set->steps < 6400 || set->steps > 9000 && set->steps < 9400 || set->steps > 12000 && set->steps < 12400){
		if(fanatico->enemyPosition.x - player->characterPosition.x < 0)
			fanatico->enemyPosition.x += 3.0;
		else
			fanatico->enemyPosition.x -= 3.0;
	}

	if(fanatico->enemyPosition.x < 3000){
		UpdateMusicStream(set->music.startFanatic);
		StopMusicStream(set->music.start);
	}

<<<<<<< HEAD
	if(player->esperaHit != 0)
		player->esperaHit--;

	if((fanatico->enemyPosition.x - player->characterPosition.x > 300) &&
	(fanatico->enemyPosition.x - player->characterPosition.x < 2000)
	){
=======
	if((fanatico->enemyPosition.x - player->characterPosition.x > 500) && (fanatico->enemyPosition.x - player->characterPosition.x < 20000)){
		fanatico->stop = 0;
		fanatico->atack = 0;
		fanatico->direction = -1;
		fanatico->enemyPosition.x -= 3.0;
	}
	else if((fanatico->enemyPosition.x - player->characterPosition.x < -500) && (fanatico->enemyPosition.x - player->characterPosition.x > -20000)){
		fanatico->stop = 0;
		fanatico->atack = 0;
		fanatico->direction = 1;
		fanatico->enemyPosition.x += 3.0;
	}
	if((fanatico->enemyPosition.x - player->characterPosition.x > 50) && (fanatico->enemyPosition.x - player->characterPosition.x < 20000)){
>>>>>>> e4914df21c23672814fe681b62f313fcf9312f74
		fanatico->stop = 0;
		fanatico->atack = 0;
		fanatico->direction = -1;
		fanatico->enemyPosition.x -= 0.7;
	}
<<<<<<< HEAD
	else if((fanatico->enemyPosition.x - player->characterPosition.x < -300) &&
	(fanatico->enemyPosition.x - player->characterPosition.x > -2000)
	){
=======
	else if((fanatico->enemyPosition.x - player->characterPosition.x < -50) && (fanatico->enemyPosition.x - player->characterPosition.x > -20000)){
>>>>>>> e4914df21c23672814fe681b62f313fcf9312f74
		fanatico->stop = 0;
		fanatico->atack = 0;
		fanatico->direction = 1;
		fanatico->enemyPosition.x += 0.7;
	}
	else{
		fanatico->stop = 1;
	}

<<<<<<< HEAD
	if(CheckCollisionRecs(player->rec,fanatico->rec) &&
	(player->esperaHit == 0) && (fanatico->atack == 0) &&
	(fanatico->enemyPosition.x - player->characterPosition.x < 80) &&
	(fanatico->enemyPosition.x - player->characterPosition.x > -80)
	){
		fanatico->atack = 1;
		player->vida--;
		player->esperaHit = 1200;
	}

	if((fanatico->enemyPosition.x - player->characterPosition.x < -2000) || (fanatico->enemyPosition.x - player->characterPosition.x > 2000)){
		fanatico->enemyPosition.x = player->characterPosition.x + 1000;
	}
}
=======
	 if(player->esperaHit != 0)
		player->esperaHit--;

	if(CheckCollisionRecs(player->rec,fanatico->rec) && player->esperaHit == 0){
		player->vida --;
		player->esperaHit = 451;
	}
}
>>>>>>> e4914df21c23672814fe681b62f313fcf9312f74
