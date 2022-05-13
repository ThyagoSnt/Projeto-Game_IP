#include "../../include/game.h"

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
