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
	int	direction;
	int	characterRadius;
	int stop;
	Vector2 characterPosition;
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
	Texture2D back[2];
	Texture2D mid[2];
	Texture2D fore[2];
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
	int map;
	int	framesCounter;
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

typedef struct{ //ATRIBUTOS DO FANTICO
	int hp;
	int damage;
	int direction;
	int stop;
	Vector2 enemyPosition;
} Fanatico;

typedef struct{ //TEXTURA DO FANTICO
	Texture2D walk_right;
	Texture2D walk_left;
	Texture2D stop_left;
	Texture2D stop_right;
} Fantext;

void DrawGamePlay(Background background, Scroll scroll,SetGame set, Player player, Heart life, Person persona, Fantext fantxt, Fanatico fanatico);
void DrawMenu(Menu menu);
void DrawTitle(Menu menu);
void LoadAllTexture(Person *persona, Heart *life,Background *background, Menu *menu, SetGame *set, Fantext *fantxt);
void UnloadAllTexture(Person *persona, Heart *life,Background *background, Menu *menu, SetGame *set, Fantext *fantxt);
void InitVar(Scroll *scroll, SetGame *set,Player *player, Fanatico *fanatico);
void GameMechanics(Background *background, Scroll *scroll,SetGame *set, Player *player, Heart *life, GameScreen *currentScreen, Fanatico *fanatico);
void TitleMechanics(GameScreen *currentScreen,Menu *menu);
void MenuMechanics(GameScreen *currentScreen);
void InfoMechanics(GameScreen *currentScreen, Menu *menu);
void DrawInfo(Menu menu);
void DrawGameOver();

#endif