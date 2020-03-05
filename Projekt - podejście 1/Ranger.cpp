#include "Characters.h"



Ranger::Ranger()
{
	name = "Ranger";
	proficiency_bonus = 3;
	tab_statistics[strength] = 10; tab_statistics_mod[strength] = set_statistic_mod(tab_statistics[strength]); tab_saving_throws[strength] = tab_statistics_mod[strength] + proficiency_bonus;
	tab_statistics[dexterity] = 20; tab_statistics_mod[dexterity] = set_statistic_mod(tab_statistics[dexterity]); tab_saving_throws[dexterity] = tab_statistics_mod[dexterity] + proficiency_bonus;
	tab_statistics[constitution] = 14; tab_statistics_mod[constitution] = set_statistic_mod(tab_statistics[constitution]); tab_saving_throws[constitution] = tab_statistics_mod[constitution];
	tab_statistics[intelligence] = 10; tab_statistics_mod[intelligence] = set_statistic_mod(tab_statistics[intelligence]); tab_saving_throws[intelligence] = tab_statistics_mod[intelligence];
	tab_statistics[wisdom] = 12; tab_statistics_mod[wisdom] = set_statistic_mod(tab_statistics[wisdom]); tab_saving_throws[wisdom] = tab_statistics_mod[wisdom];
	tab_statistics[charisma] = 10; tab_statistics_mod[charisma] = set_statistic_mod(tab_statistics[charisma]); tab_saving_throws[charisma] = tab_statistics_mod[charisma];
	main_statistic_mod_for_attack = tab_statistics_mod[dexterity];
	set_initiative();
	speed = 30;
	remember_original_speed();
	HP = 55;
	max_HP = HP;
	AC = 16;
	action = 1;
	bonus_action = 1;
	is_dead = false;
	is_hasted = false;
	is_devil_marked = false;
}

void Ranger::movement(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle)
{
	drawing draw_object;
	terminal term;
	try
	{
		draw_object.load_textures();
	}
	catch (int)
	{
		cout << "Zle wczytane tekstury, wychodzenie z programu" << endl;
		system("pause");
		exit(0);
	}
	draw_object.load_sprites();
	bool movement_condition = true;
	bool it_is_collision = false;
	Event event;
	Vector2i bufor_wsp;
	check_hitbox(tab_characters, it_is_collision);
	while (movement_condition)
	{
		draw_object.true_rerender(app_window, tab_characters, what_happend_in_battle, draw_object, id_number);
		if (it_is_collision)
			draw_object.draw_hitbox_move_error(app_window, tab_co_movement_marker.back());
		else
			draw_object.draw_movement_marker(app_window, tab_co_movement_marker.back());
		while (app_window.pollEvent(event))
			if (event.type == Event::KeyPressed)
				movement_switch(event, bufor_wsp, tab_characters, it_is_collision, current_location);
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			movement_condition = false;
			tab_co_movement_marker.clear();
			bufor_wsp.x = tab_co_character.back().x + 80;
			bufor_wsp.y = tab_co_character.back().y;
			tab_co_movement_marker.push_back(bufor_wsp);
			current_location = 1;
		}
		if (speed)
			if (!it_is_collision)
				if (Keyboard::isKeyPressed(Keyboard::Enter))
				{
					movement_condition = false;
					tab_co_character.back() = tab_co_movement_marker.back();
					set_hitbox_move_error_character(tab_co_character.back());
					tab_co_character.back().x += 20;
					tab_co_movement_marker.clear();
					bufor_wsp.x = tab_co_character.back().x + 80;
					bufor_wsp.y = tab_co_character.back().y;
					tab_co_movement_marker.push_back(bufor_wsp);
					current_location = 1;
					speed -= 5;
				}
		app_window.display();
	}
	return;
}

void Ranger::attack(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle)
{
	if (!action)
	{
		what_happend_in_battle.push_back("Akcja zostala juz wykonana");
		return;
	}
	Postac *current_character = new Ranger;
	Roll_Dice dice;
	string what_happend = "";
	int roll;
	bool collossus_slayer = true;
	for (int i = 0; i < 2; i++)
	{
		roll = dice.roll_d20();
		if (is_hit_attack(roll + 2, tab_characters[3])) // +2 z fighting style -> archery
		{
			if (is_critical_hit(roll, current_character))
			{
				tab_characters[3]->HP -= dice.roll_d8() * 2 + main_statistic_mod_for_attack;
				if (collossus_slayer)
				{
					tab_characters[3]->HP -= dice.roll_d8();
					collossus_slayer = false;
				}
			}
			else
			{
				tab_characters[3]->HP -= dice.roll_d8() + main_statistic_mod_for_attack;
				if (collossus_slayer)
				{
					tab_characters[3]->HP -= dice.roll_d8();
					collossus_slayer = false;
				}
			}
			what_happend += "Trafienie ";
		}
		else
			what_happend += "Nie trafiono ";
	}
	action--;
	what_happend_in_battle.push_back(what_happend);
	delete current_character;
}


Ranger::~Ranger()
{
}
