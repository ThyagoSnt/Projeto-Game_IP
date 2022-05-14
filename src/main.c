#include "../include/game.h"

void LoadAllMusic(Game_music *music){
	music->menu = LoadMusicStream("../assets/audio/music.mp3");
	music->jump = LoadMusicStream("../assets/audio/jump.mp3");
	music->run = LoadMusicStream("../assets/audio/correndo.mp3");
	music->natureza = LoadMusicStream("../assets/audio/natureza.mp3");
	music->start = LoadMusicStream("../assets/audio/start_game.wav");
	music->startFanatic = LoadMusicStream("../assets/audio/fanatic.wav");

	PlayMusicStream(music->menu);
	PlayMusicStream(music->jump);
	PlayMusicStream(music->run);
	PlayMusicStream(music->natureza);
	PlayMusicStream(music->start);
	PlayMusicStream(music->startFanatic);
}

void SetVolume(Game_music *music){
	SetMusicVolume(music->natureza,0.2);
	SetMusicVolume(music->start,0.3);
	SetMusicVolume(music->startFanatic, 0.3);
}

int main(void){
	//INICIANDO AS STRUCTS
	Player		player;
	Fanatico 	fanatico;
	Heart		life;
	Background	background;
	Menu		menu;
	GameScreen	currentScreen = TITLE; //SETANDO O INICIO DO GAME NA TELA DE TITULO DO GAME
	SetGame		set;
	Plataform	plataform;

	//INICIANDO O SISTEMA DO JOGO
	InitWindow(screenWidth, screenHeight, "Projeto_versao_0.1"); //INICIAdd
	SetExitKey(KEY_RIGHT_CONTROL);

	InitAudioDevice();
	LoadAllTexture(&player,&life,&background,&plataform,&menu,&set, &fanatico); // CARREGANDO TODAS AS TEXTURAS
	InitVar(&background,&plataform,&set,&player,&menu, &fanatico,&life); //VARIAVEIS DE MOVIMENTO DO BACKGROUND
	LoadAllMusic(&set.music);
	SetVolume(&set.music);

	SetTargetFPS(450); //SETANDO A TAXA DE FPS DO GAME
	while (!WindowShouldClose()){
		//ARMAZENANDO INFORMACOES SOBRE A TAXA DE FPS PARA ANIMACOES
		set.time += GetFrameTime();
		if(set.time >= 0.1f){
			set.time = 0.0f;
			set.framesCounter += 1;
		}
		if(IsKeyPressed(KEY_F11))
			ToggleFullscreen();
		// if(set.steps % 3000 == 0 && set.steps != 0)
		// 	currentScreen = WIN;

		switch(currentScreen){
			case TITLE: //MECANICAS DA TELA DO TITULO DO GAME
				TitleMechanics(&currentScreen,&menu,&set.music.menu);
				break;
			case INFO: //MECANICAS DA TELA DE INFO
				InfoMechanics(&currentScreen,&menu,&set.music.menu);
				break;
			case MENU: //MECANICAS DA TELA DE MENU
				MenuMechanics(&currentScreen, &menu);
				break;
			case WIN:
				WinMechanics(&currentScreen);
				break;
			case RESTART: //MECANICA DO RESTART
				RestartMechanics(&currentScreen, &menu);
				break;
			case EXIT: //MECANICA DO EXIT
				ExitMechanics(&currentScreen, &menu);
				break;
			case GAMEPLAY: //MECANICAS DA TELA DE GAMEPLAY
				GameMechanics(&background, &set,&plataform,&player, &life, &currentScreen, &fanatico);
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
				case INFO: //TELA DE INFORMACOES
					DrawInfo(menu);
					break;
				case MENU: //TELA DO MENU EM JOGO
					DrawMenu(menu);
					break;
				case WIN:
					DrawGameWin();
					break;
				case RESTART: //TELA DO RESTART
					DrawRestart(menu);
					break;
				case EXIT: //TELA DO EXIT
					DrawExit(menu);
					break;
				case GAMEPLAY: //TELA DO JOGO
					DrawGamePlay(background, set, plataform,player, life, fanatico);
					player.stop = 1;
					break;
				case GAME_OVER: //TELA DO GAMEOVER
					DrawGameOver();
					break;
			}
		EndDrawing();
	}

	//DESCARREGANDO AS TEXTURAS
	UnloadAllTexture(&player,&life,&background,&plataform,&menu,&set,&fanatico);
	UnloadMusicStream(set.music.menu);
	UnloadMusicStream(set.music.jump);
	UnloadMusicStream(set.music.run);
	UnloadMusicStream(set.music.natureza);

	//FECHANDO OS SISTEMAS DE AUDIO E A TELA
	CloseAudioDevice();
	CloseWindow();

	return 0;
}
