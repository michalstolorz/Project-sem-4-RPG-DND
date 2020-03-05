#include "Characters.h"

Monk::Monk()
{ 
	name = "Monk";
	proficiency_bonus = 3;
	tab_statistics[strength] = 10; tab_statistics_mod[strength] = set_statistic_mod(tab_statistics[strength]); tab_saving_throws[strength] = tab_statistics_mod[strength] + proficiency_bonus;
	tab_statistics[dexterity] = 18; tab_statistics_mod[dexterity] = set_statistic_mod(tab_statistics[dexterity]); tab_saving_throws[dexterity] = tab_statistics_mod[dexterity] + proficiency_bonus;
	tab_statistics[constitution] = 16; tab_statistics_mod[constitution] = set_statistic_mod(tab_statistics[constitution]); tab_saving_throws[constitution] = tab_statistics_mod[constitution];
	tab_statistics[intelligence] = 10; tab_statistics_mod[intelligence] = set_statistic_mod(tab_statistics[intelligence]); tab_saving_throws[intelligence] = tab_statistics_mod[intelligence];
	tab_statistics[wisdom] = 16; tab_statistics_mod[wisdom] = set_statistic_mod(tab_statistics[wisdom]); tab_saving_throws[wisdom] = tab_statistics_mod[wisdom];
	tab_statistics[charisma] = 10; tab_statistics_mod[charisma] = set_statistic_mod(tab_statistics[charisma]); tab_saving_throws[charisma] = tab_statistics_mod[charisma];
	main_statistic_mod_for_attack = tab_statistics_mod[dexterity];
	set_initiative();
	speed = 40;
	remember_original_speed();
	HP = 60;
	max_HP = HP;
	AC = 10 + tab_statistics_mod[dexterity] + tab_statistics_mod[wisdom];
	action = 1;
	bonus_action = 1;
	ki = 8;
	wholeness_body = 1;
	is_dead = false;
	is_hasted = false;
	is_devil_marked = false;
}

void Monk::movement(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle)
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

void Monk::attack(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle)
{
	bool forward_condition = true;
	Event event;
	int clear_condition = 1;
	vector<Event> events;
	string what_happend = "";
	terminal term;
	if (clear_condition)
	{
		while (app_window.pollEvent(event))
			events.push_back(event);
		events.clear();
		clear_condition = 0;
	}
	term.draw_action_menu_monk(app_window);
	app_window.display();
	while (forward_condition)
	{
		while (app_window.pollEvent(event))
		{
			if (event.type == Event::KeyPressed)
			{
				if (Keyboard::isKeyPressed(Keyboard::Num1)) //atak
				{
					if (!action)
					{
						what_happend_in_battle.push_back("Akcja zostala juz wykonana");
						return;
					}
					Postac *current_character = new Monk;
					Roll_Dice dice;
					int roll;
					if (check_range(tab_characters))
					{
						for (int i = 0; i < 2; i++)
						{
							roll = dice.roll_d20();
							if (is_hit_attack(roll, tab_characters[3]))
							{
								if (is_critical_hit(roll, current_character))
									tab_characters[3]->HP -= dice.roll_d6() * 2 + main_statistic_mod_for_attack;
								else
									tab_characters[3]->HP -= dice.roll_d6() + main_statistic_mod_for_attack;
								what_happend += "Trafienie ";
							}
							else
								what_happend += "Nie trafiono ";
						}
						what_happend_in_battle.push_back(what_happend);
						action--;
					}
					else
						what_happend_in_battle.push_back("Przeciwnik poza zasiegiem");
					delete current_character;
					forward_condition = false;
				}
				if (Keyboard::isKeyPressed(Keyboard::Num2)) //flurry of blows
				{
					if (!bonus_action)
					{
						what_happend_in_battle.push_back("Bonusowa akcja zostala juz wykonana");
						return;
					}
					if (!ki)
					{
						what_happend_in_battle.push_back("Cale ki zostalo juz zuzyte");
						return;
					}
					Postac *current_character = new Monk;
					Roll_Dice dice;
					int roll;
					if (check_range(tab_characters))
					{
						for (int i = 0; i < 2; i++)
						{
							roll = dice.roll_d20();
							if (is_hit_attack(roll, tab_characters[3]))
							{
								if (is_critical_hit(roll, current_character))
									tab_characters[3]->HP -= dice.roll_d6() * 2 + main_statistic_mod_for_attack;
								else
									tab_characters[3]->HP -= dice.roll_d6() + main_statistic_mod_for_attack;
								what_happend += "Trafienie ";
							}
							else
								what_happend += "Nie trafiono ";
						}
						what_happend_in_battle.push_back(what_happend);
						ki--;
						bonus_action--;
					}
					else
						what_happend_in_battle.push_back("Przeciwnik poza zasiegiem");
					delete current_character;
					forward_condition = false;
				}
				if (Keyboard::isKeyPressed(Keyboard::Num3)) //wholenes body
				{
					if (!action)
					{
						what_happend_in_battle.push_back("Akcja zostala juz wykonana");
						return;
					}
					if (!wholeness_body)
					{
						what_happend_in_battle.push_back("Leczenie zostalo juz wykonane");
						return;
					}
					if (24 + HP > max_HP) //24 = 3 * 8 -> trzykrotnoœæ poziomu
						HP = max_HP;
					else
						HP += 24;
					what_happend_in_battle.push_back("Przywrociles swoje zdrowie do rownowagi");
					action--;
					wholeness_body--;
					forward_condition = false;
				}
			}
		}
	}
	return;
}



Monk::~Monk()
{
}
