#include "../include/game.h"

void DrawGamePlay(Background background, Scroll scroll,SetGame set, Player player, Heart life,Person persona)
{
	DrawTextureEx(background.back, (Vector2){ scroll.back, 40 }, 0.0f, 4.0f, WHITE);
	DrawTextureEx(background.back, (Vector2){ background.back.width*4 + scroll.back, 40 }, 0.0f, 4.0f, WHITE);

	//CENARIO DO MEIO
	DrawTextureEx(background.mid, (Vector2){ scroll.mid, 40 }, 0.0f, 4.0f, WHITE);
	DrawTextureEx(background.mid, (Vector2){ background.mid.width*4 + scroll.mid, 40 }, 0.0f, 4.0f, WHITE);

	//CENARIO DA FRENTE
	DrawTextureEx(background.fore, (Vector2){ scroll.fore, 40 }, 0.0f, 4.0f, WHITE);
	DrawTextureEx(background.fore, (Vector2){ background.mid.width*4 + scroll.fore, 40 }, 0.0f, 4.0f, WHITE);

	//ANIMACAO DO PLAYER
	if(set.direction == 1 || set.direction == 0)
		DrawTextureRec(persona.personRight, (Rectangle){(persona.personRight.width/6)*(set.framesCounter % 6), 0, persona.personRight.width/6,persona.personRight.height}, player.characterPosition, WHITE);
	if(set.direction == -1)
		DrawTextureRec(persona.personLeft, (Rectangle){(persona.personLeft.width/6)*(set.framesCounter % 6), 0, persona.personLeft.width/6,persona.personLeft.height}, player.characterPosition, WHITE);

	//VIDAS DO PLAYER
	if(player.vida >= 1)
		DrawTextureEx(life.heartFull, (Vector2){15, 55}, 0.0f, 3.0f, WHITE);
	DrawTextureEx(life.heartEmpty, (Vector2){15, 55}, 0.0f, 3.0f, WHITE);
	if(player.vida >= 2)
		DrawTextureEx(life.heartFull, (Vector2){75, 55}, 0.0f, 3.0f, WHITE);
	DrawTextureEx(life.heartEmpty, (Vector2){75, 55}, 0.0f, 3.0f, WHITE);
	if(player.vida == 3)
		DrawTextureEx(life.heartFull, (Vector2){135, 55}, 0.0f, 3.0f, WHITE);
	DrawTextureEx(life.heartEmpty, (Vector2){135, 55}, 0.0f, 3.0f, WHITE);

	//TEXTO DE TESTE GAMEPLAY
	DrawText("GAMEPLAY SCREEN", 50, 120, 40, BLACK);
	DrawText("PRESS M TO JUMP TO MENU SCREEN", 50, 160, 20, BLACK);
}

void DrawMenu(Menu menu)
{
	DrawTextureEx(menu.background, (Vector2){ 0, 50}, 0.0f, 1.37f, WHITE);
	DrawText("MENU SCREEN", (screenWidth/2)-150, screenHeight/2, 40, BLACK);
	DrawText("PRESS M TO JUMP TO GAMEPLAY SCREEN", (screenWidth/2)-450, (screenHeight/2)+50, 40, BLACK);
}

void DrawTitle(Menu menu)
{
	DrawTextureEx(menu.background, (Vector2){ 0, 50}, 0.0f, 1.37f, WHITE);
	DrawText("TITLE SCREEN", (screenWidth/2)-150, screenHeight/2, 40, BLACK);
	DrawText("PRESS ENTER TO JUMP TO GAMEPLAY SCREEN", (screenWidth/2)-450, (screenHeight/2)+50, 40, BLACK);
}
