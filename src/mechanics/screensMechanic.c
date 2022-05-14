#include "../../include/game.h"

void TitleMechanics(GameScreen *currentScreen, Menu *menu, Music *music){ //MECANICAS DO TITULO PRINCIPAL
	UpdateMusicStream(*music);
	if(IsKeyPressed(KEY_ENTER) && menu->start == 1)
		*currentScreen = GAMEPLAY;
	else if(IsKeyPressed(KEY_ENTER) && menu->start == 0)
		*currentScreen = INFO;
	if(IsKeyPressed(KEY_UP))
		menu->start = 1;
	else if(IsKeyPressed(KEY_DOWN))
		menu->start = 0;
}

void MenuMechanics(GameScreen *currentScreen, Menu *menu){ //MECANICAS DO MENU
	if(IsKeyPressed(KEY_ENTER) && menu->inGame == 1)
		*currentScreen = TITLE;
	else if(IsKeyPressed(KEY_ENTER) && menu->inGame == 2)
		*currentScreen = RESTART;
	else if(IsKeyPressed(KEY_ENTER) && menu->inGame == 3)
		*currentScreen = EXIT;

	if(IsKeyPressed(KEY_UP) && (menu->inGame) > 1)
		menu->inGame--;
	else if(IsKeyPressed(KEY_DOWN) && (menu->inGame) < 3)
		menu->inGame++;
}

void InfoMechanics(GameScreen *currentScreen, Menu *menu,Music *music){ //MECANICAS DA INFO
	UpdateMusicStream(*music);
	if(IsKeyPressed(KEY_ESCAPE))
		*currentScreen = TITLE;
}

void RestartMechanics(GameScreen *currentScreen, Menu *menu){ //MECANICAS DO RESTART
	if(IsKeyPressed(KEY_ESCAPE))
		*currentScreen = MENU;

	if(IsKeyPressed(KEY_ENTER) && (menu->restart == 1))
		*currentScreen = MENU;
	else if(IsKeyPressed(KEY_ENTER) && (menu->restart == 2))
		*currentScreen = MENU;

	if(IsKeyPressed(KEY_LEFT))
		menu->restart = 1;
	else if(IsKeyPressed(KEY_RIGHT))
		menu->restart = 2;
}

void ExitMechanics(GameScreen *currentScreen, Menu *menu){ //MECANICAS DO EXIT
	if(IsKeyPressed(KEY_ESCAPE))
		*currentScreen = MENU;

	if(IsKeyPressed(KEY_ENTER) && (menu->exit == 1))
		exit(1);
	else if(IsKeyPressed(KEY_ENTER) && (menu->exit == 2))
		*currentScreen = MENU;

	if(IsKeyPressed(KEY_LEFT))
		menu->exit = 1;
	else if(IsKeyPressed(KEY_RIGHT))
		menu->exit = 2;
}

void OverMechanics(GameScreen *currentScreen, Player *player, SetGame *set){ //MECANICAS DO GAMEOVER
	if(IsKeyPressed(KEY_ESCAPE)){
		player->vida = 4;
		*currentScreen = TITLE;
	}
}

void WinMechanics(GameScreen *currentScreen){
	if(IsKeyPressed(KEY_ESCAPE))
		*currentScreen = TITLE;
}
