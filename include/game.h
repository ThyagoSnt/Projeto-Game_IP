#ifndef GAME_IP
#define GAME_IP

//INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "raylib.h"
#include "gameStructs.h"
#include "draw.h"
#include "mechanics.h"

#define screenWidth  1260
#define screenHeight  800

static int	descer = 0;
static int colision = 0;

void LoadAllTexture(Player *player, Heart *life,Background *background,Plataform *plataforma, Menu *menu, SetGame *set, Fanatico *fanatico);
void UnloadAllTexture(Player *player, Heart *life,Background *background,Plataform *plataforma, Menu *menu, SetGame *set, Fanatico *fanatico);
void InitVar(Background *background,Plataform *platafoma,SetGame *set,Player *player,Menu *menu, Fanatico *fanatico, Heart *recP);
#endif
