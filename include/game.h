#ifndef GAME_IP
#define GAME_IP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "raylib.h"

#define screenWidth  1260
#define screenHeight  800

typedef struct{ //ATRIBUTOS DO PLAYER
    int vida;
    int canJump;
	int	direction;
	int	characterRadius;
	int stop;
	int esperaHit;
	Vector2 characterPosition;
	Texture2D personRight;
	Texture2D personLeft;
	Texture2D personStopRight;
	Texture2D personStopLeft;
	Rectangle rec;
}Player;

typedef struct{ //ANIMACAO DA VIDA
	Texture2D heartFull;
	Texture2D heartEmpty;
}Heart;

typedef struct{ //TEXTURAS BACKGROUND DO GAME
	float back;
	float mid;
	float fore;
	Texture2D backg[2];
	Texture2D midg[2];
	Texture2D foreg[2];
} Background;

typedef struct{ //BACKGROUND MENU
	Texture2D	background;
	int	start;
} Menu;

typedef struct{ //VARIAVEIS DE AUXILIO
	float time;
	int map;
	int	framesCounter;
	int	steps;
	int	gameOver;
} SetGame;

typedef struct{ //MECANICAS DE COLISAO
	Vector2 position;
	Texture2D plataform;
	Rectangle rec;
} Plataform;

typedef enum GameScreen{ //ESTRUTURA DE TELAS
    TITLE, MENU, GAMEPLAY, INFO, GAME_OVER
} GameScreen;

typedef struct{ //ATRIBUTOS DO FANATICO
	int hp;
	int damage;
	int direction;
	int stop;
	Vector2 enemyPosition;
	Texture2D walk_right;
	Texture2D walk_left;
	Texture2D stop_left;
	Texture2D stop_right;
	Rectangle rec;
}Fanatico;

typedef struct{ //ATRIBUTOS DO GOBLIN
	int hp;
	int damage;
	int direction;
	int stop;
	Vector2 enemyPosition;
	Texture2D walk_right;
	Texture2D walk_left;
	Texture2D stop_left;
	Texture2D stop_right;
} Goblin;

typedef struct{ //ATRIBUTOS DO COGUMELO
	int hp;
	int damage;
	int direction;
	int stop;
	Vector2 enemyPosition;
	Texture2D walk_right;
	Texture2D walk_left;
	Texture2D stop_left;
	Texture2D stop_right;
} Cogumelo;

typedef struct{ //ATRIBUTOS DO OLHO
	int hp;
	int damage;
	int direction;
	int stop;
	Vector2 enemyPosition;
	Texture2D walk_right;
	Texture2D walk_left;
	Texture2D stop_left;
	Texture2D stop_right;
} Olho;

void DrawGamePlay(Background background,SetGame set,Plataform plataforma ,Player player, Heart life, Fanatico fanatico, Goblin goblin, Cogumelo cogumelo, Olho olho);
void DrawMenu(Menu menu);
void DrawTitle(Menu menu);
void LoadAllTexture(Player *player, Heart *life,Background *background,Plataform *plataforma, Menu *menu, SetGame *set, Fanatico *fanatico, Goblin *goblin, Cogumelo *cogumelo, Olho *olho);
void UnloadAllTexture(Player *player, Heart *life,Background *background,Plataform *plataforma, Menu *menu, SetGame *set, Fanatico *fanatico, Goblin *goblin, Cogumelo *cogumelo, Olho *olho);
void InitVar(Background *background,Plataform *platafoma,SetGame *set,Player *player, Fanatico *fanatico, Goblin *goblin, Cogumelo *cogumelo, Olho *olho);
void GameMechanics(Background *background,SetGame *set,Plataform *platafoma, Player *player, Heart *life, GameScreen *currentScreen, Fanatico *fanatico, Goblin *goblin, Cogumelo *cogumelo, Olho *olho);
void TitleMechanics(GameScreen *currentScreen,Menu *menu);
void MenuMechanics(GameScreen *currentScreen);
void InfoMechanics(GameScreen *currentScreen, Menu *menu);
void OverMechanics(GameScreen *currentScreen, Player *player, SetGame *set);
void DrawInfo(Menu menu);
void DrawGameOver();

#endif
