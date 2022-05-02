#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "raylib.h"

typedef struct{
    char name[20];
    int vida;
    int canJump;
} Player;

int main(void){
    const int larguraTela = 1260;
    const int alturaTela = 800;

    InitWindow(larguraTela, alturaTela, "Projeto_versao_0.1");
    InitAudioDevice();

    //GameScreen currentScreen = LOGO;

    //CARREGANDO ASS TEXTURAS
    Texture2D scarfy = LoadTexture("assets/personagem/scarfy.png");
    Texture2D scarfy_2 = LoadTexture("assets/personagem/scarfy_2.png");
    Texture2D Heart1 = LoadTexture("assets/gui/Heart1.png");
    Texture2D Heart2 = LoadTexture("assets/gui/Heart2.png");
    Texture2D background = LoadTexture("assets/background/background_layer_1.png");
    Texture2D midground = LoadTexture("assets/background/background_layer_2.png");
    Texture2D foreground = LoadTexture("assets/background/background_layer_3.png");

    Vector2 characterPosition = {240, 628};

    float scrollingBack = 0.0f;
    float scrollingMid = 0.0f;
    float scrollingFore = 0.0f;

    float time = 0.0f;
    int currentFrame = 0;
    int direcao = 0; 
    int characterRadius = 125;

    Player player;
    player.canJump = 0;
    player.vida = 3;

    SetTargetFPS(450);
    while (!WindowShouldClose()){

        /* switch(currentScreen){
            case LOGO:
            {
                framesCounter++;
                if (framesCounter > 120){
                    currentScreen = TITLE;
                }
            } break;
            case TITLE:
            {
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)){
                    currentScreen = GAMEPLAY;
                }
            } break;
            case GAMEPLAY:
            {
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)){
                    currentScreen = ENDING;
                }
            } break;
            case ENDING:
            {
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)){
                    currentScreen = TITLE;
                }
            } break;

            default:
                break;
        } */

        time += GetFrameTime();
        if(time >= 0.1f){
            time = 0.0f;
            currentFrame += 1;
        }

        if(IsKeyDown(KEY_D) && (characterPosition.x+characterRadius < larguraTela)){
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

        if(IsKeyDown(KEY_SPACE) && (player.canJump == 0)) player.canJump = 1;
        if((player.canJump == 1) && (characterPosition.y != 350)) characterPosition.y -= 2;
        if(characterPosition.y == 350) player.canJump = 2;
        if((player.canJump == 2) && (characterPosition.y != 628)) characterPosition.y += 2;
        if(characterPosition.y == 628) player.canJump = 0;

        if (scrollingBack <= -background.width*4){scrollingBack = 0;}
        if (scrollingMid <= -midground.width*4){scrollingMid = 0;}
        if (scrollingFore <= -foreground.width*4){scrollingFore = 0;}

        BeginDrawing();

            ClearBackground(BLACK);

            DrawTextureEx(background, (Vector2){ scrollingBack, 40 }, 0.0f, 4.0f, WHITE);
            DrawTextureEx(background, (Vector2){ background.width*4 + scrollingBack, 40 }, 0.0f, 4.0f, WHITE);

            DrawTextureEx(midground, (Vector2){ scrollingMid, 40 }, 0.0f, 4.0f, WHITE);
            DrawTextureEx(midground, (Vector2){ midground.width*4 + scrollingMid, 40 }, 0.0f, 4.0f, WHITE);

            DrawTextureEx(foreground, (Vector2){ scrollingFore, 40 }, 0.0f, 4.0f, WHITE);
            DrawTextureEx(foreground, (Vector2){ foreground.width*4 + scrollingFore, 40 }, 0.0f, 4.0f, WHITE);

            if(direcao == 1 || direcao == 0)DrawTextureRec(scarfy, (Rectangle){(scarfy.width/6)*(currentFrame % 6), 0, scarfy.width/6,scarfy.height}, characterPosition, WHITE);
            if(direcao == -1)DrawTextureRec(scarfy_2, (Rectangle){(scarfy_2.width/6)*(currentFrame % 6), 0, scarfy_2.width/6,scarfy_2.height}, characterPosition, WHITE);

            DrawTextureEx(Heart1, (Vector2){15, 55}, 0.0f, 3.0f, WHITE);
            DrawTextureEx(Heart2, (Vector2){15, 55}, 0.0f, 3.0f, WHITE);
            DrawTextureEx(Heart1, (Vector2){75, 55}, 0.0f, 3.0f, WHITE);
            DrawTextureEx(Heart2, (Vector2){75, 55}, 0.0f, 3.0f, WHITE);
            DrawTextureEx(Heart2, (Vector2){135, 55}, 0.0f, 3.0f, WHITE);
            
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