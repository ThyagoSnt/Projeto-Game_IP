#include "../../include/game.h"

void DrawPlayer(Player player, SetGame set,	Heart life){
	//ANIMACAO DO PLAYER
	DrawRectangleLinesEx(player.rec,1.0,BLANK);
	if((player.direction == 1 || player.direction == 0) && player.stop == 0)
		DrawTextureRec(player.personRight, (Rectangle){(player.personRight.width/6)*(set.framesCounter % 6), 0, player.personRight.width/6, player.personRight.height}, player.characterPosition, WHITE);
	else if(player.direction == -1 && player.stop == 0)
		DrawTextureRec(player.personLeft, (Rectangle){(player.personLeft.width/6)*(set.framesCounter % 6), 0, player.personLeft.width/6,player.personLeft.height}, player.characterPosition, WHITE);
	else if((player.direction == 1 || player.direction == 0) && player.stop == 1)
		DrawTextureEx(player.personStopRight, player.characterPosition, 0.0f, 1.0f, WHITE);
	else
		DrawTextureEx(player.personStopLeft, player.characterPosition, 0.0f, 1.0f, WHITE);

		//VIDAS DO PLAYER
	if(player.vida >= 1) DrawTextureEx(life.heartFull, (Vector2){15, 55}, 0.0f, 3.0f, WHITE);
		DrawTextureEx(life.heartEmpty, (Vector2){15, 55}, 0.0f, 3.0f, WHITE);
	if(player.vida >= 2) DrawTextureEx(life.heartFull, (Vector2){75, 55}, 0.0f, 3.0f, WHITE);
		DrawTextureEx(life.heartEmpty, (Vector2){75, 55}, 0.0f, 3.0f, WHITE);
	if(player.vida >= 3) DrawTextureEx(life.heartFull, (Vector2){135, 55}, 0.0f, 3.0f, WHITE);
		DrawTextureEx(life.heartEmpty, (Vector2){135, 55}, 0.0f, 3.0f, WHITE);
	if(player.vida >= 4) DrawTextureEx(life.heartFull, (Vector2){195, 55}, 0.0f, 3.0f, WHITE);
		DrawTextureEx(life.heartEmpty, (Vector2){195, 55}, 0.0f, 3.0f, WHITE);
	if(player.vida == 5) DrawTextureEx(life.heartFull, (Vector2){255, 55}, 0.0f, 3.0f, WHITE);
		DrawTextureEx(life.heartEmpty, (Vector2){255, 55}, 0.0f, 3.0f, WHITE);
}
