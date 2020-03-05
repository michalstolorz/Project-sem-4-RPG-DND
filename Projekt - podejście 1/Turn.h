#pragma once
#include"Postac.h"
#include "drawing.h"
#include <vector>

class Turn
{
	vector<string> what_happend_in_battle;
	int game_over = 0;
public:
	Turn();
	void in_game_turn(Postac *tab_characters[4], vector<int> tab_initiative, RenderWindow &app_window);
	void is_game_over(RenderWindow &app_window, Postac *tab_characters[4], bool &main_condition, bool &sub_condition);
	void fill_what_happend_in_battle();
	vector<string> get_what_happend_in_battle();
	~Turn();
};