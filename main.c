#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "raylib.h"

typedef struct{
    int vida;
    int canJump;
} Player;

typedef enum GameScreen{
    TITLE = 0, MENU, GAMEPLAY
} GameScreen;

int main(void){
    const int screenWidth = 1260;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Projeto_versao_0.1");
    InitAudioDevice();

    GameScreen currentScreen = TITLE;

    //CARREGANDO ASS TEXTURAS
    Texture2D scarfy = LoadTexture("assets/personagem/scarfy.png");
    Texture2D scarfy_2 = LoadTexture("assets/personagem/scarfy_2.png");
    Texture2D Heart1 = LoadTexture("assets/gui/Heart1.png");
    Texture2D Heart2 = LoadTexture("assets/gui/Heart2.png");
    Texture2D background = LoadTexture("assets/background/background_layer_1.png");
    Texture2D midground = LoadTexture("assets/background/background_layer_2.png");
    Texture2D foreground = LoadTexture("assets/background/background_layer_3.png");
    Texture2D title = LoadTexture("assets/src/title_game.png");

    Vector2 characterPosition = {240, 628};

    float scrollingBack = 0.0f;
    float scrollingMid = 0.0f;
    float scrollingFore = 0.0f;

    float time = 0.0f;
    int framesCounter = 0;
    int direcao = 0; 
    int characterRadius = 125;

    Player player;
    player.canJump = 0;
    player.vida = 3;

    SetTargetFPS(450);
    while (!WindowShouldClose()){

        time += GetFrameTime();
        if(time >= 0.1f){
            time = 0.0f;
            framesCounter += 1;
        }

        switch(currentScreen){
            case TITLE:
            {
                if(IsKeyPressed(KEY_ENTER)){
                    currentScreen = GAMEPLAY;
                }
            } break;
            case MENU:
            {
                if(IsKeyPressed(KEY_M)){
                    currentScreen = GAMEPLAY;
                }
            } break;
            case GAMEPLAY:
            {
                if(IsKeyPressed(KEY_M)){
                    currentScreen = MENU;
                }
                    if(IsKeyDown(KEY_D) && (characterPosition.x+characterRadius < screenWidth)){
                        characterPosition.x += 2.0f;
                        if(characterPosition.x > 560){
                            characterPosition.x = 560;
                            scrollingBack -= 0.1f;
                            scrollingMid -= 0.5f;
                            scrollingFore -= 1.4f;
                        }
                        direcao = 1;
                    }
                else if(IsKeyDown(KEY_A) && characterPosition.x > 0){
                    characterPosition.x -= 2.0f;
                    direcao = -1;
                }

                //PULO
                if(IsKeyDown(KEY_SPACE) && (player.canJump == 0)) player.canJump = 1;
                if((player.canJump == 1) && (characterPosition.y != 350)) characterPosition.y -= 2;
                if(characterPosition.y == 350) player.canJump = 2;
                if((player.canJump == 2) && (characterPosition.y != 628)) characterPosition.y += 2;
                if(characterPosition.y == 628) player.canJump = 0;

                if (scrollingBack <= -background.width*4){scrollingBack = 0;}
                if (scrollingMid <= -midground.width*4){scrollingMid = 0;}
                if (scrollingFore <= -foreground.width*4){scrollingFore = 0;}
            } break;
            default:
                break;
        }

        BeginDrawing();

            ClearBackground(BLACK);

            switch(currentScreen)
            {
                case TITLE:
                {
                    DrawTextureEx(title, (Vector2){ 0, 50}, 0.0f, 1.37f, WHITE);
                    DrawText("TITLE SCREEN", (screenWidth/2)-150, screenHeight/2, 40, BLACK);
                    DrawText("PRESS ENTER TO JUMP TO GAMEPLAY SCREEN", (screenWidth/2)-450, (screenHeight/2)+50, 40, BLACK);

                } break;
                case MENU:
                {
                    DrawTextureEx(title, (Vector2){ 0, 50}, 0.0f, 1.37f, WHITE);
                    DrawText("MENU SCREEN", (screenWidth/2)-150, screenHeight/2, 40, BLACK);
                    DrawText("PRESS M to JUMP TO GAMEPLAY SCREEN", (screenWidth/2)-450, (screenHeight/2)+50, 40, BLACK);

                } break;
                case GAMEPLAY:
                {
                    DrawTextureEx(background, (Vector2){ scrollingBack, 40 }, 0.0f, 4.0f, WHITE);
                    DrawTextureEx(background, (Vector2){ background.width*4 + scrollingBack, 40 }, 0.0f, 4.0f, WHITE);

                    DrawTextureEx(midground, (Vector2){ scrollingMid, 40 }, 0.0f, 4.0f, WHITE);
                    DrawTextureEx(midground, (Vector2){ midground.width*4 + scrollingMid, 40 }, 0.0f, 4.0f, WHITE);

                    DrawTextureEx(foreground, (Vector2){ scrollingFore, 40 }, 0.0f, 4.0f, WHITE);
                    DrawTextureEx(foreground, (Vector2){ foreground.width*4 + scrollingFore, 40 }, 0.0f, 4.0f, WHITE);

                    if(direcao == 1 || direcao == 0)DrawTextureRec(scarfy, (Rectangle){(scarfy.width/6)*(framesCounter % 6), 0, scarfy.width/6,scarfy.height}, characterPosition, WHITE);
                    if(direcao == -1)DrawTextureRec(scarfy_2, (Rectangle){(scarfy_2.width/6)*(framesCounter % 6), 0, scarfy_2.width/6,scarfy_2.height}, characterPosition, WHITE);

                    DrawTextureEx(Heart1, (Vector2){15, 55}, 0.0f, 3.0f, WHITE);
                    DrawTextureEx(Heart2, (Vector2){15, 55}, 0.0f, 3.0f, WHITE);
                    DrawTextureEx(Heart1, (Vector2){75, 55}, 0.0f, 3.0f, WHITE);
                    DrawTextureEx(Heart2, (Vector2){75, 55}, 0.0f, 3.0f, WHITE);
                    DrawTextureEx(Heart2, (Vector2){135, 55}, 0.0f, 3.0f, WHITE);

                    DrawText("GAMEPLAY SCREEN", 50, 80, 40, BLACK);
                    DrawText("PRESS M TO JUMP TO MENU SCREEN", 50, 120, 20, BLACK);

                } break;
                default: break;
            } 
            
        EndDrawing();
    }

    //DESCARREGANDO AS TEXTURAS
    UnloadTexture(background);
    UnloadTexture(midground);
    UnloadTexture(foreground);
    UnloadTexture(scarfy);
    UnloadTexture(scarfy_2);
    UnloadTexture(Heart1);
    UnloadTexture(Heart2);

    CloseAudioDevice();
    CloseWindow();

    return 0;
}