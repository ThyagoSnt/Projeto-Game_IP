#include "../include/game.h"

void DrawGamePlay(Background background,SetGame set,Plataform plataforma ,Player player, Heart life, Fanatico fanatico){
	//CENARIOS DO FUNDO
	DrawTextureEx(background.backg[set.map], (Vector2){ background.back, 40 }, 0.0f, 4.0f, WHITE);
	DrawTextureEx(background.backg[set.map], (Vector2){ background.backg[set.map].width*4 + background.back, 40 }, 0.0f, 4.0f, WHITE);
	//CENARIOS DO MEIO
	DrawTextureEx(background.midg[set.map], (Vector2){ background.mid, 40 }, 0.0f, 4.0f, WHITE);
	DrawTextureEx(background.midg[set.map], (Vector2){ background.midg[set.map].width*4 + background.mid, 40 }, 0.0f, 4.0f, WHITE);
	//CENARIOS DA FRENTE
	DrawTextureEx(background.foreg[set.map], (Vector2){ background.fore, 40 }, 0.0f, 4.0f, WHITE);
	DrawTextureEx(background.foreg[set.map], (Vector2){ background.foreg[set.map].width*4 + background.fore, 40 }, 0.0f, 4.0f, WHITE);
	//FLOOR
	if(set.map == 0){
		DrawTextureEx(background.floor, (Vector2){ 0, 740 }, 0.0f, 4.0f, WHITE);
		DrawTextureEx(background.floor, (Vector2){ 620, 740 }, 0.0f, 4.0f, WHITE);
	}

	//PLATAFORMA
	DrawRectangleLinesEx(plataforma.rec,1,BLANK);
	DrawTextureEx(plataforma.plataform,plataforma.position,0,1,WHITE);
	
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

	//ANIMACAO DO FANATICO
	DrawRectangleLines(fanatico.enemyPosition.x,fanatico.enemyPosition.y,fanatico.walk_left.width/6,fanatico.walk_left.height - 50,BLANK);
	if(fanatico.direction == 1 && fanatico.stop == 0)
		DrawTextureRec(fanatico.walk_left, (Rectangle){(fanatico.walk_left.width/6)*(set.framesCounter % 6), 0, fanatico.walk_left.width/6, fanatico.walk_left.height}, fanatico.enemyPosition, WHITE);
	else if(fanatico.direction == -1 && fanatico.stop == 0)
		DrawTextureRec(fanatico.walk_right, (Rectangle){(fanatico.walk_right.width/6)*(set.framesCounter % 6), 0, fanatico.walk_right.width/6, fanatico.walk_right.height}, fanatico.enemyPosition, WHITE);
	else if(fanatico.direction == 1 && fanatico.stop == 1)
		DrawTextureEx(fanatico.stop_left, fanatico.enemyPosition, 0.0f, 1.0f, WHITE);
	else
		DrawTextureEx(fanatico.stop_right, fanatico.enemyPosition, 0.0f, 1.0f, WHITE);

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

	//TEXTO DE TESTE GAMEPLAY
	if(set.map == 0){
		DrawText("GAMEPLAY SCREEN", 50, 120, 40, BLACK);
		DrawText("PRESS ESC TO MENU SCREEN", 50, 160, 20, BLACK);
		DrawText("PRESS F11 TO FULL SCREEN MODE", 850, 160, 20, BLACK);
	}
	else if(set.map == 1){
		DrawText("GAMEPLAY SCREEN", 50, 120, 40, WHITE);
		DrawText("PRESS ESC TO MENU SCREEN", 50, 160, 20, WHITE);
		DrawText("PRESS F11 TO FULL SCREEN MODE", 850, 160, 20, WHITE);
	}
}

