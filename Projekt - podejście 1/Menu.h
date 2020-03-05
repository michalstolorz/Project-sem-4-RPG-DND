#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Characters.h"
#include <windows.h> 

using namespace std;
using namespace sf;

class Menu
{
public:
	Menu();
	void show_menu(RenderWindow &app_window, Postac *tab_characters[4]);
	void enemies_screen(RenderWindow &app_window, drawing draw_object, Postac *tab_characters[4], vector<Vector2i> tab_co_enemies, vector<Vector2i> tab_co_num_buttons_enemies, vector<int> tab_choices, vector<Vector2i> tab_co_choice_num_buttons_enemies);
	void characters_screen(RenderWindow &app_window, drawing draw_object, Postac *tab_characters[4], vector<Vector2i> tab_co_characters, vector<Vector2i> tab_co_num_buttons_characters, vector<int> tab_choices, vector<Vector2i> tab_co_choice_num_buttons_characters);
	~Menu();
};
