#include "../include/game.h"

void DrawGamePlay(Background background, Scroll scroll,SetGame set, Player player, Heart life,Person persona, Fantext fantxt, Fanatico fanatico){

	//CENARIO DO FUNDO1
	DrawTextureEx(background.back[set.map], (Vector2){ scroll.back, 40 }, 0.0f, 4.0f, WHITE);
	DrawTextureEx(background.back[set.map], (Vector2){ background.back[set.map].width*4 + scroll.back, 40 }, 0.0f, 4.0f, WHITE);
	//CENARIO DO MEIO1
	DrawTextureEx(background.mid[set.map], (Vector2){ scroll.mid, 40 }, 0.0f, 4.0f, WHITE);
	DrawTextureEx(background.mid[set.map], (Vector2){ background.mid[set.map].width*4 + scroll.mid, 40 }, 0.0f, 4.0f, WHITE);
	//CENARIO DA FRENTE1
	DrawTextureEx(background.fore[set.map], (Vector2){ scroll.fore, 40 }, 0.0f, 4.0f, WHITE);
	DrawTextureEx(background.fore[set.map], (Vector2){ background.fore[set.map].width*4 + scroll.fore, 40 }, 0.0f, 4.0f, WHITE);

	//ANIMACAO DO PLAYER
	if((player.direction == 1 || player.direction == 0) && player.stop == 0) DrawTextureRec(persona.personRight, (Rectangle){(persona.personRight.width/6)*(set.framesCounter % 6), 0, persona.personRight.width/6, persona.personRight.height}, player.characterPosition, WHITE);
	else if(player.direction == -1 && player.stop == 0) DrawTextureRec(persona.personLeft, (Rectangle){(persona.personLeft.width/6)*(set.framesCounter % 6), 0, persona.personLeft.width/6,persona.personLeft.height}, player.characterPosition, WHITE);
	else if((player.direction == 1 || player.direction == 0) && player.stop == 1) DrawTextureEx(persona.personStopRight, player.characterPosition, 0.0f, 1.0f, WHITE);
	else DrawTextureEx(persona.personStopLeft, player.characterPosition, 0.0f, 1.0f, WHITE);

	//ANIMACAO DO FANATICO
	if(fanatico.direction == 1 && fanatico.stop == 0) DrawTextureRec(fantxt.walk_left, (Rectangle){(fantxt.walk_left.width/6)*(set.framesCounter % 6), 0, fantxt.walk_left.width/6, fantxt.walk_left.height}, fanatico.enemyPosition, WHITE);
	else if(fanatico.direction == -1 && fanatico.stop == 0) DrawTextureRec(fantxt.walk_right, (Rectangle){(fantxt.walk_right.width/6)*(set.framesCounter % 6), 0, fantxt.walk_right.width/6, fantxt.walk_right.height}, fanatico.enemyPosition, WHITE);
	else if(fanatico.direction == 1 && fanatico.stop == 1) DrawTextureEx(fantxt.stop_left, fanatico.enemyPosition, 0.0f, 1.0f, WHITE);
	else DrawTextureEx(fantxt.stop_right, fanatico.enemyPosition, 0.0f, 1.0f, WHITE);

	//VIDAS DO PLAYER
	if(player.vida >= 1)DrawTextureEx(life.heartFull, (Vector2){15, 55}, 0.0f, 3.0f, WHITE);
		DrawTextureEx(life.heartEmpty, (Vector2){15, 55}, 0.0f, 3.0f, WHITE);
	if(player.vida >= 2)DrawTextureEx(life.heartFull, (Vector2){75, 55}, 0.0f, 3.0f, WHITE);
		DrawTextureEx(life.heartEmpty, (Vector2){75, 55}, 0.0f, 3.0f, WHITE);
	if(player.vida == 3)DrawTextureEx(life.heartFull, (Vector2){135, 55}, 0.0f, 3.0f, WHITE);
		DrawTextureEx(life.heartEmpty, (Vector2){135, 55}, 0.0f, 3.0f, WHITE);

	//TEXTO DE TESTE GAMEPLAY
	if(set.map == 1){
		DrawText("GAMEPLAY SCREEN", 50, 120, 40, BLACK);
		DrawText("PRESS M TO JUMP TO MENU SCREEN", 50, 160, 20, BLACK);
	}
	else if (set.map == 2){
		DrawText("GAMEPLAY SCREEN", 50, 120, 40, WHITE);
		DrawText("PRESS M TO JUMP TO MENU SCREEN", 50, 160, 20, WHITE);
	}
}

void DrawMenu(Menu menu){
	DrawTextureEx(menu.background, (Vector2){ 0, 50}, 0.0f, 1.37f, WHITE);
	DrawText("IN GAME - MENU SCREEN", 50, 120, 40, BLACK);
	DrawText("PRESS M TO JUMP TO MENU SCREEN", 50, 160, 20, BLACK);
}

void DrawTitle(Menu menu){
	DrawTextureEx(menu.background, (Vector2){ 0, 50}, 0.0f, 1.37f, WHITE);
	DrawText("New Game", (menu.background.width + 200)/2, (menu.background.height + 160)/2, 40, BLACK);
	DrawText("Info", (menu.background.width + 240)/2, (menu.background.height + 280)/2, 40, BLACK);	
	if(menu.start == 1) DrawRectangleLines((menu.background.width + 190)/2,(menu.background.height + 160)/2,200,40,RED);
	else DrawRectangleLines((menu.background.width + 215)/2,(menu.background.height + 280)/2,100,40,RED);
}

void DrawInfo(Menu menu){
	DrawTextureEx(menu.background, (Vector2){ 0, 50}, 0.0f, 1.37f, WHITE);
	DrawText("EXAMPLE TEXT FOR INFO SCREEN\n .", (screenWidth/2) - 280, screenHeight/2, 40, BLACK);
	DrawText("PRESS Z TO JUMP TO TITLE\n .", (screenWidth/2) - 280, (screenHeight/2)+80, 40, BLACK);
}

void DrawGameOver(){
	ClearBackground(BLACK);
	DrawText("Game Over",screenWidth/2 -150,screenHeight/2 - 50,50,WHITE);
	DrawText("Press Z to jump to Title Menu",screenWidth/2 - 320,screenHeight/2 +10,50,WHITE);
}