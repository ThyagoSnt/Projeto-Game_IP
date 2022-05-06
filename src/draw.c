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
	if((set.direction == 1 || set.direction == 0) && player.stop == 0)
		DrawTextureRec(persona.personRight, (Rectangle){(persona.personRight.width/6)*(set.framesCounter % 6), 0, persona.personRight.width/6,persona.personRight.height}, player.characterPosition, WHITE);
	else if(set.direction == -1 && player.stop == 0)
		DrawTextureRec(persona.personLeft, (Rectangle){(persona.personLeft.width/6)*(set.framesCounter % 6), 0, persona.personLeft.width/6,persona.personLeft.height}, player.characterPosition, WHITE);
	else if((set.direction == 1 || set.direction == 0) && player.stop == 1)
		DrawTextureEx(persona.personStopRight, player.characterPosition, 0.0f, 1.0f, WHITE);
	else
		DrawTextureEx(persona.personStopLeft, player.characterPosition, 0.0f, 1.0f, WHITE);

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
	DrawText("PAUSED", (menu.background.width/2) + 20, (screenHeight/2), 80, BLACK);
}

void DrawTitle(Menu menu)
{
	DrawTextureEx(menu.background, (Vector2){ 0, 50}, 0.0f, 1.37f, WHITE);
	DrawText("Start", (menu.background.width + 240)/2, (menu.background.height + 160)/2, 40, BLACK);
	DrawText("Info", (menu.background.width + 240)/2, (menu.background.height + 280)/2, 40, BLACK);
	if(menu.start == 1)
		DrawRectangleLines((menu.background.width + 150)/2,(menu.background.height + 160)/2,200,40,RED);
	else
		DrawRectangleLines((menu.background.width + 150)/2,(menu.background.height + 280)/2,200,40,RED);
}

void DrawInfo(Menu menu)
{
	DrawTextureEx(menu.background, (Vector2){ 0, 50}, 0.0f, 1.37f, WHITE);
	DrawText("Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's\n .", 0, screenHeight/2, 40, BLACK);

}

void DrawGameOver()
{
	ClearBackground(BLACK);
	DrawText("Game Over",screenWidth/2 -150,screenHeight/2 - 50,50,WHITE);
}
