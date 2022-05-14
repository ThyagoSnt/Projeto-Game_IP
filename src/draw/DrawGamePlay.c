#include "../../include/game.h"

void DrawGamePlay(Background background,SetGame set,Plataform plataforma ,Player player, Heart life, Fanatico fanatico){
	DrawEnvironment(background,set);
	DrawInteractive(plataforma,life,set);
	DrawPlayer(player,set,life);
	DrawEnemy(fanatico,set);
	DrawMyText(set);
}