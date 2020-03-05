#include "Characters.h"

Fire_Gigant::Fire_Gigant()
{
	proficiency_bonus = 4;
	tab_statistics[strength] = 25; tab_statistics_mod[strength] = set_statistic_mod(tab_statistics[strength]); tab_saving_throws[strength] = tab_statistics_mod[strength];
	tab_statistics[dexterity] = 9; tab_statistics_mod[dexterity] = set_statistic_mod(tab_statistics[dexterity]); tab_saving_throws[dexterity] = 3;
	tab_statistics[constitution] = 23; tab_statistics_mod[constitution] = set_statistic_mod(tab_statistics[constitution]); tab_saving_throws[constitution] = 10;
	tab_statistics[intelligence] = 10; tab_statistics_mod[intelligence] = set_statistic_mod(tab_statistics[intelligence]); tab_saving_throws[intelligence] = tab_statistics_mod[intelligence];
	tab_statistics[wisdom] = 14; tab_statistics_mod[wisdom] = set_statistic_mod(tab_statistics[wisdom]); tab_saving_throws[wisdom] = tab_statistics_mod[wisdom];
	tab_statistics[charisma] = 13; tab_statistics_mod[charisma] = set_statistic_mod(tab_statistics[charisma]); tab_saving_throws[charisma] = 5;
	main_statistic_mod_for_attack = tab_statistics_mod[strength];
	set_initiative();
	speed = 30;
	remember_original_speed();
	HP = 162;
	AC = 18;
	action = 1;
	bonus_action = 1;
	is_confused = false;
	is_hasted = false;
	is_devil_marked = false;
}

void Fire_Gigant::movement(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle)
{
	int choosen_hero_id;
	Vector2i bufor_co;
	choosen_hero_id = find_closest_hero(tab_characters);
	bufor_co = tab_characters[choosen_hero_id]->get_tab_co_character().back();
	bufor_co.x += movement_80;
	bufor_co.y -= movement_100;
	tab_characters[3]->set_co_character(bufor_co);
	tab_characters[3]->set_hitbox_move_error_enemy_3x3(bufor_co);
	return;
}

void Fire_Gigant::attack(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle)
{
	int choosen_hero_id, roll, dmg = 0;
	Postac *current_character = new Earth_Elemental;
	Roll_Dice dice;
	choosen_hero_id = find_closest_hero(tab_characters);
	Vector2i bufor_co = tab_characters[choosen_hero_id]->get_tab_co_character().back();

	if (tab_co_character.back().x - bufor_co.x >= 300)
	{
		what_happend_in_battle.push_back("Ognisty olbrzym rzuca skala w " + tab_characters[choosen_hero_id]->get_name());
		roll = dice.roll_d20();
		if (is_hit_attack(roll, tab_characters[choosen_hero_id]))
			if (is_critical_hit(roll, current_character))
			{
				for (int i = 0; i < 4; i++)
					dmg += dice.roll_d10();
				tab_characters[choosen_hero_id]->HP -= dmg * 2 + main_statistic_mod_for_attack;
			}
			else
			{
				for (int i = 0; i < 4; i++)
					dmg += dice.roll_d10();
				tab_characters[choosen_hero_id]->HP -= dmg + main_statistic_mod_for_attack;
			}
		delete current_character;
		return;
	}
	movement(app_window, tab_characters, what_happend_in_battle);
	what_happend_in_battle.push_back("Ognisty olbrzym atakuje " + tab_characters[choosen_hero_id]->get_name() + " swoim mieczem");
	for (int i = 0; i < 2; i++)
	{
		roll = dice.roll_d20();
		if (is_hit_attack(roll, tab_characters[choosen_hero_id]))
			if (is_critical_hit(roll, current_character))
			{
				for (int i = 0; i < 6; i++)
					dmg += dice.roll_d6();
				tab_characters[choosen_hero_id]->HP -= dmg * 2 + main_statistic_mod_for_attack;
			}
			else
			{
				for (int i = 0; i < 6; i++)
					dmg += dice.roll_d6();
				tab_characters[choosen_hero_id]->HP -= dmg + main_statistic_mod_for_attack;
			}
		dmg = 0;
	}
	delete current_character;
	return;
}

Fire_Gigant::~Fire_Gigant()
{

}