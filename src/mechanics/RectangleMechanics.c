#include "../../include/game.h"

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
