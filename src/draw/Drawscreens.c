#include "../../include/game.h"

//DESENHO DO MENU
void DrawMenu(Menu menu){
	DrawTextureEx(menu.background, (Vector2){ 0, 50}, 0.0f, 1.37f, WHITE);
	DrawText("Main Menu", (menu.background.width + 160)/2, (menu.background.height + 100)/2, 40, BLACK);
	DrawText("Restart", (menu.background.width + 160)/2, (menu.background.height + 220)/2, 40, BLACK);
	DrawText("History", (menu.background.width + 160)/2, (menu.background.height + 340)/2, 40, BLACK);
	DrawText("Exit", (menu.background.width + 160)/2, (menu.background.height + 460)/2, 40, BLACK);

	if(menu.inGame == 1)
		DrawRectangleLines((menu.background.width + 150)/2,(menu.background.height + 100)/2,220,40,RED);
	else if(menu.inGame == 2)
		DrawRectangleLines((menu.background.width + 150)/2,(menu.background.height + 220)/2,180,40,RED);
	else if(menu.inGame == 3)
		DrawRectangleLines((menu.background.width + 150)/2,(menu.background.height + 340)/2,180,40,RED);
	else if(menu.inGame == 4)
		DrawRectangleLines((menu.background.width + 150)/2,(menu.background.height + 460)/2,90,40,RED);
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

void DrawGameWin(Menu menu){
	DrawTextureEx(menu.win, (Vector2){ 0, 50}, 0.0f, 1.37f, GRAY);
	DrawText("VOCE CONSEGUIU!", (menu.win.width - 150)/2, 120, 60, RED);

	DrawText("VOCE ENCONTROU O MAGO ACMERLIN JUNTO DE UM MONITOR", (menu.win.width)/2-300, (menu.win.height + 100)/2, 20, WHITE);
	DrawText("DA SUA DIMENSAO, ACMITO TE ENSINA O SEGREDO DE UMA ALOCACAO CORRETA", (menu.win.width)/2-300, (menu.win.height + 220)/2, 20, WHITE);
	DrawText("AGORA VOCE PODERA REALIZAR A SUA FINAL TRANQUILAMENTE", (menu.win.width)/2-300, (menu.win.height + 340)/2, 20, WHITE);
	DrawText("O MONITOR FANATICO CONTINUA VAGANDO NA FLORESTA DOS PONTEIROS ATE O DIA DE HOJE", (menu.win.width)/2-300, (menu.win.height + 460)/2, 20, WHITE);
}

void DrawGameOver(){
	ClearBackground(BLACK);
	DrawText("Game Over",screenWidth/2 -150,screenHeight - 1250/2 - 50,70,RED);
	DrawText("Press ESC or Enter to jump to Title Menu",screenWidth/2 - 540,screenHeight/2 +10,50,WHITE);
}

void DrawHistory(Menu menu){
	DrawTextureEx(menu.history, (Vector2){ 0, 50}, 0.0f, 1.37f, GRAY);
	DrawText("Historia do Game:", (menu.history.width - 110)/2, 120, 60, RED);

	DrawText("João Foi pra final na cadeira de IP!", (menu.history.width)/2-300, (menu.history.height + 100)/2, 20, WHITE);
	DrawText("E como tentativa de voltar no tempo e ajustar sua nota", (menu.history.width)/2-300, (menu.history.height + 220)/2, 20, WHITE);
	DrawText("ele pega o elevador tridimensional do Yee-Yee.", (menu.history.width)/2-300, (menu.history.height + 340)/2, 20, WHITE);
	DrawText("Porem como o elevador funciona a base de alocações de memoria ele usa um calloc errado e acaba em", (menu.history.width)/2-300, (menu.history.height + 460)/2, 20, WHITE);
	DrawText("uma dimensao alternativa onde um monitor bodybuilder fanatico por ip", (menu.history.width)/2-300, (menu.history.height + 580)/2, 20, WHITE);
	DrawText("o persegue no intuito de punir aqueles que vao pra final, agora voce tem que", (menu.history.width)/2-300, (menu.history.height + 700)/2, 20, WHITE);
	DrawText("chegar até a porta do castelo do mago ACMerlin, que vai o ajudar a voltar pra sua dimensao!", (menu.history.width)/2-300, (menu.history.height + 820)/2, 20, WHITE);
}