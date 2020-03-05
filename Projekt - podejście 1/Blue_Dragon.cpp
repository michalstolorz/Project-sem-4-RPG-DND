#include "Characters.h"

Blue_Dragon::Blue_Dragon()
{
	proficiency_bonus = 5;
	tab_statistics[strength] = 25; tab_statistics_mod[strength] = set_statistic_mod(tab_statistics[strength]); tab_saving_throws[strength] = tab_statistics_mod[strength];
	tab_statistics[dexterity] = 10; tab_statistics_mod[dexterity] = set_statistic_mod(tab_statistics[dexterity]); tab_saving_throws[dexterity] = 5;
	tab_statistics[constitution] = 23; tab_statistics_mod[constitution] = set_statistic_mod(tab_statistics[constitution]); tab_saving_throws[constitution] = 11;
	tab_statistics[intelligence] = 16; tab_statistics_mod[intelligence] = set_statistic_mod(tab_statistics[intelligence]); tab_saving_throws[intelligence] = tab_statistics_mod[intelligence];
	tab_statistics[wisdom] = 15; tab_statistics_mod[wisdom] = set_statistic_mod(tab_statistics[wisdom]); tab_saving_throws[wisdom] = 7;
	tab_statistics[charisma] = 19; tab_statistics_mod[charisma] = set_statistic_mod(tab_statistics[charisma]); tab_saving_throws[charisma] = 9;
	main_statistic_mod_for_attack = tab_statistics_mod[strength];
	set_initiative();
	speed = 80;
	remember_original_speed();
	HP = 225;
	AC = 19;
	action = 1;
	bonus_action = 1;
	is_confused = false;
	is_hasted = false;
	is_devil_marked = false;
}


void Blue_Dragon::movement(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle)
{
	int choosen_hero_id;
	Vector2i bufor_co;
	choosen_hero_id = find_closest_hero(tab_characters);
	bufor_co = tab_characters[choosen_hero_id]->get_tab_co_character().back();
	bufor_co.x += movement_80;
	bufor_co.y -= movement_100;
	tab_characters[3]->set_co_character(bufor_co);
	tab_characters[3]->set_hitbox_move_error_enemy_4x4(bufor_co);
	return;
}

void Blue_Dragon::attack(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle)
{
	movement(app_window, tab_characters, what_happend_in_battle);
	int choosen_hero_id, roll;
	Postac *current_character = new Blue_Dragon;
	Roll_Dice dice;
	choosen_hero_id = find_closest_hero(tab_characters);
	what_happend_in_battle.push_back("Niebieski smok atakuje " + tab_characters[choosen_hero_id]->get_name() + " swoim poteznym ugryzieniem oraz pazurami");
	roll = dice.roll_d20();
	if (is_hit_attack(roll, tab_characters[choosen_hero_id]))
		if (is_critical_hit(roll, current_character))
			tab_characters[choosen_hero_id]->HP -= (dice.roll_d10() + dice.roll_d10() + dice.roll_d10()) * 2 + main_statistic_mod_for_attack;
		else
			tab_characters[choosen_hero_id]->HP -= dice.roll_d10() + dice.roll_d10() + dice.roll_d10() + main_statistic_mod_for_attack;
	for (int i = 0; i < 2; i++)
	{
		roll = dice.roll_d20();
		if (is_hit_attack(roll, tab_characters[choosen_hero_id]))
			if (is_critical_hit(roll, current_character))
				tab_characters[choosen_hero_id]->HP -= (dice.roll_d6() + dice.roll_d6()) * 2 + main_statistic_mod_for_attack;
			else
				tab_characters[choosen_hero_id]->HP -= dice.roll_d6() + dice.roll_d6() + main_statistic_mod_for_attack;
	}
	delete current_character;
	return;
}


Blue_Dragon::~Blue_Dragon()
{
}
