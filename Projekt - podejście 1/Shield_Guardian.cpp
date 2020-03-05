#include "Characters.h"

Shield_Guardian::Shield_Guardian()
{
	proficiency_bonus = 3;
	tab_statistics[strength] = 18; tab_statistics_mod[strength] = set_statistic_mod(tab_statistics[strength]); tab_saving_throws[strength] = tab_statistics_mod[strength];
	tab_statistics[dexterity] = 8; tab_statistics_mod[dexterity] = set_statistic_mod(tab_statistics[dexterity]); tab_saving_throws[dexterity] = tab_statistics_mod[dexterity];
	tab_statistics[constitution] = 18; tab_statistics_mod[constitution] = set_statistic_mod(tab_statistics[constitution]); tab_saving_throws[constitution] = tab_statistics_mod[constitution];
	tab_statistics[intelligence] = 7; tab_statistics_mod[intelligence] = set_statistic_mod(tab_statistics[intelligence]); tab_saving_throws[intelligence] = tab_statistics_mod[intelligence];
	tab_statistics[wisdom] = 10; tab_statistics_mod[wisdom] = set_statistic_mod(tab_statistics[wisdom]); tab_saving_throws[wisdom] = tab_statistics_mod[wisdom];
	tab_statistics[charisma] = 3; tab_statistics_mod[charisma] = set_statistic_mod(tab_statistics[charisma]); tab_saving_throws[charisma] = tab_statistics_mod[charisma];
	main_statistic_mod_for_attack = tab_statistics_mod[strength];
	set_initiative();
	speed = 30;
	remember_original_speed();
	HP = 142;
	max_HP = HP;
	AC = 17;
	action = 1;
	bonus_action = 1;
	is_confused = false;
	is_hasted = false;
	is_devil_marked = false;
}

void Shield_Guardian::movement(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle)
{
	int choosen_hero_id;
	Vector2i bufor_co;
	choosen_hero_id = find_closest_hero(tab_characters);
	bufor_co = tab_characters[choosen_hero_id]->get_tab_co_character().back();
	bufor_co.x += movement_80;
	bufor_co.y -= movement_100;
	tab_characters[3]->set_hitbox_move_error_enemy_2x4(bufor_co);
	bufor_co.x -= movement_100;
	tab_characters[3]->set_co_character(bufor_co);
	return;
}

void Shield_Guardian::attack(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle)
{
	movement(app_window, tab_characters, what_happend_in_battle);
	if (max_HP - 10 >= HP)
		HP += 10; //regeneracja
	else
		HP = max_HP;
	int choosen_hero_id, roll;
	Postac *current_character = new Shield_Guardian;
	Roll_Dice dice;
	choosen_hero_id = find_closest_hero(tab_characters);
	what_happend_in_battle.push_back("Shield guardian atakuje " + tab_characters[choosen_hero_id]->get_name() + " poteznym uderzeniem");
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

Shield_Guardian::~Shield_Guardian()
{
}