#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <windows.h>
#include <vector>
#include "Roll_Dice.h"
#include "terminal.h"

using namespace std;
using namespace sf;

class Postac
{
protected:
	string name;
	enum statistics {strength, dexterity, constitution, intelligence, wisdom, charisma};
	int tab_statistics[6];
	int tab_statistics_mod[6];
	int tab_saving_throws[6];
	int main_statistic_mod_for_attack;
	int main_statistic_mod_for_spell;
	int initiative;
	int speed;
	int speed_memory;
	int AC;
	int max_HP;
	int proficiency_bonus;
	int action;
	int bonus_action;
	int id_number;
	bool is_dead;
	bool is_confused;
	bool is_hasted;
	bool is_devil_marked;
	vector<Vector2i> tab_co_movement_marker;
	vector<Vector2i> tab_co_character;
	IntRect *hitbox_move_error_marker;
	IntRect hitbox_move_error_character;
	const int movement_100 = 100;
	const int movement_80 = 80;
public:
	Postac();
	int HP;
	int excluded_character_list[3] = { 5,5,5 };
	vector<Vector2i> get_tab_co_movement_markers();
	vector<Vector2i> get_tab_co_character();
	int get_initiative();
	int get_id_number();
	int get_max_HP();
	bool get_confusion_status();
	string get_name();
	IntRect get_hitbox_move_error_character();
	void set_character_id_number(int id);
	void set_initiative(); 
	void remember_original_speed();
	void reset_original_speed();
	void reset_actions();
	int set_statistic_mod(int statistic);
	void set_co_movement_marker(Vector2i coordinates);
	void set_co_character(Vector2i coordinates);
	void set_hitbox_move_error_marker(Vector2i coordinates);
	void set_hitbox_move_error_character(Vector2i coordinates);
	void set_hitbox_move_error_enemy_4x4(Vector2i coordinates);
	void set_hitbox_move_error_enemy_3x3(Vector2i coordinates);
	void set_hitbox_move_error_enemy_2x2(Vector2i coordinates);
	void set_hitbox_move_error_enemy_2x4(Vector2i coordinates);
	void set_confusion_true();
	void set_confusion_false();
	void activate_haste();
	void deactivate_haste();
	void activate_devil_mark();
	void deactivate_devil_mark();
	int find_closest_hero(Postac *tab_characters[4]);
	virtual void movement(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle) = 0;
	virtual void attack(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle) = 0;
	bool check_if_alive();
	void check_if_died();
	bool check_haste();
	bool check_devil_mark();
	bool check_hitbox(Postac *tab_characters[4], bool & it_is_collision);
	bool check_range(Postac *tab_characters[4]);
	bool is_critical_hit(int roll, Postac *current_character);
	bool is_hit_attack(int roll, Postac *tab_characters);
	bool is_hit_spell(int roll, Postac *tab_characters);
	bool saving_throw(statistics stat, Postac *tab_characters, int DC);
	vector<Vector2i> move_up(Vector2i bufor_wsp, Postac *tab_characters[4], bool & it_is_collision);
	vector<Vector2i> move_down(Vector2i bufor_wsp, Postac *tab_characters[4], bool & it_is_collision);
	vector<Vector2i> move_left(Vector2i bufor_wsp, Postac *tab_characters[4], bool & it_is_collision);
	vector<Vector2i> move_right(Vector2i bufor_wsp, Postac *tab_characters[4], bool & it_is_collision);
	void movement_switch(Event event, Vector2i bufor_wsp, Postac *tab_characters[4], bool &it_is_collision, int &current_location);
	~Postac();
};

#include "Characters.h"