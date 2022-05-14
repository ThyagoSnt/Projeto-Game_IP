#ifndef DRAW_H
#define DRAW_H

	void DrawEnemy(Fanatico fanatico,SetGame set);
	void DrawEnvironment(Background background, SetGame set);
	void DrawInteractive(Plataform plataform,Heart life, SetGame set);
	void DrawMyText(SetGame set);
	void DrawPlayer(Player player, SetGame set,Heart life);
	void DrawGamePlay(Background background,SetGame set,Plataform plataforma ,Player player, Heart life, Fanatico fanatico);
	void DrawMenu(Menu menu);
	void DrawTitle(Menu menu);
	void DrawInfo(Menu menu);
	void DrawOptions(Menu menu);
	void DrawSave(Menu menu);
	void DrawExit(Menu menu);
	void DrawGameWin();
	void DrawGameOver();
	
#endif
