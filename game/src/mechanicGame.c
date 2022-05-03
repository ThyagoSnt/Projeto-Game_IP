#include "../include/game.h"

void GameMechanics(Background *background, Scroll *scroll,SetGame *set, Player *player, Heart *life, GameScreen *currentScreen)
{
	if(IsKeyPressed(KEY_M))
		*currentScreen = MENU;
	//ALTERANDO A POSICAO DO PLAYER NO EIXO X
	if(IsKeyDown(KEY_D) && (player->characterPosition.x + set->characterRadius < screenWidth))
	{
		player->characterPosition.x += 2.0f;
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
		player->characterPosition.x -= 2.0f;
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
	if(IsKeyPressed(KEY_LEFT) && (player->vida >= 1))
		player->vida--;
}

void TitleMechanics(GameScreen *currentScreen)
{
	if(IsKeyPressed(KEY_ENTER))
		*currentScreen = GAMEPLAY;
}

void MenuMechanics(GameScreen *currentScreen)
{
	if(IsKeyPressed(KEY_M))
		*currentScreen = GAMEPLAY;
}
