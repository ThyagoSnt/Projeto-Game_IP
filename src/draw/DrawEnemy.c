#include "../../include/game.h"


void DrawEnemy(Fanatico fanatico,SetGame set)
{
	 Rectangle recFan = (Rectangle){(fanatico.walk_left.width/6)*(set.framesCounter % 6), 0, fanatico.walk_left.width/6, fanatico.walk_left.height};
	//ANIMACAO DO FANATICO
	DrawRectangleLines(fanatico.enemyPosition.x,fanatico.enemyPosition.y,fanatico.walk_left.width/6,fanatico.walk_left.height - 50,BLANK);
	if(fanatico.direction == 1 && fanatico.stop == 0)
		DrawTextureRec(fanatico.walk_left,recFan, fanatico.enemyPosition, WHITE);
	else if(fanatico.direction == -1 && fanatico.stop == 0)
		DrawTextureRec(fanatico.walk_right,recFan, fanatico.enemyPosition, WHITE);
	else if(fanatico.direction == 1 && fanatico.stop == 1)
		DrawTextureEx(fanatico.stop_left, fanatico.enemyPosition, 0.0f, 1.0f, WHITE);
	else
		DrawTextureEx(fanatico.stop_right, fanatico.enemyPosition, 0.0f, 1.0f, WHITE);

}
