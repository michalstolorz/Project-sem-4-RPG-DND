#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include "Postac.h"
#include "Characters.h"


using namespace std;
using namespace sf;

class drawing
{
	//terrain
	Texture texture_terrain;
	Sprite sprite_terrain;
	Texture texture_terrain_blur;
	Sprite sprite_terrain_blur;
	//buttons
	Texture texture_terminal;
	//Sprite sprite_terminal;
	Texture texture_choose_the_party;
	Sprite sprite_choose_the_party;
	Texture texture_choose_an_enemy;
	Sprite sprite_choose_an_enemy;
	Texture texture_ready_for_battle;
	Sprite sprite_ready_for_battle;
	Texture texture_button1;
	Sprite sprite_button1;
	Texture texture_button2;
	Sprite sprite_button2;
	Texture texture_button3;
	Sprite sprite_button3;
	Texture texture_button4;
	Sprite sprite_button4;
	Texture texture_button5;
	Sprite sprite_button5;
	//characters and enemys
	Texture texture_blue_dragon;
	Sprite sprite_blue_dragon;
	Texture texture_fire_gigant;
	Sprite sprite_fire_gigant;
	Texture texture_devil;
	Sprite sprite_devil;
	Texture texture_shield_guardian;
	Sprite sprite_shield_guardian;
	Texture texture_earth_elemental;
	Sprite sprite_earth_elemental;
	//
	Texture texture_ranger;
	Sprite sprite_ranger;
	Texture texture_sorceress;
	Sprite sprite_sorceress;
	Texture texture_monk;
	Sprite sprite_monk;
	Texture texture_paladin;
	Sprite sprite_paladin;
	Texture texture_warrior;
	Sprite sprite_warrior;
	//others
	Texture texture_movement_marker;
	Sprite sprite_movement_marker;
	Texture texture_hitbox_move_error;
	Sprite sprite_hitbox_move_error;
	Texture texture_your_choice;
	Sprite sprite_your_choice;
public:
	drawing();
	void draw_sorceress(RenderWindow &app_window, Vector2i tab_co_sorceress);
	void draw_ranger(RenderWindow &app_window, Vector2i tab_co_ranger);
	void draw_monk(RenderWindow &app_window, Vector2i tab_co_monk);
	void draw_paladin(RenderWindow &app_window, Vector2i tab_co_paladin);
	void draw_warrior(RenderWindow &app_window, Vector2i tab_co_warrior);
	//
	void draw_blue_dragon(RenderWindow &app_window,Vector2i tab_co_blue_dragon);
	void draw_fire_gigant(RenderWindow &app_window, Vector2i tab_co_fire_gigant);
	void draw_devil(RenderWindow &app_window, Vector2i tab_co_devil);
	void draw_shield_guardian(RenderWindow &app_window, Vector2i tab_co_shield_guardian);
	void draw_earth_elemental(RenderWindow &app_window, Vector2i tab_co_earth_elemental);
	//
	void draw_movement_marker(RenderWindow &app_window, Vector2i tab_co_movement_marker);
	void draw_hitbox_move_error(RenderWindow &app_window, Vector2i tab_co_movement_marker_error);
	void draw_your_choice(RenderWindow &app_window);
	//
	void draw_terminal(RenderWindow & app_window);
	void draw_terrain(RenderWindow &app_window);
	void draw_terrain_blur(RenderWindow &app_window);
	//
	void draw_choose_the_party(RenderWindow &app_window);
	void draw_choose_an_enemy(RenderWindow &app_window);
	void draw_ready_for_battle(RenderWindow &app_window);
	void draw_button1(RenderWindow &app_window, Vector2i tab_co_button);
	void draw_button2(RenderWindow &app_window, Vector2i tab_co_button);
	void draw_button3(RenderWindow &app_window, Vector2i tab_co_button);
	void draw_button4(RenderWindow &app_window, Vector2i tab_co_button);
	void draw_button5(RenderWindow &app_window, Vector2i tab_co_button);
	//
	void load_textures();
	void load_sprites();
	void rerender(RenderWindow &app_window, Postac* tab_characters[4]);
	void true_rerender(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle, drawing draw_object, int id_number);
	~drawing();
};