//DESENHO DO MENU
void DrawMenu(Menu menu){
	DrawTextureEx(menu.background, (Vector2){ 0, 50}, 0.0f, 1.37f, WHITE);
	DrawText("Main Menu", (menu.background.width + 160)/2, (menu.background.height + 100)/2, 40, BLACK);
	DrawText("Options", (menu.background.width + 160)/2, (menu.background.height + 220)/2, 40, BLACK);
	DrawText("Save Game", (menu.background.width + 160)/2, (menu.background.height + 340)/2, 40, BLACK);
	DrawText("Exit", (menu.background.width + 160)/2, (menu.background.height + 460)/2, 40, BLACK);

	if(menu.inGame == 1)
		DrawRectangleLines((menu.background.width + 150)/2,(menu.background.height + 100)/2,220,40,RED);
	else if(menu.inGame == 2)
		DrawRectangleLines((menu.background.width + 150)/2,(menu.background.height + 220)/2,160,40,RED);
	else if(menu.inGame == 3)
		DrawRectangleLines((menu.background.width + 150)/2,(menu.background.height + 340)/2,230,40,RED);
	else if(menu.inGame == 4)
		DrawRectangleLines((menu.background.width + 150)/2,(menu.background.height + 460)/2,90,40,RED);
}

//DESENHO DO TITULO
void DrawTitle(Menu menu){
	DrawTextureEx(menu.background, (Vector2){ 0, 50}, 0.0f, 1.37f, WHITE);
	DrawText("New Game", (menu.background.width + 200)/2, (menu.background.height + 160)/2, 40, BLACK);
	DrawText("Info", (menu.background.width + 240)/2, (menu.background.height + 280)/2, 40, BLACK);
	if(menu.start == 1)
		DrawRectangleLines((menu.background.width + 190)/2,(menu.background.height + 160)/2,200,40,RED);
	else
		DrawRectangleLines((menu.background.width + 215)/2,(menu.background.height + 280)/2,100,40,RED);
}

//DESENHO DA INFO
void DrawInfo(Menu menu){
	DrawTextureEx(menu.background, (Vector2){ 0, 50}, 0.0f, 1.37f, WHITE);
	DrawText("INFO SCREEN", 50, 120, 40, BLACK);
	DrawText("PRESS ESC TO JUMP TO MENU SCREEN", 50, 160, 20, BLACK);
}

//DESENHO DA OPTIONS
void DrawOptions(Menu menu){
	DrawTextureEx(menu.background, (Vector2){ 0, 50}, 0.0f, 1.37f, WHITE);
	DrawText("OPTIONS SCREEN", 50, 120, 40, BLACK);
	DrawText("PRESS ESC TO JUMP TO MENU SCREEN", 50, 160, 20, BLACK);
}

//DESENHO DO SAVE
void DrawSave(Menu menu){
	DrawTextureEx(menu.background, (Vector2){ 0, 50}, 0.0f, 1.37f, WHITE);
	DrawText("SAVE SCREEN", 50, 120, 40, BLACK);
	DrawText("PRESS ESC TO JUMP TO MENU SCREEN", 50, 160, 20, BLACK);
}

//DESENHO DO EXIT
void DrawExit(Menu menu){
	ClearBackground(BLACK);
	DrawText("DO YOU REALLY WANT TO CLOSE THE GAME?", 120, 250, 40, WHITE);
	DrawText("YES", (menu.background.width + 80)/2, (menu.background.height + 200)/2, 40, WHITE);
	DrawText("NO", (menu.background.width + 360)/2, (menu.background.height + 200)/2, 40, WHITE);

	if(menu.exit == 1)
		DrawRectangleLines((menu.background.width + 70)/2,(menu.background.height + 195)/2,95,40,RED);
	else if(menu.exit == 2)
		DrawRectangleLines((menu.background.width + 340)/2,(menu.background.height + 195)/2,75,40,RED);
}

//DESENHO DO GAMEOVER
void DrawGameOver(){
	ClearBackground(BLACK);
	DrawText("Game Over",screenWidth/2 -150,screenHeight/2 - 50,50,WHITE);
	DrawText("Press ESC to jump to Title Menu",screenWidth/2 - 320,screenHeight/2 +10,50,WHITE);
}