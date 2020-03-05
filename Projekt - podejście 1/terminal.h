#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class terminal
{
	Vector2i tab_co_name;
	Vector2i tab_co_HP_string;
	Vector2i tab_co_HP_number;
	Vector2i tab_co_actions1;
	Vector2i tab_co_actions2;
	Vector2i tab_co_actions3;
	Vector2i tab_co_actions1_character;
	Vector2i tab_co_actions2_character;
	Vector2i tab_co_actions3_character;
	Vector2i tab_co_what_happend_terminal1;
	Vector2i tab_co_what_happend_terminal2;
	Vector2i tab_co_what_happend_terminal3;
	Vector2i tab_co_actions1_sorceress;
	Vector2i tab_co_actions2_sorceress;
	Vector2i tab_co_actions3_sorceress;
	Vector2i tab_co_actions4_sorceress;
	Vector2i tab_co_actions5_sorceress;
	Vector2i tab_co_actions6_sorceress;
	Vector2i tab_co_actions7_sorceress;
	Vector2i tab_co_actions8_sorceress;
	Vector2i tab_co_actions1_paladin;
	Vector2i tab_co_actions2_paladin;
	Vector2i tab_co_actions3_paladin;
	Vector2i tab_co_actions4_paladin;
	string HP_string = "HP:";
public:
	terminal();
	void draw_string(RenderWindow &app_window, string informations, Vector2i position, int size);
	void draw_action_menu(RenderWindow &app_window);
	void draw_action_menu_paladin(RenderWindow &app_window);
	void draw_heal_string(RenderWindow &app_window);
	void draw_paladin_heal_person(RenderWindow &app_window, string who_is_healed, int id_number);
	void draw_action_menu_warrior(RenderWindow &app_window);
	void draw_action_menu_monk(RenderWindow &app_window);
	void draw_action_menu_sorceress(RenderWindow &app_window);
	void draw_sorceress_spells(RenderWindow &app_window, string first_spell, string second_spell);
	void draw_haste_characters(RenderWindow &app_window, string tab_names[2]);
	void draw_what_happend_terminal(RenderWindow &app_window, vector<string> what_happend);
	void draw_you_win(RenderWindow & app_window);
	void draw_you_lose(RenderWindow & app_window);
	void set_co();
	Vector2i get_tab_co_name();
	Vector2i get_tab_co_HP_string();
	Vector2i get_tab_co_HP_number();
	Vector2i get_tab_co_action1();
	Vector2i get_tab_co_action2();
	Vector2i get_tab_co_action3();
	string get_HP_string();
	~terminal();
};

