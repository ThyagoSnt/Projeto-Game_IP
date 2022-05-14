#ifndef STRUCTS_H
#define STRUCT_H

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
		int atack;
		int die;
		Vector2 enemyPosition;
		Texture2D walk_right;
		Texture2D walk_left;
		Texture2D idle_left;
		Texture2D idle_right;
		Texture2D die_right;
		Texture2D die_left;
		Texture2D atack_left;
		Texture2D atack_right;
		Rectangle rec;
	}Fanatico;

	typedef struct{ //ANIMACAO DA VIDA
		Texture2D heartFull;
		Texture2D heartEmpty;
		Texture2D portion;
		Texture2D veneno;
		Rectangle portionRec;
		Rectangle venenoRec;
		int getPortion;
		int getVeneno;
		int up;
	}Heart;

	typedef struct{ //TEXTURAS BACKGROUND DO GAME
		float scroll;
		Texture2D mapa;
	} Background;

	typedef struct{ //BACKGROUND MENU
		Texture2D	background;
		Texture2D	title;
		int	start;
		int inGame;
		int exit;
		int restart;
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
		Vector2 finalFase;
		Game_music music;
	} SetGame;

	typedef struct{ //MECANICAS DE COLISAO
		Vector2 position;
		float storePositon;
		Texture2D plataform;
		Rectangle rec;
	} Plataform;

	typedef enum GameScreen{ //ESTRUTURA DE TELAS
		TITLE, MENU, GAMEPLAY, INFO,WIN,GAME_OVER, RESTART, EXIT
	} GameScreen;

#endif
