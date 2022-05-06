#ifndef GAME_IP
#define GAME_IP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "raylib.h"

#define screenWidth  1260
#define screenHeight  800

typedef struct{ //ESTRUTURA DO PLAYER
    char name[20];
    int vida;
    int canJump;
	Vector2 characterPosition;
	int stop;
} Player;

typedef struct{ //DIRECAO DA ANIMACAO DO PLAYER
	Texture2D personRight;
	Texture2D personLeft;
	Texture2D personStopRight;
	Texture2D personStopLeft;

}Person;

typedef struct{ //ANIMACAO DA VIDA
	Texture2D heartFull;
	Texture2D heartEmpty;
}Heart;

typedef struct{ //TEXTURAS BACKGROUND DO GAME
	Texture2D back;
	Texture2D mid;
	Texture2D fore;
}Background;

typedef struct{ //MECANICAS DO BACK GROUND DO GAME
	float back;
	float mid;
	float fore;
}Scroll;

typedef struct{ //BACKGROUND MENU
	Texture2D	background;
	int	start;
}Menu;

typedef struct{ //VARIAVEIS DE AUXILIO
	float time;
	int	framesCounter;
	int	direction;
	int	characterRadius;
	int	steps;
	int	gameOver;
}SetGame;

typedef struct{ //MECANICAS DE COLISAO
	Vector2 position;
	Texture2D plataform;
}Plataform;

typedef enum GameScreen{ //ESTRUTURA DE TELAS
    TITLE, MENU, GAMEPLAY, INFO, GAME_OVER
} GameScreen;

void DrawGamePlay(Background background, Scroll scroll,SetGame set, Player player, Heart life,Person persona);
void DrawMenu(Menu menu);
void DrawTitle(Menu menu);
void LoadAllTexture(Person *persona, Heart *life,Background *background, Menu *menu);
void UnloadAllTexture(Person *persona, Heart *life,Background *background, Menu *menu);
void InitVar(Scroll *scroll, SetGame *set,Player *player);
void GameMechanics(Background *background, Scroll *scroll,SetGame *set, Player *player, Heart *life, GameScreen *currentScreen);
void TitleMechanics(GameScreen *currentScreen,Menu *menu);
void MenuMechanics(GameScreen *currentScreen);
void InfoMechanics(GameScreen *currentScreen, Menu *menu);
void DrawInfo(Menu menu);
void DrawGameOver();

#endif