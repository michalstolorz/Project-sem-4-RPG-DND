#include "Characters.h"

Devil::Devil()
{
	proficiency_bonus = 4;
	tab_statistics[strength] = 22; tab_statistics_mod[strength] = set_statistic_mod(tab_statistics[strength]); tab_saving_throws[strength] = 10;
	tab_statistics[dexterity] = 17; tab_statistics_mod[dexterity] = set_statistic_mod(tab_statistics[dexterity]); tab_saving_throws[dexterity] = 7;
	tab_statistics[constitution] = 21; tab_statistics_mod[constitution] = set_statistic_mod(tab_statistics[constitution]); tab_saving_throws[constitution] = tab_statistics_mod[constitution];
	tab_statistics[intelligence] = 12; tab_statistics_mod[intelligence] = set_statistic_mod(tab_statistics[intelligence]); tab_saving_throws[intelligence] = tab_statistics_mod[intelligence];
	tab_statistics[wisdom] = 16; tab_statistics_mod[wisdom] = set_statistic_mod(tab_statistics[wisdom]); tab_saving_throws[wisdom] = 7;
	tab_statistics[charisma] = 17; tab_statistics_mod[charisma] = set_statistic_mod(tab_statistics[charisma]); tab_saving_throws[charisma] = 7;
	main_statistic_mod_for_attack = tab_statistics_mod[strength];
	set_initiative();
	speed = 60;
	remember_original_speed();
	HP = 178;
	AC = 18;
	spell_save_DC = 17;
	action = 1;
	bonus_action = 1;
	is_confused = false;
	is_hasted = false;
	is_devil_marked = false;
}

void Devil::movement(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle)
{
	int choosen_hero_id;
	Vector2i bufor_co;
	choosen_hero_id = find_closest_hero(tab_characters);
	bufor_co = tab_characters[choosen_hero_id]->get_tab_co_character().back();
	bufor_co.x += movement_80;
	tab_characters[3]->set_co_character(bufor_co);
	tab_characters[3]->set_hitbox_move_error_enemy_2x2(bufor_co);
	return;
}

void Devil::attack(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle)
{
	movement(app_window, tab_characters, what_happend_in_battle);
	int choosen_hero_id, roll;
	Postac *current_character = new Devil;
	Roll_Dice dice;
	choosen_hero_id = find_closest_hero(tab_characters);
	what_happend_in_battle.push_back("Diabel atakuje " + tab_characters[choosen_hero_id]->get_name() + " swoimi widlami oraz ogonem");
	for (int i = 0; i < 2; i++)
	{
		roll = dice.roll_d20();
		if (is_hit_attack(roll, tab_characters[choosen_hero_id]))
			if (is_critical_hit(roll, current_character))
				tab_characters[choosen_hero_id]->HP -= (dice.roll_d8() + dice.roll_d8()) * 2 + main_statistic_mod_for_attack;
			else
				tab_characters[choosen_hero_id]->HP -= dice.roll_d8() + dice.roll_d8() + main_statistic_mod_for_attack;
	}
	roll = dice.roll_d20();
	if (is_hit_attack(roll, tab_characters[choosen_hero_id]))
	{
		if (is_critical_hit(roll, current_character))
			tab_characters[choosen_hero_id]->HP -= (dice.roll_d8()) * 2 + main_statistic_mod_for_attack;
		else
			tab_characters[choosen_hero_id]->HP -= dice.roll_d8() + main_statistic_mod_for_attack;
		if (!tab_characters[choosen_hero_id]->saving_throw(constitution, tab_characters[choosen_hero_id], spell_save_DC))
		{
			tab_characters[choosen_hero_id]->activate_devil_mark();
			what_happend_in_battle.push_back("Diabel naznaczyl " + tab_characters[choosen_hero_id]->get_name() + " piekielnym znamieniem");
		}
		else
			what_happend_in_battle.push_back(tab_characters[choosen_hero_id]->get_name() + " oparl sie naznaczeniu przez piekielny symbol diabla");
	}
	delete current_character;
	return;
}

Devil::~Devil()
{

}