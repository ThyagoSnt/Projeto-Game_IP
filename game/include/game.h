#ifndef GAME_IP
# define GAME_IP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "raylib.h"

#define  screenWidth  1260
#define  screenHeight  800

typedef struct{ //ESTRUTURA DO PLAYER
    char name[20];
    int vida;
    int canJump;
	Vector2 characterPosition;
} Player;

typedef struct
{
	Texture2D	personRight;
	Texture2D	personLeft;
}Person;

typedef struct
{
	Texture2D	heartFull;
	Texture2D	heartEmpty;
}Heart;

typedef struct
{
	Texture2D	back;
	Texture2D	mid;
	Texture2D	fore;
}Background;

typedef struct
{
	Texture2D	background;
}Menu;

typedef struct
{
	float	time;
	int		framesCounter;
	int		direction;
	int		characterRadius;
}SetGame;

typedef struct
{
	float	back;
	float	mid;
	float	fore;
}Scroll;


typedef enum GameScreen{ //ESTRUTURA DE TELAS
    TITLE, MENU, GAMEPLAY
} GameScreen;

void DrawGamePlay(Background background, Scroll scroll,SetGame set, Player player, Heart life,Person persona);
void DrawMenu(Menu menu);
void DrawTitle(Menu menu);
void UnloadAllTexture(Person *persona, Heart *life,Background *background, Menu *menu);
void LoadAllTexture(Person *persona, Heart *life,Background *background, Menu *menu);
void InitVar(Scroll *scroll, SetGame *set,Player *player);
void GameMechanics(Background *background, Scroll *scroll,SetGame *set, Player *player, Heart *life, GameScreen *currentScreen);
void TitleMechanics(GameScreen *currentScreen);
void MenuMechanics(GameScreen *currentScreen);

#endif
