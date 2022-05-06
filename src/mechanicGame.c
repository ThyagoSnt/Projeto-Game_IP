#include "../include/game.h"
void GameMechanics(Background *background, Scroll *scroll,SetGame *set, Player *player, Heart *life, GameScreen *currentScreen)
{
	if(IsKeyPressed(KEY_P))
		*currentScreen = MENU;
	//ALTERANDO A POSICAO DO PLAYER NO EIXO X
	if(IsKeyDown(KEY_D) && (player->characterPosition.x + set->characterRadius < screenWidth))
	{
		set->steps++;
		player->stop = 0;
		player->characterPosition.x += 1.0f;
		if(player->characterPosition.x > 560)
		{
			player->characterPosition.x = 560;
			scroll->back -= 0.1f;
			scroll->mid -= 0.5f;
			scroll->fore -= 1.4f;
		}
		set->direction = 1;
	}
	else if(IsKeyDown(KEY_A) && player->characterPosition.x > 0)
	{
		player->stop = 0;
		player->characterPosition.x -= 1.0f;
		set->direction = -1;
	}

	//MECANICA DE PULO
	if(IsKeyDown(KEY_SPACE) && (player->canJump == 0))
		player->canJump = 1;
	if((player->canJump == 1) && (player->characterPosition.y != 350))
		player->characterPosition.y -= 2;
	if(player->characterPosition.y == 350)
		player->canJump = 2;
	if((player->canJump == 2) && (player->characterPosition.y != 628))
		player->characterPosition.y += 2;
	if(player->characterPosition.y == 628)
		player->canJump = 0;

	//MECANICA DO BACKGROUND
	if (scroll->back <= -background->back.width*4)
		scroll->back = 0;
	if (scroll->mid <= -background->mid.width*4)
		scroll->mid = 0;
	if (scroll->fore <= -background->fore.width*4)
		scroll->fore = 0;

	//TESTE DE ALTERAR A VIDA COM AS SETAS DO TECLADO
	if(IsKeyPressed(KEY_RIGHT) && (player->vida <= 2))
		player->vida++;
	if(set->steps == 900 && (player->vida >= 1))
	{
		player->vida--;
		set->steps = 0;
	}
	if(player->vida == 0)
		*currentScreen = GAME_OVER;
}

void TitleMechanics(GameScreen *currentScreen, Menu *menu)
{
	if(IsKeyPressed(KEY_ENTER) && menu->start == 1)
		*currentScreen = GAMEPLAY;
	else if(IsKeyPressed(KEY_ENTER) && menu->start == 0)
		*currentScreen = INFO;
	if(IsKeyPressed(KEY_UP))
		menu->start = 1;
	else if(IsKeyPressed(KEY_DOWN))
		menu->start = 0;
}

void MenuMechanics(GameScreen *currentScreen)
{
	if(IsKeyPressed(KEY_P))
		*currentScreen = GAMEPLAY;
}

void InfoMechanics(GameScreen *currentScreen, Menu *menu)
{
	if(IsKeyPressed(KEY_Z))
		*currentScreen = TITLE;
}
