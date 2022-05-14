#include "../../include/game.h"

void DrawInteractive(Plataform plataform,Heart life, SetGame set){
		DrawTextureRec(life.veneno,(Rectangle){(life.veneno.width/3)*(set.framesCounter % 4), 0, life.veneno.width/3, life.veneno.height},(Vector2){plataform.position.x + 25,plataform.position.y -70},WHITE);
		DrawTextureRec(life.portion,(Rectangle){(life.portion.width/3)*(set.framesCounter % 4), 0, life.portion.width/3, life.portion.height},(Vector2){plataform.position.x + 25,plataform.position.y - 70},WHITE);
		DrawTextureEx(plataform.plataform,plataform.position,0,1,WHITE);
}