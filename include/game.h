#ifndef GAME_IP
#define GAME_IP

//INCLUDES
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

typedef struct{ //ANIMACAO DA VIDA
	Texture2D heartFull;
	Texture2D heartEmpty;
	Texture2D portion;
}Heart;

typedef struct{ //TEXTURAS BACKGROUND DO GAME
	float back;
	float mid;
	float fore;
	Texture2D backg[3];
	Texture2D midg[3];
	Texture2D foreg[3];
	Texture2D floor;
} Background;

typedef struct{ //BACKGROUND MENU
	Texture2D	background;
	int	start;
	int inGame;
	int exit;
} Menu;

typedef struct{
	Music	start;
	Music	natureza;
	Music	jump;
	Music	run;
	Music	menu;
	Music	ataqueFanatic;
	Music	startFanatic;
}Game_music;

typedef struct{ //VARIAVEIS DE AUXILIO
	float time;
	int map;
	int	framesCounter;
	int	steps;
	int	gameOver;
	Game_music music;
} SetGame;

typedef struct{ //MECANICAS DE COLISAO
	Vector2 position;
	Texture2D plataform;
	Rectangle rec;
} Plataform;

typedef enum GameScreen{ //ESTRUTURA DE TELAS
    TITLE, MENU, GAMEPLAY, INFO, GAME_OVER, OPTIONS, SAVEGAME, EXIT
} GameScreen;

void LoadAllTexture(Player *player, Heart *life,Background *background,Plataform *plataforma, Menu *menu, SetGame *set, Fanatico *fanatico);
void UnloadAllTexture(Player *player, Heart *life,Background *background,Plataform *plataforma, Menu *menu, SetGame *set, Fanatico *fanatico);
void InitVar(Background *background,Plataform *platafoma,SetGame *set,Player *player,Menu *menu, Fanatico *fanatico);
void GameMechanics(Background *background,SetGame *set,Plataform *platafoma, Player *player, Heart *life, GameScreen *currentScreen, Fanatico *fanatico);
void TitleMechanics(GameScreen *currentScreen, Menu *menu, Music *music);
void MenuMechanics(GameScreen *currentScreen, Menu *menu);
void InfoMechanics(GameScreen *currentScreen, Menu *menu,Music *music);
void OverMechanics(GameScreen *currentScreen, Player *player, SetGame *set);
void OptionsMechanics(GameScreen *currentScreen, Menu *menu);
void SaveMechanics(GameScreen *currentScreen, Menu *menu);
void ExitMechanics(GameScreen *currentScreen, Menu *menu);
void DrawInfo(Menu menu);
void DrawGameOver();
void DrawOptions(Menu menu);
void DrawSave(Menu menu);
void DrawGamePlay(Background background,SetGame set,Plataform plataforma ,Player player, Heart life, Fanatico fanatico);
void DrawMenu(Menu menu);
void DrawTitle(Menu menu);
void DrawExit(Menu menu);

#endif