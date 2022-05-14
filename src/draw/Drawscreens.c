#include "../../include/game.h"

//DESENHO DO MENU
void DrawMenu(Menu menu){
	DrawTextureEx(menu.background, (Vector2){ 0, 50}, 0.0f, 1.37f, WHITE);
	DrawText("Main Menu", (menu.background.width + 160)/2, (menu.background.height + 100)/2, 40, BLACK);
	DrawText("Restart", (menu.background.width + 160)/2, (menu.background.height + 220)/2, 40, BLACK);
	DrawText("Exit", (menu.background.width + 160)/2, (menu.background.height + 340)/2, 40, BLACK);

	if(menu.inGame == 1)
		DrawRectangleLines((menu.background.width + 150)/2,(menu.background.height + 100)/2,220,40,RED);
	else if(menu.inGame == 2)
		DrawRectangleLines((menu.background.width + 150)/2,(menu.background.height + 220)/2,180,40,RED);
	else if(menu.inGame == 3)
		DrawRectangleLines((menu.background.width + 150)/2,(menu.background.height + 340)/2,90,40,RED);
}

//DESENHO DO TITULO
void DrawTitle(Menu menu){
	DrawTextureEx(menu.title, (Vector2){ -30, 30}, 0.0f, 0.705f, WHITE);
	if(menu.start == 1)
		DrawRectangleLines((menu.background.width + 40)/2,(menu.background.height + 460)/2,340,95,RED);
	else
		DrawRectangleLines((menu.background.width + 260)/2,(menu.background.height + 710)/2,120,95,RED);
}

//DESENHO DA INFO
void DrawInfo(Menu menu){
	DrawTextureEx(menu.background, (Vector2){ 0, 50}, 0.0f, 1.37f, GRAY);
	DrawText("INFO MECANICS", (menu.background.width - 50)/2, 120, 60, RED);
	DrawText("PRESS ESC TO JUMP TO TITLE GAME", (menu.background.width)/2, 185, 20, RED);

	DrawText("<MECANICS>", (menu.background.width)/2, (menu.background.height + 100)/2, 40, WHITE);
	DrawText("[D]: RIGHT", (menu.background.width)/2, (menu.background.height + 220)/2, 40, WHITE);
	DrawText("[A]: LEFT", (menu.background.width)/2, (menu.background.height + 340)/2, 40, WHITE);
	DrawText("[SPACE]: JUMP", (menu.background.width)/2, (menu.background.height + 460)/2, 40, WHITE);
	DrawText("[ENTER]: INTERACTIONS", (menu.background.width)/2, (menu.background.height + 580)/2, 40, WHITE);
	DrawText("[F11]: FULL SCREEN", (menu.background.width)/2, (menu.background.height + 700)/2, 40, WHITE);
}

//DESENHO DO RESTART
void DrawRestart(Menu menu){
	DrawTextureEx(menu.background, (Vector2){ 0, 50}, 0.0f, 1.37f, GRAY);
	DrawText("DO YOU REALLY WANT TO RESTART THIS LEVEL?", 120, 250, 40, WHITE);
	DrawText("YES", (menu.background.width + 80)/2, (menu.background.height + 200)/2, 40, WHITE);
	DrawText("NO", (menu.background.width + 360)/2, (menu.background.height + 200)/2, 40, WHITE);

	if(menu.restart == 1)
		DrawRectangleLines((menu.background.width + 70)/2,(menu.background.height + 195)/2,95,40,RED);
	else if(menu.restart == 2)
		DrawRectangleLines((menu.background.width + 340)/2,(menu.background.height + 195)/2,75,40,RED);
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

void DrawGameWin(){
	ClearBackground(BLACK);
	DrawText("YOU WIN THE GAME",screenWidth/2 - 200,screenHeight/2 - 100,100,GREEN);
	DrawText("Press ESC to jump to Title Menu",screenWidth/2 - 400,screenHeight/2 +10,50,WHITE);
}

void DrawGameOver(){
	ClearBackground(BLACK);
	DrawText("Game Over",screenWidth/2 -200,screenHeight/2 - 100,100,RED);
	DrawText("Press ESC to jump to Title Menu",screenWidth/2 - 400,screenHeight/2 + 10,50,WHITE);
}
