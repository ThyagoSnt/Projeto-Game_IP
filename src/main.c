#include "../include/game.h"
void LoadAllMusic(Game_music *music)
{
	music->menu = LoadMusicStream("../assets/audio/music.mp3");
	music->jump = LoadMusicStream("../assets/audio/jump.mp3");
	music->run = LoadMusicStream("../assets/audio/correndo.mp3");
	music->natureza = LoadMusicStream("../assets/audio/natureza.mp3");
}
int main(void){
	//INICIANDO AS STRUCTS
	Player		player;
	Heart		life;
	Background	background;
	Menu		menu;
	GameScreen	currentScreen = TITLE; //SETANDO O INICIO DO GAME NA TELA DE TITULO DO GAME
	SetGame		set;
	Fanatico	fanatico;
	Goblin		goblin;
	Cogumelo	cogumelo;
	Olho		olho;
	Plataform	plataform;
	//INICIANDO O SISTEMA DO JOGO
	InitWindow(screenWidth, screenHeight, "Projeto_versao_0.1"); //INICIAdd
	SetExitKey(KEY_RIGHT_CONTROL);

	InitAudioDevice();
	LoadAllTexture(&player,&life,&background,&plataform,&menu,&set, &fanatico,&goblin,&cogumelo,&olho); // CARREGANDO TODAS AS TEXTURAS
	InitVar(&background,&plataform,&set,&player,&fanatico,&goblin,&cogumelo,&olho); //VARIAVEIS DE MOVIMENTO DO BACKGROUND
	LoadAllMusic(&set.music);
	PlayMusicStream(set.music.menu);
	PlayMusicStream(set.music.jump);
	PlayMusicStream(set.music.run);
	PlayMusicStream(set.music.natureza);


	SetMusicVolume(set.music.natureza,0.1);

	menu.start = 1;

	SetTargetFPS(450); //SETANDO A TAXA DE FPS DO GAME
	while (!WindowShouldClose()){
		//ARMAZENANDO INFORMACOES SOBRE A TAXA DE FPS PARA ANIMACOES
		set.time += GetFrameTime();
		if(set.time >= 0.1f){
			set.time = 0.0f;
			set.framesCounter += 1;
		}
		if(IsKeyPressed(KEY_F11)){
			ToggleFullscreen();
		}

		switch(currentScreen){
			case TITLE: //MECANICAS DA TELA DO TITULO DO GAME
				TitleMechanics(&currentScreen,&menu,&set.music.menu);
			break;
			case INFO: //MECANICAS DA TELA DE INFO
				InfoMechanics(&currentScreen,&menu,&set.music.menu);
			break;
			case MENU: //MECANICAS DA TELA DE MENU
				MenuMechanics(&currentScreen);
			break;
			case GAMEPLAY: //MECANICAS DA TELA DE GAMEPLAY
				GameMechanics(&background, &set,&plataform,&player, &life, &currentScreen, &fanatico, &goblin, &cogumelo, &olho);
			break;
			case GAME_OVER: //TELA DO GAMEOVER
				OverMechanics(&currentScreen, &player, &set);
			break;
		}

		BeginDrawing();
			ClearBackground(BLACK); //LIMPA O BACKGROUND ANTES DE CADA FRAME
			switch(currentScreen){
				case TITLE: //TELA DO TITULO DO GAME
					DrawTitle(menu);
				break;
				case INFO:
					DrawInfo(menu);
				break;
				case MENU: //TELA DO MENU EM JOGO
					DrawMenu(menu);
				break;
				case GAMEPLAY: //TELA DO JOGO
					DrawGamePlay(background, set, plataform,player, life, fanatico, goblin, cogumelo, olho);
					player.stop = 1;
				break;
				case GAME_OVER: //TELA DO GAMEOVER
					DrawGameOver();
				break;
			}
		EndDrawing();
	}

	//DESCARREGANDO AS TEXTURAS
	UnloadAllTexture(&player,&life,&background,&plataform,&menu,&set,&fanatico,&goblin,&cogumelo,&olho);
	UnloadMusicStream(set.music.menu);
	UnloadMusicStream(set.music.jump);
	UnloadMusicStream(set.music.run);
	UnloadMusicStream(set.music.natureza);
	//FECHANDO OS SISTEMAS DE AUDIO E A TELA
	CloseAudioDevice();
	CloseWindow();

	return 0;
}
