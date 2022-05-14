#include "../../include/game.h"

void DrawEnemy(Fanatico fanatico,SetGame set){
<<<<<<< HEAD
	//ANIMACAO DO FANATICO
	DrawRectangleLines(fanatico.enemyPosition.x,fanatico.enemyPosition.y,fanatico.walk_left.width/6,fanatico.walk_left.height - 50,WHITE);
=======
>>>>>>> e4914df21c23672814fe681b62f313fcf9312f74
	if(fanatico.direction == 1 && fanatico.stop == 0 && fanatico.atack == 0)
		DrawTextureRec(fanatico.walk_left, (Rectangle){(fanatico.walk_left.width/6)*(set.framesCounter % 6), 0, fanatico.walk_left.width/6, fanatico.walk_left.height}, fanatico.enemyPosition, WHITE);
	if(fanatico.direction == -1 && fanatico.stop == 0 && fanatico.atack == 0)
		DrawTextureRec(fanatico.walk_right, (Rectangle){(fanatico.walk_right.width/6)*(set.framesCounter % 6), 0, fanatico.walk_right.width/6, fanatico.walk_right.height}, fanatico.enemyPosition, WHITE);
	if(fanatico.direction == 1 && fanatico.stop == 1 && fanatico.atack == 0)
		DrawTextureRec(fanatico.idle_right, (Rectangle){(fanatico.idle_right.width/5)*(set.framesCounter % 5), 0, fanatico.idle_right.width/5, fanatico.idle_right.height}, fanatico.enemyPosition, WHITE);
	if(fanatico.direction == -1 && fanatico.stop == 1 && fanatico.atack == 0)
		DrawTextureRec(fanatico.idle_left, (Rectangle){(fanatico.idle_left.width/5)*(set.framesCounter % 5), 0, fanatico.idle_left.width/5, fanatico.idle_left.height}, fanatico.enemyPosition, WHITE);
	if(fanatico.direction == 1 && fanatico.atack == 1)
		DrawTextureRec(fanatico.atack_right, (Rectangle){(fanatico.atack_right.width/4)*(set.framesCounter % 4), 0, fanatico.atack_right.width/4, fanatico.atack_right.height}, fanatico.enemyPosition, WHITE);
	if(fanatico.direction == -1 && fanatico.atack == 1)
		DrawTextureRec(fanatico.atack_left, (Rectangle){(fanatico.atack_left.width/4)*(set.framesCounter % 4), 0, fanatico.atack_left.width/4, fanatico.atack_left.height}, fanatico.enemyPosition, WHITE);
}